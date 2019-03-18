#include <TridentTD_SunriseSunset.h>

                              /* lat, long, timezone */
TridentTD_SunriseSunset theSun(13.7493308,100.4873595, 7);

void setup() {
  Serial.begin(115200); Serial.println();
  Serial.printf("Day Length                  : %.2f hours\n", theSun.day_Length(18,3,2019));
  Serial.printf("Civil Twilight Length       : %.2f hours\n", theSun.civilTwilight_Length(18,3,2019));
  Serial.printf("Nautical Twilight Length    : %.2f hours\n", theSun.nauticalTwilight_Length(18,3,2019));
  Serial.printf("Atronomical Twilight Length : %.2f hours\n", theSun.astronomicalTwilight_Length(18,3,2019));
  Serial.println("----------------------------------------------------------");
  Serial.printf("Sun rise               : %s\n", theSun.sunrise(18,3,2019));
  Serial.printf("Sun set                : %s\n", theSun.sunset(18,3,2019));
  Serial.printf("Civil   Twilight Start : %s\n", theSun.civilTwilight_Start(18,3,2019));
  Serial.printf("Civil   Twilight End   : %s\n", theSun.civilTwilight_End(18,3,2019));
  Serial.printf("Nautic. Twilight Start : %s\n", theSun.nauticalTwilight_Start(18,3,2019));
  Serial.printf("Nautic. Twilight End   : %s\n", theSun.nauticalTwilight_End(18,3,2019));
  Serial.printf("Astro.  Twilight Start : %s\n", theSun.astronomicalTwilight_Start(18,3,2019));
  Serial.printf("Astro.  Twilight End   : %s\n", theSun.astronomicalTwilight_End(18,3,2019));
}

void loop() {

}

