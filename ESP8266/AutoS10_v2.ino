#include <ESP8266WiFi.h>

const char* ssid = "IEEE_UEFS";
const char* password = "ramoIEEEUEFS";

int toggleD3=0;
int toggleD4=0;
int toggleD2=0;
int toggleD1=0;

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void acLigaDesliga(){
  //TODO: Implementar os codigos de liga/desliga do ar-condicionado
}

void acTemp(boolean mais){
  //TODO: Implementar os codigos de aumento ou diminuição de temperatura de acordo com o parametro
}

void setup() {
  Serial.begin(115200);
  delay(10);

  // preparando portas de relays
  pinMode(D4, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D1, OUTPUT);
  digitalWrite(D4, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D1, LOW);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
  if (req.indexOf("/gpio/0") != -1)
    toggleD3 = !toggleD3;
  else if (req.indexOf("/gpio/1") != -1)
    toggleD4 = !toggleD4;
  else if (req.indexOf("/gpio/2") != -1)
    toggleD2 = !toggleD2;
  else if (req.indexOf("/cafe/0") != -1)
    toggleD1 = !toggleD1;
  else if (req.indexOf("/ac/0") != -1)
    acLigaDesliga();
  else if (req.indexOf("/ac/1") != -1)
    acTemp(true);
  else if (req.indexOf("/ac/2") != -1)
    acTemp(false);
    
  

String page = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"
"<!DOCTYPE html>"
"<html>"
"<head>"
"    <meta charset=\"utf-8\" />"
"    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">"
"    <title>-= S10 - IEEE - Controle de Aparelhos =-</title>"
"    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"
"</head>"
"<style>"
"    *{"
"    margin: 0px;"
"    font-family: monospace;"
"}"
".main {"
"    display: flex;"
"    justify-content: center;"
"    align-items: center;"
"    width: 100vw;"
"    height: 100vh;"
"    background-color: #313131;"
"}"
".card {"
"    box-sizing: border-box;"
"    padding: 5px;"
"    display: flex;"
"    flex-direction: column;"
"    align-items: center;"
"    background-color: #383838;"
"    width: 250px;"
"    height: 480px;"
"    overflow: scroll;"
"}"
".card-effect3d{"
"    border-top: 1px solid gray;"
"    border-left: 1px solid gray;"
"    border-bottom: 1px solid black;"
"    border-right: 1px solid black;"
"}"
".btncard{"
"    display: flex;"
"    flex-direction: column;"
"    justify-content: center;"
"    align-items: center;"
"    background-color: #383838;"
"    width: 57px;"
"    height: 80px;"
"}"
".btn{"
"    width: 42px;"
"    height: 42px;"
"    margin: 4px;"
"    border: 1px solid #42f489;"
"    border-radius: 2px;"
"}"
".separator{"
"    box-sizing: border-box;"
"    width: 100%;"
"    margin-top: 15px;"
"    padding-left: 4px;"
"    padding-top: 4px;"
"    border-top: 1px solid gray;"
"    text-align: left;"
"    color: gray;"
"    font-size: 15px;"
"}"
".zone{"
"    box-sizing: border-box;"
"    padding: 8px;"
"    display: flex;"
"    flex-direction: row;"
"    justify-content: center;"
"}"
"</style>"
"<body>"
"    <div class=\"main\">"
"        <div class=\"card card-effect3d\">"
"            <span>"
"                <h1 style=\"color: #42b3f4\">controle_S10</h1>"
"                <p style=\"color: gray; font-size: 8px;\">Página de Controle de recursos físicos do "
"                                                            laboratório de Embarcados S10.</p>"
"                <p style=\"color: gray;   font-size: 8px;\">Recursos: Liga/Desliga luzes, cafeteira "
"                                                            e controla funções básicas do ar-condicionado.</p>"
"            </span>"
"            <!-- zona de luzes -->"
"            <div class=\"separator\">luzes</div>"
"            <div class=\"zone\">"
"                <div class=\"btncard card-effect3d\">"
"                    <span style=\"color: gray\">luz_1</span>"
"                    <a href=\"/gpio/0\" style=\"text-decoration: none;\">"
"                        <div class=\"btn\"></div>"
"                    </a>"
"                </div>"
"                <div class=\"btncard card-effect3d\">"
"                    <span style=\"color: gray\">luz_2</span>"
"                    <a href=\"/gpio/1\">"
"                        <div class=\"btn\"></div>"
"                    </a>"
"                </div>"
"                <div class=\"btncard card-effect3d\">"
"                    <span style=\"color: gray\">luz_3</span>"
"                    <a href=\"/gpio/2\">"
"                        <div class=\"btn\"></div>"
"                    </a>"
"                </div>"
"            </div>"
"            <!-- zona de cafe -->"
"            <div class=\"separator\">café</div>"
"            <div class=\"zone\">"
"                <div class=\"btncard card-effect3d\">"
"                    <span style=\"color: gray\">qro_cafe</span>"
"                    <a href=\"/cafe/0\" style=\"text-decoration: none;\">"
"                        <div class=\"btn\"></div>"
"                    </a>"
"                </div>"
"            </div>"
"            <!-- zona de AC -->"
"            <div class=\"separator\">A.C.</div>"
"            <div class=\"zone\">"
"                <div class=\"btncard card-effect3d\">"
"                    <span style=\"color: gray\">on/off</span>"
"                    <a href=\"/ac/0\" style=\"text-decoration: none;\">"
"                        <div class=\"btn\"></div>"
"                    </a>"
"                </div>"
"                <div class=\"btncard card-effect3d\">"
"                    <span style=\"color: gray\">temp_+</span>"
"                    <a href=\"/ac/1\" style=\"text-decoration: none;\">"
"                        <div class=\"btn\"></div>"
"                    </a>"
"                </div>"
"                <div class=\"btncard card-effect3d\">"
"                    <span style=\"color: gray\">temp_-</span>"
"                    <a href=\"/ac/2\" style=\"text-decoration: none;\">"
"                        <div class=\"btn\"></div>"
"                    </a>"
"                </div>"
"            </div>"
"        </div>"
"    </div>"
"</body>"
"</html>";
  // Send the response to the client
  client.print(page);

  // Set GPIO2 according to the request
  digitalWrite(D4, toggleD4);
  digitalWrite(D3, toggleD3);
  
  client.flush();

  // Send the response to the client
  //client.print(indice);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}

