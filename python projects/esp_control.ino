//#include <ESP8266WiFi.h>
#include <WiFi.h>
const char* ssid = "nostop";
const char* Password = "8243";
int relay = 2;
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin (115200);
  pinMode (relay, OUTPUT);
  digitalWrite (relay, LOW);
  Serial.print ("connecting to network");
  WiFi.begin (ssid, Password);
  while (WiFi.status() != WL_CONNECTED) {
    delay (500);
    Serial.print("please buy data (SAPA)");
  }

  Serial.println ("Wifi connected");
  server.begin ();
  Serial.println("Server started");
  Serial.print("IP address of network:");

  Serial.println(WiFi.localIP());
  Serial.print("/");

}

void loop() {
  // put your main code here, to run repeatedly:
  WiFiClient client = server.available ();
  if (!client) {
    return;
  }
  Serial.println("Waiting for new client");
  while (!client.available ()) {
    delay(1);
  }
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
  int value = LOW;
  if (request.indexOf("/relay=ON") != -1)
  {
    digitalWrite (relay, HIGH);
    value = HIGH;
  }
  if (request.indexOf("/relay=OFF") != -1)
  {
    digitalWrite (relay, LOW);
    value = LOW;
  }
  client.println("HTTP / 1.1 200 OK");
  client.println("Connect-Type: text/html");
  client.println("");
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println(" CONTROL LED");
  if (value == HIGH) {
    client.print("ON");
  }
  else {
    client.print("OFF");
  }
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"\"><button>ON</button></a>");
  client.println("<a href=\"/LED=OFF\"\"><button>OFF</button></a><br/>");
  client.println("</html>");
  delay(1);
  Serial.println("client disconnected");
  Serial.println("");
}
