#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <String>
#include "gushi.h"


void Gushi::config(String userKey) {
  _reqUserKey = userKey;
}

String Gushi::getGushi()//获取解析后的古诗数据
{
  String message;
  message = parseInfo(gushi_line); //解析
  return message;
}

// 向心知天气服务器服务器请求信息并对信息进行解析
bool Gushi::upDate() {
  WiFiClient client;

  // 建立http请求信息
  String httpRequest = String("GET ") + "/txapi/poetry/index?key=" + _reqUserKey + " HTTP/1.1\r\n" +
                       "Host: " + "api.tianapi.com" + "\r\n" +
                       "Connection: close\r\n\r\n";
  //Serial.println("");
  //Serial.print("Connecting to "); Serial.print(HOST);

  // 尝试连接服务器
  if (client.connect("api.tianapi.com", 80)) {
    //Serial.println(" Success!");

    // 向服务器发送http请求信息
    client.print(httpRequest);
    // Serial.println("Sending request: ");
    //Serial.println(httpRequest);

    // 获取并显示服务器响应状态行
    //String status_response = client.readStringUntil('\n');
    //Serial.print("status_response: ");
    // Serial.println(status_response);

    // 使用find跳过HTTP响应头，这就是那个API网站返回json数据的不标准的处理方法
    if (client.find("{")) {
      Serial.println("Found Header End. Start Parsing.");
    }

    gushi_line = "{" + client.readString();
    gushi_line = gushi_line.substring(0, gushi_line.length() - 5);//转化字符串为标准Json格式，不知道为什么，心知天气就能正常解析成功，古诗词的不可以
    //Serial.println(line);

  } else {
    Serial.println(" connection failed!");
  }
  //断开客户端与服务器连接工作
  client.stop();
}

// 利用ArduinoJson库解析响应信息
String Gushi::parseInfo(String& line) {
  StaticJsonDocument<2048> doc;

  DeserializationError error = deserializeJson(doc, line);

  if (error) {
    // Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return "窗前明月光，疑似地上霜。";
  }

  int code = doc["code"]; // 200
  const char* msg = doc["msg"]; // "success"

  JsonObject newslist_0 = doc["newslist"][0];
  //const char* newslist_0_title = newslist_0["title"]; // "送李端"
  const char* newslist_0_content = newslist_0["content"];
//  const char* newslist_0_intro = newslist_0["intro"];
//  const char* newslist_0_kind = newslist_0["kind"]; // "五言律诗"
//  const char* newslist_0_author = newslist_0["author"]; // "卢伦"

  //串口显示
  String txt = newslist_0["content"].as<String>();
  //Serial.println(txt.length() / 3);
  //Serial.println(txt);
  return txt;
}
