
#include "TridentTD_SunriseSunset.h"
#include "utils/sunriset.h"

TridentTD_SunriseSunset::TridentTD_SunriseSunset() {
}

TridentTD_SunriseSunset::TridentTD_SunriseSunset(double lat, double lon, double timezone )
  : _lat(lat), _lon(lon) , _timezone(timezone) {
}

void TridentTD_SunriseSunset::setPosition(double lat, double lon ) {
  _lat = lat;
  _lon = lon;
}

void TridentTD_SunriseSunset::setTimezone(double timezone) {
  _timezone = timezone;
}

double TridentTD_SunriseSunset::day_Length( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year) {
  return day_length(year, month, mday, _lon, _lat );
}

double TridentTD_SunriseSunset::civilTwilight_Length( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year) {
  return day_civil_twilight_length(year, month, mday, _lon, _lat );
}

double TridentTD_SunriseSunset::nauticalTwilight_Length( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year) {
  return day_nautical_twilight_length(year, month, mday, _lon, _lat );
}

double TridentTD_SunriseSunset::astronomicalTwilight_Length( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year){
  return day_astronomical_twilight_length(year, month, mday, _lon, _lat );
}
    
static String _datetime_helper (uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year, double _clock ) {
  time_t rawtime; time ( &rawtime );
  struct tm *_tm = localtime ( &rawtime );

  _tm->tm_year = year;
  _tm->tm_mon  = month-1;
  _tm->tm_mday = mday;

  _tm->tm_hour = floor(_clock);
  _tm->tm_min  = floor(( _clock - _tm->tm_hour )*60);
  _tm->tm_sec  = floor( _clock * 3600 - _tm->tm_hour*3600 - _tm->tm_min*60 );
  mktime(_tm);

  char buf[sizeof "00:00:00"];
  strftime(buf, sizeof(buf),  "%H:%M:%S", _tm );
  return String(buf);
}

const char* TridentTD_SunriseSunset::sunrise( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year) {
  double srise; double sset;
  int rs = sun_rise_set( year, month, mday, _lon, _lat, &srise, &sset );

  srise += _timezone;
  sset  += _timezone;

  switch(rs) {
    case 0:  return _datetime_helper(mday,month,year,srise).c_str();
    case 1:  return "Sun above horizon";
    case -1: return "Sun below horizon";
  }
}

const char* TridentTD_SunriseSunset::sunset( uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year) {
  double srise; double sset;
  int rs = sun_rise_set( year, month, mday, _lon, _lat, &srise, &sset );

  srise += _timezone;
  sset  += _timezone;

  switch(rs) {
    case 0:  return _datetime_helper(mday,month,year,sset).c_str();
    case 1:  return "Sun above horizon";
    case -1: return "Sun below horizon";
  }
}

const char*  TridentTD_SunriseSunset::civilTwilight_Start(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year) {
  double cstart; double cend;
  int civ = civil_twilight( year, month, mday, _lon, _lat, &cstart, &cend );

  cstart += _timezone;
  cend  += _timezone;

  switch(civ) {
    case 0:  return _datetime_helper(mday,month,year,cstart).c_str();
    case 1:  return "Never darker than civil twilight";
    case -1: return "Never as bright as civil twilight";
  }
}

const char* TridentTD_SunriseSunset::civilTwilight_End(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year){
  double cstart; double cend;
  int civ = civil_twilight( year, month, mday, _lon, _lat, &cstart, &cend );

  cstart += _timezone;
  cend  += _timezone;

  switch(civ) {
    case 0:  return _datetime_helper(mday,month,year,cend).c_str();
    case 1:  return "Never darker than civil twilight";
    case -1: return "Never as bright as civil twilight";
  }
}


const char* TridentTD_SunriseSunset::nauticalTwilight_Start(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year){
  double nstart; double nend;
  int nautic = nautical_twilight( year, month, mday, _lon, _lat, &nstart, &nend );

  nstart += _timezone;
  nend  += _timezone;

  switch(nautic) {
    case 0:  return _datetime_helper(mday,month,year,nstart).c_str();
    case 1:  return "Never darker than nautical twilight";
    case -1: return "Never as bright as nautical twilight";
  }
}

const char* TridentTD_SunriseSunset::nauticalTwilight_End(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year) {
  double nstart; double nend;
  int nautic = nautical_twilight( year, month, mday, _lon, _lat, &nstart, &nend );

  nstart += _timezone;
  nend  += _timezone;

  switch(nautic) {
    case 0:  return _datetime_helper(mday,month,year,nend).c_str();
    case 1:  return "Never darker than nautical twilight";
    case -1: return "Never as bright as nautical twilight";
  }
}

const char* TridentTD_SunriseSunset::astronomicalTwilight_Start(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year){
  double astart; double aend;
  int astro = astronomical_twilight( year, month, mday, _lon, _lat, &astart, &aend );

  astart += _timezone;
  aend  += _timezone;

  switch(astro) {
    case 0:  return _datetime_helper(mday,month,year,astart).c_str();
    case 1:  return "Never darker than astronomical twilight";
    case -1: return "Never as bright as astronomical twilight";
  }
}

const char* TridentTD_SunriseSunset::astronomicalTwilight_End(uint8_t mday /*1-31*/, uint8_t month /* 1-12*/, int year){
  double astart; double aend;
  int astro = astronomical_twilight( year, month, mday, _lon, _lat, &astart, &aend );

  astart += _timezone;
  aend  += _timezone;

  switch(astro) {
    case 0:  return _datetime_helper(mday,month,year,aend).c_str();
    case 1:  return "Never darker than astronomical twilight";
    case -1: return "Never as bright as astronomical twilight";
  }
}
    
