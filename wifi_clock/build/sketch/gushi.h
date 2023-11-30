/**
   名字：gushi.h
   功能：实现古诗的调取

   作者：小夸克克
   时间：2021.8.12
*/


#ifndef _GUSHI_H__
#define _GUSHI_H__

//导入arduino核心头文件
#include "Arduino.h"


class Gushi
{
  private:
    String _reqUserKey;//私钥
    String gushi_line;//获得古诗的json数据
  public:
    String getGushi();//http请求
    bool upDate();//更新
    String parseInfo(String& line);
    void config(String userKey);//配置
};

#endif
