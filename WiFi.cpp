
#define WiFi_SID YOUR_WIFI_SID
#define WiFi_pwd YOUR_WIFI_PWD

#if (WiFi_SID == YOUR_WIFI_SID)
/* IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT IMPORTANT 
 *  for privacy reasons I keep my sensitive info in a header file that isn't included
 *  You should provide your wifi sid and pwd in the lines above!
 **************************************************************************************/
# include "nogit_wifi.h"
#endif




#include <ESP8266WiFi.h>
#include "settings.h"


void doWiFiWaitDHCP() {
  
  WiFi.mode(WIFI_STA);
  if (WiFi.SSID() == 0L || WiFi.SSID() == "") {
    S.print("Need to authenticate");
    S.println();
    WiFi.begin(WiFi_SID, WiFi_pwd);
  }
  else {
    S.print("Using eeprom credentials to authenticate\n");
    WiFi.begin();

    int CONNECT_TIMEOUT = 20*1000;
    int waited = 0;
    // wait for connection
    while(waited < CONNECT_TIMEOUT) {
      if (WiFi.status() == WL_CONNECTED) {
        S.println("WiFi Connected");
        Serial.println("WiFi Connected");
        break;
      }
      delay(250);
      waited += 250;
    }
    if (WiFi.status() != WL_CONNECTED) {
      S.println("Timed out waiting for WiFi");
      Serial.println("Timed out waiting for WiFi");
    }
  }
}