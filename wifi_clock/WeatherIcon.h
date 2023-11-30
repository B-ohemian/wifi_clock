// width: 32, height: 32 晴天
const unsigned char sunny[] U8X8_PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                             0x80, 0x01, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0xe0, 0xe0, 0x07,
                                             0x07, 0xc0, 0xf8, 0x1f, 0x03, 0x00, 0x1e, 0x78, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x80,
                                             0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0xce, 0x00, 0x00,
                                             0x73, 0xce, 0x00, 0x00, 0x73, 0xc0, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x03, 0x80, 0x01, 0x80, 0x01, 0x80,
                                             0x01, 0x80, 0x01, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x1e, 0x78, 0x00, 0xc0, 0xf8, 0x1f,
                                             0x03, 0xe0, 0xe0, 0x07, 0x07, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00,
                                             0x80, 0x01, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00
                                           };

// width: 35, height: 32 多云
const unsigned char cloudy[] U8X8_PROGMEM = { 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00,
                                              0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x04, 0x00, 0x40, 0x00, 0x00, 0x08, 0x00,
                                              0x60, 0x00, 0x00, 0x10, 0x00, 0x30, 0x00, 0x00, 0x00, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x87, 0x03, 0x00, 0x00,
                                              0x80, 0x01, 0x06, 0x00, 0x00, 0xc0, 0x00, 0x0c, 0x00, 0x00, 0x6c, 0x00, 0x08, 0x00, 0xc0, 0xf3, 0x00, 0x18,
                                              0x00, 0x60, 0x80, 0x01, 0x90, 0x07, 0x18, 0x00, 0x06, 0x10, 0x00, 0x0c, 0x00, 0x0c, 0x10, 0x00, 0x04, 0x00,
                                              0x08, 0x10, 0x00, 0x02, 0x00, 0x10, 0x1e, 0x00, 0x02, 0x00, 0xf0, 0x3d, 0x00, 0x03, 0x00, 0x30, 0x60, 0x00,
                                              0x01, 0x00, 0x00, 0xc0, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
                                              0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x00, 0x01, 0x06,
                                              0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x00, 0x01, 0x08, 0x00, 0x00, 0x80, 0x00, 0x10, 0x00, 0x00, 0xc0,
                                              0x00, 0xe0, 0xff, 0xff, 0x7f, 0x00
                                            };

// width: 32, height: 32 雷雨
const unsigned char light_rain[] U8X8_PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0x00, 0x00, 0x30,
                                                  0x30, 0x00, 0x00, 0x18, 0x40, 0x00, 0x00, 0x08, 0xc0, 0x00, 0x00, 0x0c, 0x80, 0x00, 0xe0, 0x0f, 0x80, 0x07,
                                                  0x30, 0x04, 0x00, 0x0c, 0x18, 0x00, 0x00, 0x18, 0x0c, 0x00, 0x00, 0x30, 0x06, 0x00, 0x00, 0x60, 0x02, 0x00,
                                                  0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x40,
                                                  0x06, 0x00, 0x00, 0x60, 0x04, 0x00, 0x00, 0x20, 0x0c, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x18, 0xf0, 0x00,
                                                  0x00, 0x0f, 0xc0, 0xff, 0xff, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x00, 0x00,
                                                  0x00, 0x60, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x30,
                                                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                                };
// width: 32, height: 32 阴天
const unsigned char ying[] U8X8_PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0x00, 0xf0, 0x0f, 0x00, 0x00, 0xfc, 0x3f, 0x00, 0x00, 0x1e, 0x78, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x03,
                                            0xc0, 0x00, 0x80, 0x03, 0xc0, 0x01, 0xc0, 0x01, 0x80, 0x03, 0xf0, 0x01, 0x80, 0x0f, 0x78, 0x00, 0x00, 0x1e,
                                            0x18, 0x00, 0x00, 0x18, 0x1c, 0x00, 0x00, 0x38, 0x0c, 0x00, 0x00, 0x30, 0x0c, 0x00, 0x00, 0x30, 0x1c, 0x00,
                                            0x00, 0x38, 0x18, 0x00, 0x00, 0x18, 0x38, 0x00, 0x00, 0x1c, 0xf0, 0xff, 0xff, 0x0f, 0xe0, 0xff, 0xff, 0x07,
                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                          };
// width: 32, height: 32 小雨
const unsigned char xiaoyu[] U8X8_PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                              0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0xfe, 0x07, 0x00, 0x00, 0x03, 0x0c, 0x00, 0x80, 0x00, 0x10, 0x00,
                                              0x40, 0x00, 0x20, 0x00, 0x60, 0x00, 0x60, 0x00, 0x20, 0x00, 0xc0, 0x0f, 0x20, 0x00, 0x00, 0x18, 0x30, 0x00,
                                              0x00, 0x20, 0x1c, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x80,
                                              0x01, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x40, 0x03, 0x00, 0x00, 0x60, 0x02, 0x00,
                                              0x00, 0x20, 0x0c, 0x60, 0x06, 0x18, 0x78, 0x20, 0x02, 0x0f, 0x00, 0x10, 0x01, 0x00, 0x00, 0x98, 0x01, 0x00,
                                              0x00, 0x88, 0x00, 0x00, 0x00, 0xcc, 0x00, 0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                              0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                            };
// width: 32, height: 32 中雨
const unsigned char zhongyu[] U8X8_PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x03, 0x00, 0x00, 0x1c, 0x06, 0x00, 0x00, 0x06, 0x08, 0x00,
                                               0x00, 0x02, 0x70, 0x00, 0x00, 0x01, 0xa0, 0x03, 0x00, 0x01, 0x00, 0x04, 0x80, 0x01, 0x00, 0x08, 0xe0, 0x00,
                                               0x00, 0x08, 0x30, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x08,
                                               0x10, 0x00, 0x00, 0x04, 0x70, 0x00, 0x00, 0x03, 0xc0, 0xff, 0xff, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x00, 0x00, 0x00, 0x81, 0x40, 0x00, 0x80, 0xc1, 0x60, 0x00, 0x80, 0x40, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x00, 0x04, 0x02, 0x00, 0x00, 0x06, 0x03, 0x00, 0x00, 0x83, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                               0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                                             };
// width: 37, height: 32 大雨
const unsigned char dayu[] U8X8_PROGMEM = { 0x00, 0xe0, 0x03, 0x00, 0x00, 0x00, 0xfc, 0x0f, 0x00, 0x00,
                                            0x00, 0x1e, 0x38, 0x00, 0x00, 0x00, 0x03, 0x60, 0x00, 0x00, 0x80, 0x01, 0xc0, 0x00, 0x00, 0xc0, 0x00, 0xc0,
                                            0x00, 0x00, 0xc0, 0x00, 0x80, 0x1f, 0x00, 0x40, 0x00, 0x80, 0x3d, 0x00, 0x60, 0x00, 0x00, 0x60, 0x00, 0x60,
                                            0x00, 0x00, 0xc0, 0x00, 0x60, 0x00, 0x00, 0xc0, 0x00, 0x70, 0x00, 0x00, 0x80, 0x00, 0x3c, 0x00, 0x00, 0x80,
                                            0x01, 0x0e, 0x00, 0x00, 0x80, 0x07, 0x06, 0x00, 0x00, 0x00, 0x0e, 0x07, 0x00, 0x00, 0x00, 0x0c, 0x03, 0x00,
                                            0x00, 0x00, 0x1c, 0x03, 0x00, 0x00, 0x00, 0x18, 0x03, 0x00, 0x00, 0x00, 0x18, 0x03, 0x00, 0x00, 0x00, 0x18,
                                            0x02, 0x00, 0x00, 0x00, 0x18, 0x06, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x0c, 0x38, 0x40, 0x88,
                                            0x01, 0x07, 0xf0, 0x67, 0x8c, 0xfd, 0x03, 0x00, 0x60, 0xbd, 0x01, 0x00, 0x00, 0xe0, 0xbd, 0x00, 0x00, 0x00,
                                            0xe0, 0xf7, 0x00, 0x00, 0x00, 0xa0, 0xd7, 0x00, 0x00, 0x00, 0xa0, 0xdf, 0x00, 0x00, 0x00, 0x80, 0x18, 0x00,
                                            0x00, 0x00, 0x80, 0x18, 0x00, 0x00
                                          };
// width: 32, height: 32  阵雨
const unsigned char zhenyu[] U8X8_PROGMEM = { 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00,
                                              0x10, 0x00, 0x00, 0x08, 0x00, 0x10, 0x00, 0x18, 0x00, 0x18, 0x00, 0x30, 0x00, 0x0c, 0x00, 0x00, 0x7e, 0x00, 0x00,
                                              0xe0, 0xc7, 0x01, 0x00, 0xf8, 0x03, 0x01, 0xc0, 0x0d, 0x06, 0x03, 0xf0, 0x07, 0x0c, 0x02, 0x10, 0x02, 0x08, 0x02,
                                              0x18, 0x00, 0x18, 0xe2, 0x18, 0x00, 0x18, 0x02, 0x1c, 0x00, 0x38, 0x03, 0x06, 0x00, 0xe0, 0x01, 0x02, 0x00, 0xc0,
                                              0x00, 0x03, 0x00, 0xc0, 0x00, 0x01, 0x00, 0xc0, 0x04, 0x03, 0x00, 0xc0, 0x0c, 0x03, 0x00, 0x40, 0x08, 0x06, 0x00,
                                              0x70, 0x00, 0xfc, 0xff, 0x1f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x22, 0x02, 0x00, 0x20,
                                              0x62, 0x06, 0x00, 0x20, 0x22, 0x02, 0x00, 0x20, 0x22, 0x02, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x23, 0x00, 0x00,
                                              0x00, 0x22, 0x00, 0x00
                                            };
// width: 32, height: 32 摄氏度
const unsigned char sheshidu[] U8X8_PROGMEM = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                0x00, 0x00, 0x00, 0x0e, 0x7f, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x9a, 0x00, 0x00, 0x00, 0x9e, 0x00, 0x00, 0x00,
                                                0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00,
                                                0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00,
                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                0x00, 0x00, 0x00
                                              };
// width: 25, height: 25 摄氏度2
const unsigned char sheshidu2[] U8X8_PROGMEM = { 0xe0,0xe0,0x03,0x00,0xb0,0xf9,0x07,0x00,0xb0,0xfd,0x0f,0x00,0xe0,0x3c,0x0f,0x00,0x40,0x1c,0x1e,0x00,0x00,0x1e,0x1e,0x00,0x00,0x1e,0x1e,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x00,0x00,0x00,0x1e,0x1e,0x00,0x00,0x1e,0x1e,0x00,0x00,0x1c,0x1e,0x00,0x00,0x7c,0x0f,0x00,0x00,0xfc,0x0f,0x00,0x00,0xf8,0x07,0x00,0x00,0xe0,0x01,0x00 };                                           
// width: 25, height: 25 晴天2
const unsigned char qingtian2[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x18,0x00,0x30,0xfe,0x18,0x00,0x00,0xc7,0x01,0x00,0x80,0x01,0x03,0x00,0xc0,0x00,0x06,0x00,0x60,0x00,0x0c,0x00,0x60,0x00,0x0c,0x00,0x24,0x00,0x48,0x00,0x26,0x00,0xc8,0x00,0x24,0x00,0x48,0x00,0x60,0x00,0x0c,0x00,0x60,0x00,0x0c,0x00,0xc0,0x00,0x06,0x00,0x80,0x01,0x03,0x00,0x00,0xc7,0x01,0x00,0x30,0xfe,0x18,0x00,0x30,0x00,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x38,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x00,0x00,0x00 };
// width: 25, height: 22 多云2
const unsigned char duoyun2[] U8X8_PROGMEM = { 0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x00,0x80,0x00,0x20,0x00,0x00,0x01,0x10,0x00,0x00,0xf0,0x03,0x00,0x00,0x08,0x04,0x00,0x00,0x04,0x08,0x00,0xe0,0x07,0x18,0x00,0x18,0x18,0xd0,0x01,0x04,0x20,0x10,0x00,0x02,0x40,0x10,0x00,0x02,0x40,0x1f,0x00,0x01,0x80,0x20,0x00,0x01,0x00,0x40,0x00,0x01,0x00,0x80,0x00,0x01,0x00,0x80,0x00,0x01,0x00,0x80,0x00,0x02,0x00,0x80,0x00,0x02,0x00,0x80,0x00,0x04,0x00,0x40,0x00,0xf8,0xff,0x3f,0x00 };
// width: 25, height: 25 雷雨2
const unsigned char leiyu2[] U8X8_PROGMEM = { 0x00,0x70,0x00,0x00,0x00,0xdc,0x01,0x00,0x00,0x06,0x03,0x00,0x00,0x03,0x06,0x00,0x00,0x01,0x04,0x00,0xf8,0x01,0x3c,0x00,0x0c,0x00,0x60,0x00,0x06,0x00,0xc0,0x00,0x02,0x00,0x80,0x00,0x02,0x00,0x80,0x00,0x03,0x00,0x80,0x01,0x02,0x00,0x80,0x00,0x02,0x00,0x80,0x00,0x02,0x00,0x80,0x00,0x04,0x00,0x40,0x00,0x18,0x00,0x30,0x00,0xf0,0xff,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x1c,0x00,0x00,0x00,0x08,0x00,0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
// width: 25, height: 25 阵雨2
const unsigned char zhenyu2[] U8X8_PROGMEM = { 0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0x60,0x00,0x00,0x84,0x21,0x00,0x00,0xe0,0x07,0x00,0x00,0x3e,0x0c,0x00,0xf0,0x41,0x08,0x00,0xd8,0xc0,0x18,0x00,0x08,0x80,0xd8,0x01,0x0c,0x80,0x08,0x00,0x0c,0x80,0x0d,0x00,0x02,0x00,0x06,0x00,0x01,0x00,0x06,0x00,0x01,0x00,0x16,0x00,0x01,0x00,0x22,0x00,0x02,0x00,0x03,0x00,0xfc,0xff,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x90,0x64,0x00,0x00,0x90,0x24,0x00,0x00,0x90,0x24,0x00,0x00,0x80,0x04,0x00,0x00,0x80,0x04,0x00,0x00 };
// width: 25, height: 21 大雨2
const unsigned char dayu2[] U8X8_PROGMEM = { 0x00,0x1f,0x00,0x00,0xc0,0x71,0x00,0x00,0x60,0xc0,0x00,0x00,0x30,0x80,0x00,0x00,0x10,0x00,0x0f,0x00,0x10,0x00,0x18,0x00,0x18,0x00,0x30,0x00,0x1c,0x00,0x20,0x00,0x0e,0x00,0x60,0x00,0x02,0x00,0xc0,0x00,0x03,0x00,0x80,0x01,0x01,0x00,0x00,0x01,0x01,0x00,0x00,0x01,0x03,0x00,0x80,0x01,0x02,0x00,0x80,0x00,0x1c,0x32,0xe1,0x00,0x70,0xb2,0x3d,0x00,0x00,0xfe,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0xb6,0x00,0x00,0x00,0x24,0x00,0x00 };
// width: 25, height: 25 中雨2
const unsigned char zhongyu2[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3e,0x00,0x00,0x00,0x43,0x00,0x00,0x80,0x80,0x01,0x00,0x40,0x00,0x0f,0x00,0x40,0x00,0x10,0x00,0x60,0x00,0x20,0x00,0x18,0x00,0x20,0x00,0x08,0x00,0x20,0x00,0x08,0x00,0x20,0x00,0x08,0x00,0x20,0x00,0x18,0x00,0x18,0x00,0xe0,0xff,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x08,0x02,0x00,0x20,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x80,0x20,0x00,0x00,0x80,0x10,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
// width: 25, height: 25 小雨2
const unsigned char xiaoyu2[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0x80,0x7f,0x00,0x00,0xc0,0xc0,0x00,0x00,0x20,0x00,0x01,0x00,0x10,0x00,0x03,0x00,0x10,0x00,0x3e,0x00,0x18,0x00,0x60,0x00,0x0c,0x00,0x80,0x00,0x06,0x00,0x80,0x01,0x03,0x00,0x00,0x01,0x01,0x00,0x00,0x01,0x01,0x00,0x00,0x01,0x01,0x00,0x80,0x01,0x02,0x00,0x80,0x00,0x06,0x04,0x60,0x00,0x1c,0x24,0x38,0x00,0x00,0x32,0x00,0x00,0x00,0x12,0x00,0x00,0x00,0x09,0x00,0x00,0x80,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
// width: 25, height: 25 阴天2
const unsigned char yingtian2[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7c,0x00,0x00,0x00,0xff,0x01,0x00,0x80,0x83,0x03,0x00,0xc0,0x01,0x07,0x00,0xc0,0x00,0x06,0x00,0x60,0x00,0x0c,0x00,0x78,0x00,0x3c,0x00,0x1c,0x00,0x70,0x00,0x0c,0x00,0x60,0x00,0x04,0x00,0x60,0x00,0x04,0x00,0x60,0x00,0x0c,0x00,0x60,0x00,0x1c,0x00,0x70,0x00,0xf8,0xff,0x3f,0x00,0xe0,0xff,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

// width: 40, height: 42 动画1
const unsigned char donghua1[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6c,0x00,0x00,0x00,0x30,0x82,0x18,0x00,0x00,0xcc,0x01,0x23,0x00,0x00,0x84,0x82,0x42,0x00,0x00,0x42,0x3c,0x82,0x00,0x00,0x60,0x00,0x8c,0x00,0x80,0x1f,0x00,0xf0,0x03,0x60,0x01,0x00,0x00,0x0d,0x90,0x00,0x00,0x00,0x10,0x90,0x00,0x00,0x00,0x12,0x48,0x00,0x00,0x00,0x24,0x28,0x00,0x00,0x00,0x28,0x18,0x00,0x00,0x00,0x30,0x0c,0x00,0x00,0x00,0x20,0x0c,0x00,0x00,0x00,0x60,0x02,0x00,0x00,0x00,0xa0,0x06,0x00,0x00,0x00,0xc0,0x06,0x00,0x00,0x00,0xc0,0x06,0x00,0x00,0x00,0xc0,0x02,0x00,0x00,0x00,0x80,0x02,0x00,0x00,0x00,0x80,0x02,0x00,0x00,0x00,0x80,0x02,0x00,0x00,0x00,0x80,0x02,0x00,0x00,0x00,0x80,0x02,0x00,0x00,0x00,0x80,0x06,0x00,0x00,0x00,0xc0,0x04,0x00,0x00,0x00,0x40,0x04,0x00,0x00,0x00,0x40,0x04,0x00,0x00,0x00,0x20,0x08,0x00,0x00,0x00,0x20,0x08,0x00,0x00,0x00,0x30,0x10,0x00,0x00,0x00,0x10,0x20,0x00,0x00,0x00,0x08,0x60,0x00,0x00,0x00,0x04,0xc0,0x00,0x00,0x00,0x06,0x80,0x01,0x00,0x00,0x03,0x00,0x02,0x00,0x80,0x00,0x00,0x0c,0x00,0x60,0x00,0x00,0x30,0x00,0x18,0x00,0x00,0xc0,0x81,0x07,0x00,0x00,0x00,0x3c,0x00,0x00 };
// width: 40, height: 39 动画2
const unsigned char donghua2[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xf7,0x03,0x00,0x00,0x20,0x1e,0x04,0x00,0x00,0xf8,0x61,0x7c,0x00,0x00,0x06,0x80,0x8b,0x01,0x00,0x03,0x00,0x00,0x01,0x80,0x00,0x00,0x10,0x02,0x40,0x00,0x00,0x20,0x02,0x20,0x00,0x00,0xc0,0x03,0x10,0x00,0x00,0x00,0x0e,0x08,0x00,0x00,0x00,0x32,0x08,0x00,0x00,0x00,0x22,0x04,0x00,0x00,0x00,0x02,0x04,0x00,0x00,0x00,0x02,0x02,0x00,0x00,0x00,0x24,0x02,0x00,0x00,0x00,0x28,0x02,0x00,0x00,0x00,0x30,0x02,0x00,0x00,0x00,0x50,0x02,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x88,0x00,0x00,0x00,0x00,0x88,0x00,0x00,0x00,0x00,0x08,0x02,0x00,0x00,0x00,0x50,0x02,0x00,0x00,0x00,0x30,0x02,0x00,0x00,0x00,0x30,0x02,0x00,0x00,0x00,0x30,0x04,0x00,0x00,0x00,0x28,0x04,0x00,0x00,0x00,0x24,0x04,0x00,0x00,0x00,0x14,0x08,0x00,0x00,0x00,0x18,0x10,0x00,0x00,0x00,0x0e,0x10,0x00,0x00,0x00,0x02,0x20,0x00,0x00,0x00,0x01,0x40,0x00,0x00,0xc0,0x01,0x80,0x01,0x00,0xe0,0x00,0x00,0x02,0x00,0x70,0x00,0x00,0x0c,0x00,0x1c,0x00,0x00,0x70,0x80,0x03,0x00,0x00,0x00,0x7f,0x00,0x00 };
// width: 40, height: 39 动画3
const unsigned char donghua3[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0xf3,0x01,0x00,0x00,0x18,0x00,0x0e,0x00,0x00,0x06,0x00,0x38,0x00,0x80,0x01,0x00,0x60,0x00,0xc0,0x00,0x00,0x80,0x00,0x20,0x00,0x00,0x80,0x03,0x10,0x00,0x00,0x00,0x05,0x10,0x00,0x00,0x00,0x09,0x08,0x00,0x00,0x00,0x0a,0x04,0x00,0x00,0x00,0x0c,0x04,0x00,0x00,0x00,0x18,0x02,0x00,0x00,0x00,0x38,0x02,0x00,0x00,0x00,0x28,0x02,0x00,0x00,0x00,0x48,0x00,0x00,0x00,0x00,0x48,0x01,0x00,0x00,0x00,0x08,0x01,0x00,0x00,0x00,0x50,0x01,0x00,0x00,0x00,0x70,0x01,0x00,0x00,0x00,0x20,0x01,0x00,0x00,0x00,0x50,0x01,0x00,0x00,0x00,0x48,0x01,0x00,0x00,0x00,0x88,0x02,0x00,0x00,0x00,0x84,0x02,0x00,0x00,0x00,0x84,0x02,0x00,0x00,0x00,0x48,0x04,0x00,0x00,0x00,0x28,0x04,0x00,0x00,0x00,0x0c,0x08,0x00,0x00,0x00,0x03,0x08,0x00,0x00,0x80,0x10,0x10,0x00,0x00,0x80,0x00,0x20,0x00,0x00,0x00,0x08,0x40,0x00,0x00,0x40,0x04,0x80,0x00,0x00,0xf8,0x03,0x00,0x03,0x00,0x46,0x00,0x00,0x0e,0x00,0x21,0x00,0x00,0x78,0xbe,0x30,0x00,0x00,0x80,0xc1,0x0f,0x00,0x00,0x00,0x3e,0x00,0x00 };
// width: 40, height: 41 动画4
const unsigned char donghua4[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xff,0x01,0x00,0x00,0x70,0x00,0x0c,0x00,0x00,0x0c,0x00,0x30,0x00,0x00,0x02,0x00,0xc0,0x00,0x00,0x01,0x00,0x80,0x01,0x80,0x00,0x00,0x00,0x02,0x40,0x00,0x00,0x00,0x04,0x20,0x00,0x00,0x00,0x08,0x10,0x00,0x00,0x00,0x08,0x18,0x00,0x00,0x00,0x10,0x08,0x00,0x00,0x00,0x30,0x0c,0x00,0x00,0x00,0x20,0x04,0x00,0x00,0x00,0x20,0x04,0x00,0x00,0x00,0x40,0x00,0x00,0x00,0x00,0x40,0x02,0x00,0x00,0x00,0x40,0x02,0x00,0x00,0x00,0x40,0x02,0x00,0x00,0x00,0xc0,0x02,0x00,0x00,0x00,0xc0,0x02,0x00,0x00,0x00,0xc0,0x02,0x00,0x00,0x00,0xc0,0x02,0x00,0x00,0x00,0x40,0x02,0x00,0x00,0x00,0x40,0x04,0x00,0x00,0x00,0x40,0x04,0x00,0x00,0x00,0x60,0x08,0x00,0x00,0x00,0x50,0x14,0x00,0x00,0x00,0x50,0x14,0x00,0x00,0x00,0x28,0x08,0x00,0x00,0x00,0x28,0x30,0x00,0x00,0x00,0x18,0x60,0x00,0x00,0x00,0x0c,0xa0,0x01,0x00,0x80,0x05,0x40,0x06,0x00,0x40,0x04,0x40,0x04,0x00,0x20,0x02,0x80,0xc8,0x81,0x13,0x02,0x00,0x3f,0x46,0xfc,0x01,0x00,0x10,0x2c,0x08,0x00,0x00,0x20,0x18,0x08,0x00,0x00,0x40,0x24,0x06,0x00,0x00,0x80,0x81,0x01,0x00 };
// width: 40, height: 39 动画5
const unsigned char donghua5[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x01,0x00,0x00,0xe0,0x00,0x0c,0x00,0x00,0x38,0x00,0x20,0x00,0x00,0x0c,0x00,0xc0,0x00,0x00,0x03,0x00,0x00,0x01,0x80,0x01,0x00,0x00,0x02,0x40,0x01,0x00,0x00,0x04,0xa0,0x00,0x00,0x00,0x08,0x40,0x00,0x00,0x00,0x10,0x30,0x00,0x00,0x00,0x10,0x10,0x00,0x00,0x00,0x20,0x18,0x00,0x00,0x00,0x20,0x14,0x00,0x00,0x00,0x40,0x10,0x00,0x00,0x00,0x40,0x12,0x00,0x00,0x00,0x40,0x12,0x00,0x00,0x00,0x00,0x0a,0x00,0x00,0x00,0x80,0x0c,0x00,0x00,0x00,0x80,0x04,0x00,0x00,0x00,0x80,0x0a,0x00,0x00,0x00,0x80,0x12,0x00,0x00,0x00,0x00,0x22,0x00,0x00,0x00,0x40,0x22,0x00,0x00,0x00,0x40,0x22,0x00,0x00,0x00,0x40,0x04,0x00,0x00,0x00,0x40,0x18,0x00,0x00,0x00,0x20,0x70,0x00,0x00,0x00,0x20,0x90,0x01,0x00,0x00,0x10,0x10,0x01,0x00,0x00,0x08,0x10,0x02,0x00,0x00,0x08,0x10,0x02,0x00,0x00,0x04,0x60,0x02,0x00,0x00,0x02,0x00,0x3f,0x00,0x80,0x01,0x00,0x42,0x00,0xe0,0x00,0x00,0x84,0x00,0x38,0x00,0x00,0x08,0xe7,0x1f,0x00,0x00,0x70,0xc6,0x00,0x00,0x00,0x00,0x38,0x00,0x00 };
// width: 40, height: 38 动画6
const unsigned char donghua6[] U8X8_PROGMEM = { 0x00,0x00,0x07,0x00,0x00,0x00,0xc0,0xf0,0x07,0x00,0x00,0x40,0x8c,0x0f,0x00,0x00,0xfe,0x03,0x30,0x00,0x00,0x11,0x00,0xc0,0x00,0x80,0x10,0x00,0x00,0x01,0x80,0x08,0x00,0x00,0x02,0x80,0x06,0x00,0x00,0x04,0xe0,0x00,0x00,0x00,0x08,0x88,0x00,0x00,0x00,0x10,0x84,0x00,0x00,0x00,0x10,0x84,0x00,0x00,0x00,0x20,0x44,0x00,0x00,0x00,0x00,0x64,0x00,0x00,0x00,0x40,0x18,0x00,0x00,0x00,0x40,0x08,0x00,0x00,0x00,0x00,0x14,0x00,0x00,0x00,0x80,0x12,0x00,0x00,0x00,0x80,0x12,0x00,0x00,0x00,0x80,0x10,0x00,0x00,0x00,0x80,0x12,0x00,0x00,0x00,0x80,0x12,0x00,0x00,0x00,0x80,0x0c,0x00,0x00,0x00,0x80,0x08,0x00,0x00,0x00,0x00,0x10,0x00,0x00,0x00,0x40,0x20,0x00,0x00,0x00,0x40,0x28,0x00,0x00,0x00,0x20,0x48,0x00,0x00,0x00,0x20,0x50,0x00,0x00,0x00,0x10,0x60,0x00,0x00,0x00,0x10,0xc0,0x00,0x00,0x00,0x08,0x80,0x01,0x00,0x00,0x04,0x00,0x03,0x00,0x00,0x02,0x00,0x06,0x00,0x00,0x01,0x00,0x1c,0x00,0xc0,0x00,0x00,0x70,0x00,0x30,0x00,0x00,0xc0,0x03,0x0f,0x00,0x00,0x00,0xf8,0x00,0x00 };


// width: 64, height: 64 调皮
const unsigned char tiaopi[] U8X8_PROGMEM = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x7f,0x00,0x00,0xff,0xff,0x1f,0x00,0xfc,0x7f,0x00,0x80,0xff,0xff,0x3f,0x00,0xfc,0x7f,0x00,0x80,0xff,0xff,0x3f,0x00,0xfc,0x7f,0x00,0x80,0xff,0xff,0x3f,0x00,0xfc,0x7f,0x00,0x80,0xff,0xff,0x3f,0x00,0xfc,0x7f,0x00,0x00,0xff,0xff,0x1f,0x00,0xfc,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0e,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1f,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xfe,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xfc,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0xf8,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x0f,0x00,0x00,0x00,0x00,0x00,0x00,0xf0,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0xe0,0x7f,0x00,0x00,0x00,0x00,0x00,0x00,0xc0,0xff,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xff,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0xff,0x0f,0x00,0x00,0x1c,0x00,0x00,0x00,0xfe,0x7f,0x00,0x80,0x3f,0x00,0x00,0x00,0xf8,0xff,0x03,0xf8,0x7f,0x00,0x00,0x00,0xf0,0xff,0xff,0xff,0x7f,0x00,0x00,0x00,0xe0,0xff,0xff,0xff,0x7f,0x00,0x00,0x00,0x80,0xff,0xff,0xff,0x3f,0x00,0x00,0x00,0x00,0xfe,0xff,0xff,0x1f,0x00,0x00,0x00,0x00,0xf0,0xff,0xff,0x03,0x00,0x00,0x00,0x00,0x80,0xff,0x3f,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
