#line 1 "d:\\项目\\开源项目\\wifi_clock\\wifi_clock\\wifi_clock.ino"
#include <ESP8266_BiliBili.h>
#include <FansInfo.h>
#include <UpInfo.h>
#include <VideoInfo.h>

#include <FansInfo.h>
#include <UpInfo.h>
#include <VideoInfo.h>

#include <ESP8266_Seniverse.h>
#include <Forecast.h>
#include <LifeInfo.h>
#include <WeatherNow.h>

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#include <ArduinoJson.h>
#include <String>


#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

#include <DNSServer.h>//密码直连将其三个库注释
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

#include <time.h>
#include <sys/time.h>
#include <coredecls.h>

#include "WeatherIcon.h"
#include "nongli.h"//农历获取相关给库
#include "gushi.h"//获取古诗相关的库



//时间显示相关定义
#define TZ              8      // 中国时区为8
#define DST_MN          0      // 默认为0
#define TZ_MN           ((TZ)*60)   //时间换算
#define TZ_SEC          ((TZ)*3600)
#define DST_SEC         ((DST_MN)*60)
const int SDA_PIN = 0;  //引脚连接,使用的是硬件IIC
const int SDC_PIN = 2;  //

time_t now; //实例化时间



//刷新更新，使用mills函数实现，如果用delay会造成显示秒的时候卡住不动
const int UPDATE_INTERVAL_SECS = 5 * 60; // 5分钟更新一次天气
const int UPDATE_NONGLI_SECS = 60 * 60 * 2; //农历一天更新一次
const int UPDATE_GUSHI_SECS = 20 * 60; //古诗20分钟更新一次
const int UPDATE_UI_SECS = 5; //UI5秒钟更新一次
const int UPDATE_Fans_SECS = 2 * 60; //粉丝两分钟更新一次


int count = 0; //计数变量
bool first = true;  //首次更新标志
long timeSinceLastWeatherUpdate = 0;    //上次更新后的时间
long timeSinceLastNongliUpdate = 0;   //上次天气更新后的时间
long timeSinceLastGushiUpdate = 0;   //上次天气更新后的时间
long timeSinceLastUiUpdate = 0;   //上次UI更新后的时间
long timeSinceLastFansUpdate = 0; //上次粉丝更新后的时间

const String WDAY_NAMES[] = {"星期天", "星期一", "星期二", "星期三", "星期四", "星期五", "星期六"};  //星期
const String MONTH_NAMES[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};  //月份

uint8_t* my_oled_buf1;
uint8_t* my_oled_buf2;
uint8_t* my_oled_buf3;
uint8_t* my_oled_buf4;//定义4个显示缓存空间

uint8_t my_oled_buf1_arry[1024];
uint8_t my_oled_buf2_arry[1024];
uint8_t my_oled_buf3_arry[1024];
uint8_t my_oled_buf4_arry[1024];//定义4个数组用来存放过度动画的画面


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ 2, /* data=*/ 0);  //配置构造函数，使用硬件IIC

const char* ssid     = "BOHEMIAN";       // 连接WiFi名
// 请将您需要连接的WiFi名填入引号中
const char* password = "12345678";          // 连接WiFi密码
// 请将您需要连接的WiFi密码填入引号中

//心知天气
String reqUserKey = "ShtRP8VhE_gxAZgVd";   // 私钥
String reqLocation = "chongqing";            // 城市
String reqUnit = "c";                      // 摄氏/华氏
//天行数据密匙，我找了半天发现这个网站的API接口比较全，但是返回的json数据有点奇怪，需要处理一下，不过我已经处理好了，网址https://www.tianapi.com/
String tianxingkey = "================";
//逼站账号
FansInfo fansInfo("============");

//对象的建立
WeatherNow weatherNow;  // 建立WeatherNow对象用于获取心知当前天气信息
Forecast forecast; // 建立Forecast对象用于获取心知天气预报信息
Nongli nongli;//建立一个nongli对象
Gushi gushi;//建立一个gushi对象


//函数的声明
void webconnect();//web配网
void connectWiFi();//直连wifi
void runProgress();//几个界面的运行切换
void updateForTime();//从网络获取各种信息的更新
void drawPogress(int16_t degree, int16_t x, int16_t y, const char* lable);//绘制进度条
void drawDateTime(); //显示时间
void drawGushi();//显示古诗
void drawForcastWeather();//显示未来三天的天气预报
void drawCurrentWeather(); //显示当前天气
void StartClock();//开机更新
void littleWeatherIconShow( int16_t day, int16_t x, int16_t y); //显示小的天气图标
void littleWeatherTempShow(int16_t day, int16_t x, int16_t y); //显示天气预报温度
void drawPagePoint(int16_t x, int16_t y, const char* icon); //绘制底栏的小圆点
void drawEyebow(int16_t x, int16_t y, int page, const char*someData); //绘制底栏
void Move_aPage(uint8_t  page_1[1024], uint8_t page_2[1024]);//动画过渡效果
void my_oled_clear(uint8_t* oled_gram);//清空缓存区（清空数组）



#line 127 "d:\\项目\\开源项目\\wifi_clock\\wifi_clock\\wifi_clock.ino"
void setup(void);
#line 152 "d:\\项目\\开源项目\\wifi_clock\\wifi_clock\\wifi_clock.ino"
void loop(void);
#line 127 "d:\\项目\\开源项目\\wifi_clock\\wifi_clock\\wifi_clock.ino"
void setup(void)
{
  Serial.begin(9600);
  Serial.println("");
  u8g2.begin();
  u8g2.enableUTF8Print();//开启UTF-8字符显示，即开启中文的显示

  //WiFiManager wifiManager; //第一次web配网的时候如果ESP8266还保存着上次的wifi信息可能需要先格式化，如果直接编译下载后不能发现你的热点就需要把你原来的信息清楚一下
  //wifiManager.resetSettings();//格式化wifi信息

  //webconnect();//配网

  connectWiFi();//密码手动联网
  // 配置心知天气请求信息
  weatherNow.config(reqUserKey, reqLocation, reqUnit);//初始化天气
  forecast.config(reqUserKey, reqLocation, reqUnit);//初始化天气
  //天行数据的请求
  nongli.config(tianxingkey);//初始化农历
  gushi.config(tianxingkey);//初始化古诗
  //时间服务器的请求
  configTime(TZ_SEC, DST_SEC, "ntp.ntsc.ac.cn", "ntp1.aliyun.com");//获取当前时间

  delay(200);
}

void loop(void)
{
  updateForTime();//开机初始化和更新时间
  runProgress();//运行代码
  delay(200);
}



//Web配网
void webconnect() {
  u8g2.clearBuffer();//清空缓存
  u8g2.drawXBMP(32, 0, 64, 64, tiaopi);//绘制连接网络的动画
  u8g2.sendBuffer();//显示
  //delay(1000);
  WiFiManager wifiManager;  //实例化WiFiManager
  if (!wifiManager.autoConnect("========")) {  //AP模式，用手机或者电脑web配网时你的esp8266的热点
    u8g2.setCursor(34, 60);
    u8g2.println("连接失败");
    //重新设置并再试一次，或者让它进入深度睡眠状态，这样断网之后它也会再有网的时候再次连接
    ESP.restart();
    delay(1000);
  }

  yield();
}

// 密码连接WiFi,由于我使用的是web配网，所以这部分的UI没设计
void connectWiFi() {
  WiFi.begin(ssid, password);                  // 启动网络连接
  Serial.print("Connecting to ");              // 串口监视器输出网络连接信息
  Serial.print(ssid); Serial.println(" ...");  // 告知用户NodeMCU正在尝试WiFi连接

  int i = 0;                                   // 这一段程序语句用于检查WiFi是否连接成功
  while (WiFi.status() != WL_CONNECTED) {      // WiFi.status()函数的返回值是由NodeMCU的WiFi连接状态所决定的。
    delay(1000);                               // 如果WiFi连接成功则返回值为WL_CONNECTED
    Serial.print(i++); Serial.print(' ');      // 此处通过While循环让NodeMCU每隔一秒钟检查一次WiFi.status()函数返回值
  }                                            // 同时NodeMCU将通过串口监视器输出连接时长读秒。
  // 这个读秒是通过变量i每隔一秒自加1来实现的。
  Serial.println("");                          // WiFi连接成功后
  Serial.println("Connection established!");   // NodeMCU将通过串口监视器输出"连接成功"信息。
  Serial.print("IP address:    ");             // 同时还将输出NodeMCU的IP地址。这一功能是通过调用
  Serial.println(WiFi.localIP());              // WiFi.localIP()函数来实现的。该函数的返回值即NodeMCU的IP地址。
}



void runProgress()//让几个界面运行起来
{

  bool changeflag = false; //页面切换标志
  if (millis() - timeSinceLastUiUpdate > (1000L * UPDATE_UI_SECS)) //如果到了计时的时间
  {
    changeflag = true; //切换界面标志位取反
    count++;//以此作为计数值
    if (count == 4)
      count = 0;
    timeSinceLastUiUpdate = millis();

  }
  if (count == 1)
  {
    if (changeflag == true)//不要更改这两个语句的位置，不然要出bug
    {

      Move_aPage(my_oled_buf4_arry, my_oled_buf1_arry);
      changeflag = false; //只让其执行一次
    }
    drawDateTime();
  }
  if (count == 2)
  {
    if (changeflag == true)
    {

      Move_aPage(my_oled_buf1_arry, my_oled_buf2_arry);
      changeflag = false; //只让其执行一次
    }
    drawCurrentWeather();

  }
  if (count == 3)
  {
    if (changeflag == true)
    {

      Move_aPage(my_oled_buf2_arry, my_oled_buf3_arry);
      changeflag = false; //只让其执行一次
    }
    drawForcastWeather();

  }
  if (count == 0)
  {
    if (changeflag == true)
    {

      Move_aPage(my_oled_buf3_arry, my_oled_buf4_arry);
      changeflag = false; //只让其执行一次
    }
    drawGushi();

  }
}


void updateForTime()//根据设定的时间更新
{
  if (first) {  //首次加载
    StartClock();//开机动画
    first = false;
  }//mills返回开始运行当前程序的毫秒数,1000L * UPDATE_INTERVAL_SECS被视为long，它可以容纳更大的值
  if (millis() - timeSinceLastWeatherUpdate > (1000L * UPDATE_INTERVAL_SECS))//不要将判断时间设置为==，不然根本不能判断出，因为不会这么巧合刚刚等于
  { //如果现在运行的时间大于设定的时间，说明该更新了
    weatherNow.update();
    forecast.update();
    timeSinceLastWeatherUpdate = millis();//重置更新时间计时
  }
  if (millis() - timeSinceLastNongliUpdate > (1000L * UPDATE_NONGLI_SECS))
  { //农历更新
    nongli.upDate();
    timeSinceLastNongliUpdate = millis();
  }
  if (millis() - timeSinceLastGushiUpdate > (1000L * UPDATE_GUSHI_SECS))
  { //古诗更新
    gushi.upDate();
    timeSinceLastGushiUpdate = millis();
  }
  if (millis() - timeSinceLastFansUpdate > (1000L * UPDATE_Fans_SECS))
  { //粉丝更新
    fansInfo.update();
    timeSinceLastFansUpdate = millis();
  }

}

void drawPogress(int16_t degree, int16_t x, int16_t y, const char* lable) //绘制进度条
{
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tf);//设置字体
  //u8g2.setCursor(35, 45 ); //年份居中显示
  switch (degree)
  {
    case 1: u8g2.drawBox(16, 24, 20, 5); u8g2.drawStr(35 + x, 54 + y, lable); break;
    case 2: u8g2.drawBox(16, 24, 20, 5); u8g2.drawBox(42, 24, 20, 5); u8g2.drawStr(35 + x, 54 + y, lable); break;
    case 3: u8g2.drawBox(16, 24, 20, 5); u8g2.drawBox(42, 24, 20, 5); u8g2.drawBox(68, 24, 20, 5); u8g2.drawStr(35 + x, 54 + y, lable); break;
    case 4: u8g2.drawBox(16, 24, 20, 5); u8g2.drawBox(42, 24, 20, 5); u8g2.drawBox(68, 24, 20, 5); u8g2.drawBox(94, 24, 20, 5); u8g2.drawStr(35 + x, 54 + y, lable); break;
  }
  //u8g2.drawFrame(18, 22, 92, 24);
  u8g2.sendBuffer();
}


void drawDateTime() //显示时间
{
  now = time(nullptr);//time库
  struct tm* timeInfo;//声明一个结构体
  timeInfo = localtime(&now);
  char buff[16];
  char tem[8];
  const char* fans = itoa(fansInfo.getFansNumber(), tem, 10); //粉丝
  String date = WDAY_NAMES[timeInfo->tm_wday];
  u8g2.clearBuffer();//年份格式化显示
  sprintf_P(buff, PSTR("%04d-%02d-%02d %s"), timeInfo->tm_year + 1900, timeInfo->tm_mon + 1, timeInfo->tm_mday, WDAY_NAMES[timeInfo->tm_wday].c_str());
  u8g2.setFont(u8g2_font_wqy14_t_gb2312a);
  u8g2.setCursor(9 , 20 ); //年份居中显示
  u8g2.println(buff);//显示出年份
  sprintf_P(buff, PSTR("%02d:%02d:%02d"), timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);//中间大时间
  u8g2.setFont(u8g2_font_fur17_tn);
  u8g2.drawStr(19 , 45 , buff);
  drawEyebow(0, 0, 1, fans); //时间是第一页
  my_oled_buf1 = u8g2.getBufferPtr();
  for (int a = 0; a < 1024; a++)//将界面存起来
  {
    my_oled_buf1_arry[a] = my_oled_buf1[a];
  }
  u8g2.sendBuffer();

}

void littleWeatherIconShow( int16_t day, int16_t x, int16_t y) //显示小的天气图标
{
  switch (forecast.getDayCode(day))
  {
    case 0: u8g2.drawXBMP(x, y, 25, 25, qingtian2);  break; //国内城市白天晴
    case 4: u8g2.drawXBMP(x, y,   25, 22, duoyun2);  break; //多云
    case 9: u8g2.drawXBMP(x, y,   25, 25, yingtian2); break; //阴
    case 10: u8g2.drawXBMP(x, y,   25, 25, zhenyu2); break; //阵雨
    case 11: u8g2.drawXBMP(x, y,   25, 25, leiyu2);  break; //雷雨
    case 13: u8g2.drawXBMP(x, y,   25, 25, xiaoyu2);  break; //小雨
    case 14: u8g2.drawXBMP(x, y,   25, 25, zhongyu2); break; //中雨
    case 15: u8g2.drawXBMP(x, y,   25, 21, dayu2); break; //大雨
    default: u8g2.drawXBMP(x, y,   25, 25, qingtian2); break; //国内城市白天晴
  }
}
void littleWeatherTempShow(int16_t day, int16_t x, int16_t y) //显示天气预报温度
{
  char  hig[8];
  char  low[8];

  const char* higweather = itoa(forecast.getHigh(day), hig, 10); //最高温度
  const char* lowweather = itoa(forecast.getLow(day), low, 10); //最低温度

  u8g2.setFont(u8g2_font_6x12_tf);
  u8g2.drawStr(x, y, higweather);//显示高温
  u8g2.drawStr(14 + x, y, "|" );
  u8g2.drawStr(20 + x, y, lowweather); //显示低温

}

void drawForcastWeather()//显示未来三天的天气预报
{
  //forecast.update();//测试使用
  char tem[8];
  const char* fans = itoa(fansInfo.getFansNumber(), tem, 10); //粉丝
  u8g2.clearBuffer();//清空缓存
  u8g2.setFont(u8g2_font_wqy14_t_gb2312a);
  u8g2.setCursor(10, 14);
  u8g2.println("今天");
  u8g2.setCursor(50, 14 );
  u8g2.println("明天");
  u8g2.setCursor(90, 14);
  u8g2.println("后天");
  littleWeatherIconShow(0, 10, 16); //显示今天天气预报
  littleWeatherIconShow(1, 50, 16); //显示明天天气预报
  littleWeatherIconShow(2, 90, 16); //显示后天天气预报
  littleWeatherTempShow(0, 13, 48); //显示气温
  littleWeatherTempShow(1, 52, 48);
  littleWeatherTempShow(2, 90, 48);
  drawEyebow(0, 0, 3, fans); //天气预报是第三页
  my_oled_buf3 = u8g2.getBufferPtr();
  for (int a = 0; a < 1024; a++)//将界面存起来
  {
    my_oled_buf3_arry[a] = my_oled_buf3[a];
  }
  u8g2.sendBuffer();

}

void drawGushi()//显示古诗,有一些bug，比如句子不是对称长度的话就容易出错，还有就是由于字库的原因，复杂一些的字不能显示
{
  String txt;
  int commaPosition , commaPosition2, len;
  String line1, line2;
  char tem[8];
  const char* fans = itoa(fansInfo.getFansNumber(), tem, 10); //粉丝，这个函数是将int转换为const char*
  txt = gushi.getGushi();
  commaPosition = txt.indexOf('，');
  if (commaPosition != -1)//提取出逗号之间的文字
  {
    line1 = txt.substring(0, commaPosition - 2);
    line2 = txt.substring(commaPosition + 1, 2 * commaPosition - 1 );
  }
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_wqy14_t_gb2312a);
  u8g2.setCursor((126 - (14 * (line1.length() / 3))) / 2, 22); //居中显示
  u8g2.println(line1);
  u8g2.setCursor((126 - (14 * (line2.length() / 3))) / 2, 38);
  u8g2.print(line2);
  drawEyebow(0, 0, 4, fans);//显示底栏，古诗是第四页
  my_oled_buf4 = u8g2.getBufferPtr();
  for (int a = 0; a < 1024; a++)//将界面存起来
  {
    my_oled_buf4_arry[a] = my_oled_buf4[a];
  }
  u8g2.sendBuffer();
}



void drawCurrentWeather() //显示当前天气
{
  char temp[8];//声明几个变量用于存储转换的变量
  char wind[8];
  char hum[8];
  char higtemp[8];
  char tem[8];
  const char* fans = itoa(fansInfo.getFansNumber(), tem, 10); //粉丝
  String wea = weatherNow.getWeatherText();
  const char* weathernow = wea.c_str();//这个函数是将string转换为const char*类型转换，天气
  const char* windscale = itoa(forecast.getWindScale(0), wind, 10); //风力
  const char*  tempreture = itoa(weatherNow.getDegree(), temp, 10); //温度
  const char*  humidity = itoa(forecast.getHumidity(0), hum, 10); //湿度
  const char*  higtempreture = itoa(forecast.getHigh(0), higtemp, 10); //当天最高温度


  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_6x12_tf);
  //u8g2.drawStr(10 , 48 ,  weathernow); //显示现在的天气和风速
  //u8g2.drawStr(63 , 48 , "|" ); //显示现在的天气
  u8g2.drawStr(77 , 48 ,  "Wind:"); //
  u8g2.drawStr(105 , 48 ,  windscale); //显示现在风速
  u8g2.setFont(u8g2_font_logisoso24_tf);
  u8g2.drawStr(77 , 25 , tempreture);
  //u8g2.drawStr(78 , 27 , "");
  u8g2.drawXBMP(105 , 0 , 25, 25, sheshidu2); //摄氏度
  u8g2.setFont(u8g2_font_6x12_tf);
  u8g2.drawStr(77 , 38 , higtempreture);//显示当天最高温度
  u8g2.drawStr(90 , 38 , "C");
  u8g2.drawStr(99 , 38 , "|" );
  u8g2.drawStr(108 , 38 , humidity );//显示湿度
  u8g2.drawStr(120 , 38 , "%");

  //根据天气返回的代码显示对应天气的图标
  u8g2.setFont(u8g2_font_wqy14_t_gb2312a);
  u8g2.setCursor(4 , 48 );
  //显示农历
  String text = nongli.getNongli();
  u8g2.println(text);

  switch (weatherNow.getWeatherCode())
  {
    case 0: u8g2.drawXBMP(3, 3, 32, 32, sunny); u8g2.setCursor(43 , 16 ); u8g2.println("晴"); u8g2.setCursor(43 , 30 ); u8g2.println("天"); break; //国内城市白天晴
    case 4: u8g2.drawXBMP(3, 3, 35, 32, cloudy); u8g2.setCursor(43 , 16 ); u8g2.println("多"); u8g2.setCursor(43 , 30 ); u8g2.println("云"); break; //多云
    case 9: u8g2.drawXBMP(3, 3, 32, 32, ying); u8g2.setCursor(43 , 16 ); u8g2.println("阴"); u8g2.setCursor(43 , 30 ); u8g2.println("天"); break; //阴
    case 10: u8g2.drawXBMP(3, 3, 32, 32, zhenyu); u8g2.setCursor(43 , 16 ); u8g2.println("阵"); u8g2.setCursor(43 , 30 ); u8g2.println("雨"); break; //阵雨
    case 11: u8g2.drawXBMP(3, 3, 32, 32, light_rain); u8g2.setCursor(43 , 16 ); u8g2.println("雷"); u8g2.setCursor(43 , 30 ); u8g2.println("雨"); break; //雷雨
    case 13: u8g2.drawXBMP(3, 3, 32, 32, xiaoyu); u8g2.setCursor(43 , 16 ); u8g2.println("小"); u8g2.setCursor(43 , 30 ); u8g2.println("雨"); break; //小雨
    case 14: u8g2.drawXBMP(3, 3, 32, 32, zhongyu); u8g2.setCursor(43 , 16 ); u8g2.println("中"); u8g2.setCursor(43 , 30 ); u8g2.println("雨"); break; //中雨
    case 15: u8g2.drawXBMP(3, 3, 37, 32, dayu); u8g2.setCursor(43 , 16 ); u8g2.println("大"); u8g2.setCursor(43 , 30 ); u8g2.println("雨"); break; //大雨
    default: u8g2.drawXBMP(3, 3, 32, 32, sunny); u8g2.setCursor(43 , 16 ); u8g2.println("晴"); u8g2.setCursor(43 , 30); u8g2.println("天"); break; //国内城市白天晴
  }
  u8g2.drawLine(67, 0, 67, 50); //画竖直线
  drawEyebow(0, 0, 2, fans);//显示底栏，天气是第二页
  my_oled_buf2 = u8g2.getBufferPtr();
  for (int a = 0; a < 1024; a++)//将界面存起来
  {
    my_oled_buf2_arry[a] = my_oled_buf2[a];
  }
  u8g2.sendBuffer();

}


void drawPagePoint(int16_t x, int16_t y, const char* icon) //绘制底栏的小圆点
{
  u8g2.setFont(u8g2_font_wqy14_t_gb2312a);
  u8g2.setCursor( x, y);
  u8g2.println(icon);
  //u8g2.drawStr(x, y, icon);
}

void drawEyebow(int16_t x, int16_t y, int page, const char*someData) //绘制底栏
{
  now = time(nullptr);//time库
  struct tm* timeInfo;
  timeInfo = localtime(&now);
  char buff[16];
  sprintf_P(buff, PSTR("%02d:%02d"), timeInfo->tm_hour, timeInfo->tm_min);//底栏小时间
  u8g2.setFont(u8g2_font_6x12_tf);
  u8g2.drawStr(5 + x, 61 + y, buff);
  u8g2.drawStr(105 + x, 61 + y, someData);
  u8g2.drawHLine(0, 50, 128); //画底部实线
  switch (page) //显示底部小圆点
  {
    case 1: drawPagePoint(50, 61, "。"); drawPagePoint(60, 61, "."); drawPagePoint(68, 61, "."); drawPagePoint(76, 61, "."); break;
    case 2: drawPagePoint(52, 61, "."); drawPagePoint(58, 61, "。"); drawPagePoint(68, 61, "."); drawPagePoint(76, 61, "."); break;
    case 3: drawPagePoint(52, 61, "."); drawPagePoint(60, 61, "."); drawPagePoint(66, 61, "。"); drawPagePoint(76, 61, "."); break;
    case 4: drawPagePoint(52, 61, "."); drawPagePoint(60, 61, "."); drawPagePoint(68, 61, "."); drawPagePoint(74, 61, "。"); break;
deflaut: break;
  }

}

void StartClock()//开机更新
{
  drawPogress(1, 0, 0, "weatherupdate"); //更新天气
  weatherNow.update();//更新现在的天气
  fansInfo.update();//更新粉丝
  drawPogress(2, 0, 0, "forecasrupdate");
  forecast.update();//更新天气预报
  drawPogress(3, 0, 0, "nongliupdate");
  nongli.upDate();//更新农历
  drawPogress(4, 0, 0, "poemupdate");
  gushi.upDate();//更新古诗
  delay(200);
}


void Move_aPage(uint8_t  page_1[1024], uint8_t page_2[1024]) //移动页面
{
  uint8_t* disbuf;

  u8g2.clearBuffer();
  u8g2.drawXBMP(3, 3, 32, 32, light_rain);
  disbuf = u8g2.getBufferPtr();//得到一个缓存区
  my_oled_clear(disbuf);//清空disbuf,不要用u8g2.clearBuffer()，否则会把整个缓存区都删除了


  //将得到的两个界面进行拼接处理，第一种算法
  //  for (int k = 0; k < 128; k++) //刷新多少页
  //  {
  //    //my_oled_clear(disbuf);//清空disbuf
  //    for ( int i = 0; i < 8; i++) //行增，整个循环执行完后就刷新了一页
  //    {
  //      for (int j = 0; j < 127; j++) //把第一个图像的后一列赋值给前一列
  //      {
  //        page_1[i * 128 + j ] = page_1[i * 128 + j + 1];
  //
  //      }
  //      for (int j = 0; j < 128; j++) //把第二个页面的第k列赋值给第一个缓存的最后一列，始终是最后一列没有数据
  //      {
  //        page_1[i * 128 + 127 ] = page_2[i * 128 + k ];
  //      }
  //    }
  //    for (int a = 0; a < 1024; a++)//将这帧图像赋值给显存
  //    {
  //      disbuf[a] = page_1[a];
  //    }
  //    u8g2.sendBuffer();//显示
  //    delay(20);
  //  }


  //将得到的两个界面进行拼接处理，第二种算法，第二种算法比较好
  for (int k = 0; k < 128; k = k + 8) //取多少帧,这里取了8*16=128，取了16帧
  {
    for (int i = 0; i < 8; i++)
    {
      for (int j = k; j < 128; j++)//取第一个画面的后几列
      {
        disbuf[i * 128 + j - k] = page_1[i * 128 + j];
      }
      for (int j = 0; j < k; j++) //取第二个画面的前几列
      {
        disbuf[i * 128 + 127 - k + j] = page_2[i * 128 + j];
      }
    }
    u8g2.sendBuffer();//显示
    delay(10);//每帧显示时间
  }
  //u8g2.clearBuffer();//释放缓存区
}



void my_oled_clear(uint8_t* oled_gram)//清空缓存区
{
  uint8_t i, n;
  for (i = 0; i < 8; i++)//行
  {
    for (n = 0; n < 128; n++)//列
    {
      oled_gram[n + i * 128] = 0X00;
    }
  }
}

