#ifndef __TRIDENTTDD_SUNRISE_SUNSET_H__
#define __TRIDENTTDD_SUNRISE_SUNSET_H__

#include <Arduino.h>
#include <time.h>

class TridentTD_SunriseSunset {
  public:
    TridentTD_SunriseSunset();
    TridentTD_SunriseSunset(double lat, double lon , double timezone);
    void      setPosition(double lat, double lon );
    void      setTimezone(double timezone);
    double    day_Length( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    double    civilTwilight_Length( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    double    nauticalTwilight_Length( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    double    astronomicalTwilight_Length( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    const char* sunrise( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    const char* sunset( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    const char* civilTwilight_Start(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    const char* civilTwilight_End(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    const char* nauticalTwilight_Start(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    const char* nauticalTwilight_End(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    const char* astronomicalTwilight_Start(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
    const char* astronomicalTwilight_End(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year);
  
  private:
    double _lat;
    double _lon;
    double _timezone;
};

#endif
