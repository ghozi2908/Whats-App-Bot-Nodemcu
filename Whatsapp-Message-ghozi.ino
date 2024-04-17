/*====CARA PAKENYA====
1. Install Library callmebotesp8266 di Arduino IDE
2. copy api key, link tutor: https://www.callmebot.com/blog/free-api-whatsapp-messages/
3. Ganti SSID, PASS, PHONE NUMBER, API sesuai perangkat mu
4. done

Contect : Ghozi Yusuf Matdoan
+6285776254687
Github : ghozi2908
Portofolio : https://portofolio-ghozi-yusuf-matdoan.web.app/
*/


#include <ESP8266WiFi.h>
#include <Callmebot_ESP8266.h>

const char* ssid = "Devices"; //ganti dengan jaringan wifi mu
const char* password = "87654321"; //masukkan passwordnya

const int umur = 20;
float nilai = 99.9;

String phoneNumber = "+6285959950845"; //ganti dengan nomor tujuan
String apiKey = "6139433"; //Ganti dengan apikey yang didapat
String message;

void setup() {
	Serial.begin(115200);
	WiFi.begin(ssid, password);
	Serial.println("Connecting");
	while(WiFi.status() != WL_CONNECTED) {
		delay(500);
		Serial.print(".");
	}
	Serial.println("");
	Serial.print("Connected to WiFi network with IP Address: ");
	Serial.println(WiFi.localIP());

	Callmebot.begin();

}

void loop() {
	// Whatsapp Message
  message = (String)"Nama : Ghozi Yusuf Matdoan" + "\n" +
  (String)"Umur : " + String(umur) + (String)"Tahun" + "\n" +
  (String)"Nilai : " + String(nilai) + (String)" %" + "\n";
	Callmebot.whatsappMessage(phoneNumber, apiKey, message);
	Serial.println(Callmebot.debug());
  delay(3000);
}