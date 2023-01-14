#ifndef _sat_h_
#define _sat_h_
#include <FS.h>          // this needs to be first, or it all crashes and burns...
#include <Wire.h>
#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <ESP8266WebServer.h>
#define TRIGGER_PIN 0
#include <DMDESP.h>
#include <fonts/ElektronMart6x16.h>
#include <fonts/ElektronMart6x12.h>
#include <fonts/Mono5x7.h>
#include <fonts/Droid_Sans_12.h>
#include <fonts/Droid_Sans_16.h>
#include <fonts/Stencil18.h>
#include <fonts/droid20.h>

#include <timer.h>
#include "CountDown.h"
#include "WiFiUdp.h"
#include "NTPClient.h"
#include "DHT.h"
#include "PageIndex.h"
#include "page2.h"
#define DHTPIN 2 // na koji pin je povezan DHT11
#define DHTTYPE DHT11
#include "Arduino.h"
#define DISPLAYS_WIDE 8 //--> Panel Columns
#define DISPLAYS_HIGH 4 //--> Panel Rows
#include <string.h>
#endif
