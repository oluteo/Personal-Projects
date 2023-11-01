/*
 * DJ Oluteo
 * Complete Project Details http://randomnerdtutorials.com
 */

// Load required libraries
#include <WiFi.h>

#include <Wire.h>
#include <HCSR04.h>

// Replace with your network credentials
const char* ssid     = "free wifi password is 12345678";
const char* password = "12345678";



int triggerPin = 21;
int echoPin = 12;


// Web page file stored on the SD card
File webFile; 




// variables to store distance readings
double distances;
// Variable to store the HTTP request
String header;

// Set web server port number to 80
WiFiServer server(80);

void setup(){    
  // initialize serial port
  Serial.begin(115200); 
  
// initialize ultrasonic sensor
  HCSR04.begin(triggerPin, echoPin);



  // Connect to Wi-Fi network with SSID and password
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();


   
  
  
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {  // if new client connects
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {   // client data available to read
        char c = client.read(); // read 1 byte (character) from client
        header += c;
        // if the current line is blank, you got two newline characters in a row.
        // that's the end of the client HTTP request, so send a response:
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          // Send XML file or Web page
          // If client already on the web page, browser requests with AJAX the latest
          // sensor readings (ESP32 sends the XML file)
          if (header.indexOf("update_readings") >= 0) {
            // send rest of HTTP header
            client.println("Content-Type: text/xml");
            client.println("Connection: keep-alive");
            client.println();
            // Send XML file with sensor readings
            sendXMLFile(client);
          }
          // When the client connects for the first time, send it the index.html file
          // stored in the microSD card
          else {  
            // send rest of HTTP header
            client.println("Content-Type: text/html");
            client.println("Connection: keep-alive");
            client.println();
            // send web page stored in microSD card
            webFile = open("/index.html");
            if (webFile) {
              while(webFile.available()) {
                // send web page to client
                client.write(webFile.read()); 
              }
              webFile.close();
            }
          }
          break;
        }
        // every line of text received from the client ends with \r\n
        if (c == '\n') {
          // last character on line of received text
          // starting new line with next character read
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // a text character was received from client
          currentLineIsBlank = false;
        }
        } // end if (client.available())
    } // end while (client.connected())
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
  } // end if (client)
}

// Send XML file with the latest sensor readings
void sendXMLFile(WiFiClient cl){
  // Read DHT sensor and update variables
  

  // Prepare XML file
  cl.print("<?xml version = \"1.0\" ?>");
  cl.print("<inputs>");

   distances= HCSR04.measureDistanceCm();
  cl.print("<reading>");
  cl.print(distances);
  cl.println("</reading>");
  
  
  cl.print("</inputs>");
}
delay(100);


  /*Serial.print("Humidity: ");
  Serial.print(humi);
  Serial.print(" %\t Temperature: ");
  Serial.print(tempC);
  Serial.print(" *C ");
  Serial.print(tempF);
  Serial.println(" *F");*/
}
