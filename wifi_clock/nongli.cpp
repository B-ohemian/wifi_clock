#include "nongli.h"
#include"Arduino.h"
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <String>

String Nongli::getNongli()
{
  String message;
  message = parseInfo(nongli_line); //解析
  return message;
}

void Nongli::config(String userKey){
  _reqUserKey = userKey; 
}

bool Nongli::upDate() {
  WiFiClient client;

  // 建立http请求信息
  String httpRequest = String("GET ") + "/txapi/lunar/index?key="+_reqUserKey + " HTTP/1.1\r\n" +
                       "Host: " + "api.tianapi.com" + "\r\n" +
                       "Connection: close\r\n\r\n";
 // Serial.println("");
 // Serial.print("Connecting to "); Serial.print(Host);

  // 尝试连接服务器
  if (client.connect("api.tianapi.com", 80)) {
    //Serial.println(" Success!");

    // 向服务器发送http请求信息
    client.print(httpRequest);
   // Serial.println("Sending request: ");
   // Serial.println(httpRequest);

    // 获取并显示服务器响应状态行
    String status_response = client.readStringUntil('\n');
    //Serial.print("status_response: ");
   // Serial.println(status_response);

    // 使用find跳过HTTP响应头
    if (client.find("{")) {
      Serial.println("Found Header End. Start Parsing.");
    }

    nongli_line= "{" + client.readString();
    nongli_line = nongli_line.substring(0, nongli_line.length() - 5);//转化字符串为标准Json格式，不知道为什么，心知天气就能正常解析成功，古诗词的不可以
    //Serial.println(line);//接收数据打印测试
    //return line;//返回json数据
  } else {
    Serial.println(" connection failed!");
  }
  //断开客户端与服务器连接工作
  client.stop();
}

// 利用ArduinoJson库解析响应信息
String Nongli:: parseInfo(String& line) {

  StaticJsonDocument<2048> doc;

  DeserializationError error = deserializeJson(doc, line);

  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return "erro";
  }
  int code = doc["code"]; // 200
  const char* msg = doc["msg"]; // "success"
  JsonObject newslist_0 = doc["newslist"][0];
  const char* newslist_0_lunar_festival = newslist_0["lunar_festival"]; // "腊八节"
  const char* newslist_0_lubarmonth = newslist_0["lubarmonth"]; // "腊月"
  const char* newslist_0_lunarday = newslist_0["lunarday"]; // "初八"

  String txt1 = newslist_0["lubarmonth"].as<String>() + newslist_0["lunarday"].as<String>();
  return txt1;
}
