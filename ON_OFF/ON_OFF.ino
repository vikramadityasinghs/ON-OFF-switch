#include<ESP8266WebServer.h>  
ESP8266WebServer server;
const char username[]="train";
const char password[]="padhlokuch";
#define pin 16
void setup()
{pinMode(pin,OUTPUT);
Serial.begin(115200);

WiFi.softAP(username,password);//create access point
Serial.println('connected');
IPAddress myIP=WiFi.softAPIP();
Serial.print("AP IP address: ");
Serial.println(myIP);
server.begin();
server.on("/led",led);
//server.on("/check",check);
}
void loop()
{server.handleClient();
}
void led()
{String myhtml="\n"
"<html>\n"
"    <head>\n"
"        <style>\n"
"            button {\n"
"              background-color:white;\n"
"              border: black;\n"
"              color:yellowgreen;\n"
"              padding: 15px 32px;\n"
"              text-align: center;\n"
"              text-decoration: none;\n"
"              display: inline-block;\n"
"              font-size: 16px;\n"
"              margin: 100px 50px;\n"
"              cursor: pointer;\n"
"            }\n"
"            </style>\n"
"        <title>Program</title>\n"
"    </head>\n"
"    <body style=\"background-color:lavender\"><center>\n"
"        <h1><centre><b>TASK : SWTICH</b></centre></h1>\n"
"        <form>What do you want to do?<br>\n"
"          \n"
"        \n"
"            <button type=\"submit\" name=\"state\" value=\"1\">ON</button>\n"
"     \n"
"            <button type=\"submit\" name=\"state\" value=\"0\">OFF</button>\n"
"        \n"

"</center>  \n"
"    </form>\n"
"    </body>\n"
"                 \n"
" </html>";
   server.send(200,"text/html",myhtml);
   if(server.arg("state")=="1")
    {
      digitalWrite(pin,HIGH);
    }
    else
    {
      digitalWrite(pin,LOW);
    }
}
