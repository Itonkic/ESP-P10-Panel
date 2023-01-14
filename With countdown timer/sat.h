#ifndef _sat_h_
#define _sat_h_
#include <FS.h>          // this needs to be first, or it all crashes and burns...
#include <Wire.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <ESP8266WebServer.h>
#define TRIGGER_PIN 0
#include <DMDESP.h>
#include <fonts/ElektronMart6x8.h>
#include <fonts/Mono5x7.h>
#include <fonts/DejaVuSans9.h>
#include <timer.h>
#include "CountDown.h"
#include "WiFiUdp.h"
  #include "DHT.h"
#include "PageIndex.h"
#define DHTPIN 2 // na koji pin je povezan DHT11
#define DHTTYPE DHT11
#include "Arduino.h"







#endif
