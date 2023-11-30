/**
   名字：nongli.h
   功能：实现农历的调取

   作者：小夸克克
   时间：2021.8.12
*/


#ifndef _NONGLI_H__
#define _NONGLI_H__

//导入arduino核心头文件
#include "Arduino.h"


class Nongli
{
  private:
    String _reqUserKey;//私钥
    String nongli_line;//返回的古诗json数据
  public:
    bool upDate();//http请求
    String getNongli(void);//获取农历信息
    void   config(String userKey);//初始化控制
    String parseInfo(String& line);//json解析
};

#endif
