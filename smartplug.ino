#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

String webpage = "<H1><align=\"center\">BELAJAR <br>NodeMCU Web Server</H1><p><a href=\"ON\"><button>ON</button></a>&nbsp;<a href=\"OFF\"><button>OFF</button></a></p>";

void setup() {
  Serial.begin(9600);// put your setup code here, to run once:
  pinMode(D4, OUTPUT);

  WiFi.begin("SmartPlug", "11110000");

  Serial.print("Nyambung");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Nyambung, IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", [](){
    server.send(200, "text/html", webpage);
  });
  server.on("/ON", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D4, HIGH);
  });
  server.on("/OFF", [](){
    server.send(200, "text/html", webpage);
    digitalWrite(D4, LOW);
  });
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
