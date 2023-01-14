#include <FS.h>          // this needs to be first, or it all crashes and burns..
#include "asat.h"
int pocetak = 0;
WiFiManager wm; //// global wm instance
WiFiUDP ntpUDP;
unsigned long currentMillis;
const int sirenat = 5;
const int sirenap = 4;
String monthStamp;
String dayStamp;
String rtc;
const int sirenaq = 1;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 7200);
ESP8266WebServer server(80);
unsigned long currentMilliss;
DHT dht(DHTPIN, DHTTYPE);
String Incoming_Text = ""; //--> Variable to hold the text that is sent from a web server (web page)
String Incoming_Text2 = ""; //--> Variable to hold the text that is sent from a web server (web page)
String data = "NESTOJAKOZANIMLJIVO";
String flashtext = "";
DMDESP Disp(DISPLAYS_WIDE, DISPLAYS_HIGH);  //--> Number of Panels P10 used (Column, Row)
int ass;
  float t;
  unsigned long previousMilliss = 0;
unsigned long intervall = 600000;
int h;
String formattedDate;
unsigned long starttime;
unsigned long endtime;
const char* ssid = "";
int zapiss;
String oneLLine;
const char* password = "";
unsigned long previousMillis = 0;
unsigned long interval = 1000;
bool wm_nonblocking = false; // change to true to use non blocking
int ser = 0;
char *Text[] = {"Some text that will be scrolling"}; //--> Variable for scrolling Text. Don't leave this variable blank
String sa[3];
String temp[3];
  String oneLine ;

int vrijeme[30];
CountDown CD;
String fdata;
WiFiManagerParameter custom_field; // global param ( for non blocking w params )
int hr;
int miin;
int sec;
int q[30];
String test = "";
bool success = SPIFFS.begin();

void vremena(String flash) {
  delay(500);
  String oneLine = flash;
  int str_len = flash.length() + 1;
  Serial.println("vremena");
  char char_array[str_len];
  //Serial.println(Incoming_Text.toCharArray(char_array, str_len));
  Incoming_Text.toCharArray(char_array, str_len);
  //strcpy(Text[0], char_array);
  int r = 0, t = 0;
  for (int i = 0; i < oneLine.length(); i++)
  {
    if (oneLine.charAt(i) == '_')
    {
      vrijeme[t] = oneLine.substring(r, i).toInt();
      r = (i + 1);
      t++;
    }
  }
  fdata = String(vrijeme[1]) + "_" + String(vrijeme[2]) + "_" + String(vrijeme[3]) + "_" + String(vrijeme[4]) + "_" + String(vrijeme[5]) + "_" + String(vrijeme[6]) + "_" + String(vrijeme[7]) + "_" + String(vrijeme[8]) + "_" + String(vrijeme[9]) + "_" + String(vrijeme[10]) + "_" + String(vrijeme[11]) + "_" + String(vrijeme[12]) + "_" + String(vrijeme[13]) + "_" + String(vrijeme[14]) + "_" + String(vrijeme[15]) + "_" + String(vrijeme[16]) + "_" + String(vrijeme[17]) + "_" + String(vrijeme[18]) + "_" + String(vrijeme[19]) + "_" + String(vrijeme[20]) + "_" + String(vrijeme[21]) + "_" + String(vrijeme[22]) + "_" + String(vrijeme[23]) + "_" + String(vrijeme[24]) + "_" + String(vrijeme[25]) + "_" + String(vrijeme[26]) + "_" + String(vrijeme[27]) + "_" + String(vrijeme[28]) + "_" + String(vrijeme[29]);
   writeData(fdata,1);
  return;
}

/*
void Flash_Text(String flash) {
  delay(500);
  String oneLine = flash;
  int str_len = flash.length() + 1;
  char char_array[str_len];
  Incoming_Text.toCharArray(char_array, str_len);
  strcpy(Text[0], char_array);
  int r = 0, t = 0;
  for (int i = 0; i < oneLine.length(); i++)
  {
    if (oneLine.charAt(i) == '_')
    {
      q[t] = oneLine.substring(r, i).toInt();
      r = (i + 1);
      t++;
    }
  }
  int sat = sa[1].toInt();
  int minu = sa[2].toInt();
  int sec = sa[3].toInt();
  CD.start(0, sa[1].toInt(), sa[2].toInt(), sa[3].toInt());
  fdata = sa[1] + "_" + sa[2] + "_" + sa[3];
  return;
}
*/
void handlePage2() {
  Serial.println("GET /ithr");
  server.send(200, "text/html", htmlPage2);
}

void sirena2(){
    starttime = millis();
    endtime = starttime;
Serial.println(rtc);
    Disp.bris();
        Disp.setFont(Droid_Sans_16);
digitalWrite(sirenat, LOW);
    while ((endtime - starttime) <=((String(vrijeme[29]).toInt())*1000)) // do this loop for up to 1000mS
      {
        Disp.drawText(0, 1, rtc);
        Disp.loop();
        endtime = millis();
      }
      Serial.println("gotov while");
      digitalWrite(sirenat, HIGH); 
  }


void sirena1(){
    starttime = millis();
    endtime = starttime;
Serial.println(rtc);
    Disp.bris();
        Disp.setFont(Droid_Sans_16);
digitalWrite(sirenap, LOW);
    while ((endtime - starttime) <=((String(vrijeme[29]).toInt())*1000)) // do this loop for up to 1000mS
      {
        Disp.drawText(0, 1, rtc);
        Disp.loop();
        endtime = millis();
      }
      Serial.println("gotov while");
      digitalWrite(sirenap, HIGH); 
  }
String getParam(String name) {
  //read parameter from server, for customhmtl input
  String value;
  if (wm.server->hasArg(name)) {
    value = wm.server->arg(name);
  }
  return value;
}
void saveParamCallback() {
  Serial.println("[CALLBACK] saveParamCallback fired");
  Serial.println("PARAM customfieldid = " + getParam("customfieldid"));
}
void readData(int a)
{
  Serial.println(a);
  if(a==0){
  File file2 = SPIFFS.open("/vremea.txt", "r");
  if (!success) {
    Serial.println("Error mounting the file system");
    return;
    if (!file2) {
      Serial.println("Failed to open file for reading");
      return;
    }
  }
  String oneLine;
  String first_line = file2.readStringUntil('\n');
  file2.close();
  oneLine = first_line + "_";
  delay(500);
  //Serial.println(first_line);
  int str_len = oneLine.length() + 1;
  char char_array[str_len];
  Incoming_Text.toCharArray(char_array, str_len);
  int r = 0, t = 0;
  for (int i = 0; i < oneLine.length(); i++)
  {
    if (oneLine.charAt(i) == '_')
    {
      sa[t] = oneLine.substring(r, i);
      r = (i + 1);
      t++;
    }
  }
  int sat = sa[1].toInt();
  int minu = sa[2].toInt();
  int sec = sa[3].toInt();
  //Serial.println("readdata");
  //Serial.println(sa[1]);
  //  Serial.println(sa[2]);
    //  Serial.println(sa[3]);
  CD.start(0, sa[1].toInt(), sa[2].toInt(), sa[3].toInt());
  pocetak = 1;
  
  return;
  }
    if(a==1){
  File file2 = SPIFFS.open("/tablica.txt", "r");
  if (!success) {
    Serial.println("Error mounting the file system");
    return;
    if (!file2) {
      Serial.println("Failed to open file for reading");
      return;
    }
  }
  String oneLine;
  Serial.println("oneLine");
  Serial.println(oneLine);
  String first_line = file2.readStringUntil('\n');
  file2.close();
  oneLine = first_line + "_";
  delay(500);
  //Serial.println(first_line);
  int str_len = oneLine.length() + 1;
  char char_array[str_len];
  Incoming_Text.toCharArray(char_array, str_len);
  int r = 0, t = 0;
  for (int i = 0; i < oneLine.length(); i++)
  {
    if (oneLine.charAt(i) == '_')
    {
      vrijeme[t] = oneLine.substring(r, i).toInt();
      r = (i + 1);
      t++;
    }
  }
  fdata = String(vrijeme[1]) + "_" + String(vrijeme[2]) + "_" + String(vrijeme[3]) + "_" + String(vrijeme[4]) + "_" + String(vrijeme[5]) + "_" + String(vrijeme[6]) + "_" + String(vrijeme[7]) + "_" + String(vrijeme[8]) + "_" + String(vrijeme[9]) + "_" + String(vrijeme[10]) + "_" + String(vrijeme[11]) + "_" + String(vrijeme[12]) + "_" + String(vrijeme[13]) + "_" + String(vrijeme[14]) + "_" + String(vrijeme[15]) + "_" + String(vrijeme[16]) + "_" + String(vrijeme[17]) + "_" + String(vrijeme[18]) + "_" + String(vrijeme[19]) + "_" + String(vrijeme[20]) + "_" + String(vrijeme[21]) + "_" + String(vrijeme[22]) + "_" + String(vrijeme[23]) + "_" + String(vrijeme[24]) + "_" + String(vrijeme[25]) + "_" + String(vrijeme[26]) + "_" + String(vrijeme[27]) + "_" + String(vrijeme[28]) + "_" + String(vrijeme[29]);

  //Serial.println("readdata");
  //Serial.println(sa[1]);
  //  Serial.println(sa[2]);
    //  Serial.println(sa[3]);
  CD.start(0, sa[1].toInt(), sa[2].toInt(), sa[3].toInt());
  pocetak = 1;
  
  return;
  }
}

void deleteData()
{
  //Remove the file
  SPIFFS.remove("/vremea.txt");
}

void setup() {
  pinMode(sirenat, OUTPUT);
  pinMode(sirenap, OUTPUT);
  pinMode(sirenaq, OUTPUT);
  digitalWrite(sirenat, HIGH);
  digitalWrite(sirenaq, HIGH);
  digitalWrite(sirenap, HIGH);
  h=0;
  ass=1;
  zapiss=0;
  temp[1]="0";
temp[2]="0";
  //deleteData();
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  delay(3000);
  //Serial.println("\n Starting");
  pinMode(TRIGGER_PIN, INPUT);
//  wm.resetSettings(); // wipe settings
  if (wm_nonblocking) wm.setConfigPortalBlocking(false);
  int customFieldLength = 40;
  const char* custom_radio_str = "<br/><label for='customfieldid'>Custom Field Label</label><input type='radio' name='customfieldid' value='1' checked> One<br><input type='radio' name='customfieldid' value='2'> Two<br><input type='radio' name='customfieldid' value='3'> Three";
  new (&custom_field) WiFiManagerParameter(custom_radio_str); // custom html input
  wm.addParameter(&custom_field);
  wm.setSaveParamsCallback(saveParamCallback);
  std::vector<const char *> menu = {"wifi", "info", "param", "sep", "restart", "exit"};
  wm.setMenu(menu);
  // set dark theme
  wm.setClass("invert");
  //set static ip
  // wm.setSTAStaticIPConfig(IPAddress(10,0,1,99), IPAddress(10,0,1,1), IPAddress(255,255,255,0)); // set static ip,gw,sn
  // wm.setShowStaticFields(true); // force show static ip fields
  // wm.setShowDnsFields(true);    // force show dns field always
  // wm.setConfigPortalTimeout(86400); // auto close configportal after n seconds
  bool res;
  res = wm.autoConnect("AutoConnectAP", "password"); // password protected ap

  if (!res) {
    Serial.println("Failed to connect or hit timeout");
    // ESP.restart();
  }
  else {
    //if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
    ser = 1;
    timeClient.begin();
        while(!timeClient.update()) {
timeClient.forceUpdate();
}
formattedDate = timeClient.getFormattedDate();
int splitT = formattedDate.indexOf("T");
monthStamp = formattedDate.substring(5, 7);
dayStamp=formattedDate.substring(8, 10);
if(monthStamp.toInt()>=10 || monthStamp.toInt()<=3){
  if(monthStamp.toInt()==10 && dayStamp.toInt()>=30){
    timeClient.setTimeOffset(3600);
    timeClient.forceUpdate();
  }
  else if(monthStamp.toInt()==3 && dayStamp.toInt()<=26){
    timeClient.setTimeOffset(3600);
    timeClient.forceUpdate();
  }
  else if(monthStamp.toInt()!=10 && monthStamp.toInt()!=4){
    timeClient.setTimeOffset(3600);
    timeClient.forceUpdate();
  }
}
    //

    //----------------------------------------DMDESP Setup
    Disp.start(); //--> Run the DMDESP library
    Disp.setBrightness(1); //--> Brightness level
//    Disp.setFont(Droid_Sans_24); //--> Determine the font used
    //----------------------------------------
    IPAddress apip = WiFi.softAPIP(); //--> Get the IP server
    Serial.print("Connect your wifi laptop/mobile phone to this NodeMCU Access Point : ");
    Serial.println(ssid);
    Serial.print("Visit this IP : ");
    Serial.print(apip); //--> Prints the IP address of the server to be visited
    Serial.println(" in your browser.");
    server.on("/", handleRoot); //--> Routine to handle at root location. This is to display web page.
    server.on("/ithr", handlePage2);    
    server.on("/setText", handle_Incoming_Text);  //--> Routine to handle handle_Incoming_Text Subroutines
    server.begin(); //--> Start server
    Serial.println("HTTP server started");
    while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
      delay(500);
      Serial.print('.');
    }
    Serial.println('\n');
    Serial.println("Connection established!");
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP());
    //readData();
    // deleteData();
        dht.begin();
         t = dht.readTemperature();
     // CD.start(0, 1, 2, 1);

  }
}

void loop() {
    Serial.println("1 i 2");

  Serial.println(vrijeme[1]);
  Serial.println(vrijeme[2]);
  Serial.println("3i 4");
  Serial.println(vrijeme[3]);
  Serial.println(vrijeme[4]);
    if ( pocetak==0){
      pocetak=1;
    readData(0);
    readData(1);
    }

currentMilliss = millis();

if (currentMilliss - previousMilliss > intervall) {
 previousMilliss = currentMilliss;
 t = dht.readTemperature();

}
    
currentMillis = millis();
if (currentMillis - previousMillis > interval) {
 previousMillis = currentMillis;
if(timeClient.getMinutes()==55||timeClient.getMinutes()==45||timeClient.getMinutes()==35||timeClient.getMinutes()==25||timeClient.getMinutes()==15||timeClient.getMinutes()==5){
  if(timeClient.getSeconds()==0){
Serial.println("==0");
    }
  }
 if(timeClient.getSeconds()==1||timeClient.getSeconds()==5||timeClient.getSeconds()==11||timeClient.getSeconds()==15||timeClient.getSeconds()==21||timeClient.getSeconds()==25||timeClient.getSeconds()==31||timeClient.getSeconds()==35||timeClient.getSeconds()==41||timeClient.getSeconds()==45||timeClient.getSeconds()==51||timeClient.getSeconds()==55){
  Disp.bris();
  
  }
  //sirena takta
if(CD.remaining()==300){
  sirena2();
  }
if(CD.remaining()==60){
  sirena2();
  }
  if(CD.remaining()==0){
  sirena2();
  }
  
   //prva smjena
  //pocetak prve,kraj druge
  if ((timeClient.getHours() == vrijeme[1] && timeClient.getMinutes() == vrijeme[2] && timeClient.getSeconds()==0)||(timeClient.getHours() == vrijeme[3] && timeClient.getMinutes() == vrijeme[4] && timeClient.getSeconds()==0)) {
    Serial.println("1");
    sirena1();
    }
    //prva,druga pauza početak
  if ((timeClient.getHours() == vrijeme[7] && timeClient.getMinutes() == vrijeme[8] && timeClient.getSeconds()==0)||(timeClient.getHours() == vrijeme[13] && timeClient.getMinutes() == vrijeme[14] && timeClient.getSeconds()==0)) {
    if (ass == 1) {
      ass = 0;
      CD.stop();
      Serial.println("2");
    sirena1();
    }
  }
  if(timeClient.getSeconds()==30){
    ass=1;
    }
    //prva druga pauza kraj
  if ((timeClient.getHours() == vrijeme[19] && timeClient.getMinutes() == vrijeme[20] && timeClient.getSeconds()==0)||(timeClient.getHours() == vrijeme[25] && timeClient.getMinutes() == vrijeme[26] && timeClient.getSeconds()==0)) {
    CD.cont();
    Serial.println("3");
    sirena1();
  }
  
// druga smjena
//kraj druge pocetak trece
  if (timeClient.getHours() == vrijeme[5] && timeClient.getMinutes() == vrijeme[6] && timeClient.getSeconds()==0) {
    Serial.println("4");
    sirena1();
    }
    //pocetak pauza 2.sm
  if (timeClient.getHours() == vrijeme[15] && timeClient.getMinutes() == vrijeme[16] && timeClient.getSeconds()==0) {
    if (ass == 1) {
      ass = 0;
      CD.stop();
      Serial.println("5");
    sirena1();
    }
  }
  if(timeClient.getSeconds()==30){
    ass=1;
    }
    //kraj pauza 2.sm
  if (timeClient.getHours() == vrijeme[21] && timeClient.getMinutes() == vrijeme[22] && timeClient.getSeconds()==0) {
    CD.cont();
    Serial.println("6");
    sirena1();
  }

// treca smjena
    //pocetak pauza 3.sm
  if (timeClient.getHours() == vrijeme[11] && timeClient.getMinutes() == vrijeme[12] && timeClient.getSeconds()==0) {
    if (ass == 1) {
      ass = 0;
      CD.stop();
      Serial.println("7");
    sirena1();
    }
  }
  if(timeClient.getSeconds()==30){
    ass=1;
    }
    //kraj pauza 3.sm
  if (timeClient.getHours() == vrijeme[17] && timeClient.getMinutes() == vrijeme[18] && timeClient.getSeconds()==0) {
    CD.cont();
    Serial.println("8");
    sirena1();
  }  
}
  Disp.loop(); //--> Run "Disp.loop" to refresh the LED

  if (wm_nonblocking) wm.process(); // avoid delays() in loop when non-blocking and other long running code
  wm.process();
  timeClient.update();
  server.handleClient();  //--> Handle client requests
  static uint32_t last_remaining = 0;
  if(!isnan(t) && int(t)>0){
  int h = t;
  }

  // Read temperature as Celsius (the default)
  //t = dht.readTemperature();
 /* if ( isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }*/

  if (last_remaining != CD.remaining() || CD.remaining() == 0 )
  {
    last_remaining = CD.remaining();
  }
  hr = CD.remaining() / 3600;
  miin = (CD.remaining() / 60) % 60;
  sec = (CD.remaining() % 60);
  String sa;
  String sek;
  String mi;

  if (hr < 10) {
    sa = String(hr);
    sa = "0" + sa;
  }
  else {
    sa = String(hr);
  }
  if (miin < 10) {
    mi = String(miin);
    mi = "0" + mi;
  }
  else {
    mi = String(miin);
  }
  if (sec < 10) {
    sek = String(sec);
    sek = "0" + sek;
  }
  else {
    sek = String(sec);
  }

  String asd = sa + ":" + mi + ":" + sek;
  String sat = String(timeClient.getHours());
  String minute = String(timeClient.getMinutes());
  String sekunde = String(timeClient.getSeconds());
  String spremanje = sa + "_" + mi + "_" + sek;



     
    if(timeClient.getSeconds()==50 ){
        zapiss=0;
     }


  if (timeClient.getHours() < 10) {
    sat = "0" + String(timeClient.getHours());
  }
  if (timeClient.getMinutes() < 10) {
    minute = "0" + String(timeClient.getMinutes());
  }
  if (timeClient.getSeconds() < 10) {
    sekunde = "0" + String(timeClient.getSeconds());
  }
  rtc = sat + ":" + minute + ":" + sekunde;

 // Arial14
   Disp.setFont(Droid20);

 // Disp.setFont(Droid_Sans_16);
  Disp.drawText(0, 1, rtc);
 // Disp.drawText(0, 1, "SADFSDFSDF");

      //----------------Disp.drawText(0, 1, String(timeClient.getSeconds()));
  Disp.drawText(128, 2, rtc);
  Disp.setFont(Droid_Sans_12);
  //Scrolling_Text(0, 50); //--> Show running text "Scrolling_Text(y position, speed);"
  static uint32_t pM;
  static uint32_t x;
  int y =29;
  uint8_t scrolling_speed=50;
  int width = Disp.width();
//  Disp.setFont(Droid_Sans_12);
  int fullScroll = Disp.textWidth(Text[0]) + width;
  if ((millis() - pM) > scrolling_speed) {
    pM = millis();
    if (x < fullScroll) {
      ++x;
    } else {
      x = 0;
      return;
    }
    Disp.drawText(width - x, y, Text[0]);
  }
  if(isnan(t)){
    //Serial.println(h);
    //Serial.println("h");
      Disp.setFont(Droid20);
    Disp.drawText(88, 2, String(int(h)-temp[1].toInt()+temp[2].toInt())+"C");
        Disp.drawText(216, 2, String(int(h)-temp[1].toInt()+temp[2].toInt())+"C");

    }
    else if(!isnan(t)){
        Disp.setFont(Droid20);

      Disp.drawText(88, 2, String(int(t)-temp[1].toInt()+temp[2].toInt())+"C");    
            Disp.drawText(216, 2, String(int(t)-temp[1].toInt()+temp[2].toInt())+"C");    
      }
        Disp.setFont(Droid20);
       //  Disp.drawText(0, 43, asd);
       //  Disp.drawText(128, 43, asd);   
}
//========================================================================


void handle_Incoming_Text() {
  Incoming_Text = server.arg("TextContents");
  server.send(200, "text/plane", ""); //--> Send web page
  Process_Incoming_Text();
}
void Process_Incoming_Text() {
  //deleteData();
  delay(500);

  char str2[] = "t";
  char str[] = "s";
  char str3[] = "k";
    char str4[] = "p";
  String oneLine = Incoming_Text;
  int str_len = Incoming_Text.length() + 1;
  char aarray[str_len];
  // char char_array[str_len];
  //Incoming_Text.toCharArray(char_array, str_len);
  //  strcpy(Text[0], char_array);
    Serial.println(strncmp(aarray, str, 1));

  Serial.println(strncmp(aarray, str2, 1));

  Serial.println(strncmp(aarray, str3, 1));
 Serial.println(strncmp(aarray, str4, 1));
  int r = 0, t = 0;
  //char texxt[str_len];
  strcpy(aarray, oneLine.c_str());

  if (strncmp(aarray, str3, 1) == 0) {
    vremena(Incoming_Text);
  }

  //Takt
  else if (strncmp(aarray, str, 1) == 0) {

    for (int i = 0; i < oneLine.length(); i++)
    {
      if (oneLine.charAt(i) == '_')
      {
        sa[t] = oneLine.substring(r, i);
        r = (i + 1);
        t++;
        delay(1000);
      }
    }
  //  Serial.println("process");
   // Serial.println(sa[0]+"_"+sa[1]+"_"+sa[2]+"_"+sa[3]);
    writeData(sa[0]+"_"+sa[1]+"_"+sa[2]+"_"+sa[3],0);
    CD.start(0, sa[1].toInt(), sa[2].toInt(), sa[3].toInt());
  }

  //srednji red displaya
  else if (strncmp(aarray, str2, 1) == 0) {
    //listAllFiles();
  String oneLLine = Incoming_Text;
  int str_len = Incoming_Text.length() +1;
  char aarray[str_len];
  int r = 0, t = 0;
  //char texxt[str_len];
  strcpy(aarray, oneLLine.c_str());
            strcpy(Text[0], oneLLine.c_str());
    memmove(Text[0],Text[0]+2,strlen(Text[0]));
    data=oneLLine;
    Serial.println("ADKSJUHASKDFJSDUFH");
    String str(oneLLine);
    char str_array[str.length()];
    str.toCharArray(str_array, str.length());
/*    strcpy(Text[0], oneLLine.c_str());
    data=oneLLine;
    Serial.println(oneLLine.c_str());
    String str(oneLLine);
    char str_array[str.length()];
str.toCharArray(str_array, str.length());
        Serial.println(Text[0]);
    Serial.println("1");

char str_array[str.length()];
str.toCharArray(str_array, str.length());
    Serial.println(Text[0]);
    Serial.println("2");
*/
    Serial.println("srednji red");
  }
  //temp
  else if (strncmp(aarray, str4, 1) == 0) {
    for (int i = 0; i < oneLine.length(); i++)
    {
      if (oneLine.charAt(i) == '_')
      {
        temp[t] = oneLine.substring(r, i);
        r = (i + 1);
        t++;
        delay(1000);
      }
  }
}
}
void handleRoot() {
  server.send(200, "text/html", MAIN_page); //--> Send web page
}

void writeData(String data, int dr)
{
      Serial.println(dr);

 // deleteData();
 // Serial.println("data");
 // Serial.println(data);
if (dr==0){
  SPIFFS.remove("/vremea.txt");
  if (!success) {
    Serial.println("Error mounting the file system");
    return;
  }
  File file = SPIFFS.open("/vremea.txt", "w");
  if (!file) {
    Serial.println("Error opening file for writing");
    file.close();
    return;
  }

  int bytesWritten = file.print(data);
  if (bytesWritten == 0) {
    Serial.println("File write failed");
    return;
  }
  else if (bytesWritten > 0) {
    file.flush();
  }
  file.close();}
  
  if (dr==1){
    SPIFFS.remove("/tablica.txt");
  if (!success) {
    Serial.println("Error mounting the file system");
    return;
  }
  File file = SPIFFS.open("/tablica.txt", "w");
  if (!file) {
    Serial.println("Error opening file for writing");
    file.close();
    return;
  }
Serial.println("data");
Serial.println(data);
  int bytesWritten = file.print(data);
  if (bytesWritten == 0) {
    Serial.println("File write failed");
    return;
  }
  else if (bytesWritten > 0) {
    file.flush();
  }
  file.close();}
}
//========================================================================Subroutines for scrolling Text
void Scrolling_Text(int y, uint8_t scrolling_speed) {
  static uint32_t pM;
  static uint32_t x;
  int width = Disp.width();
  Disp.setFont(Droid_Sans_12);
  int fullScroll = Disp.textWidth(Text[0]) + width;
  if ((millis() - pM) > scrolling_speed) {
    pM = millis();
    if (x < fullScroll) {
      ++x;
    } else {
      x = 0;
      return;
    }
    Disp.drawText(width - x, y, Text[0]);
  }
}
