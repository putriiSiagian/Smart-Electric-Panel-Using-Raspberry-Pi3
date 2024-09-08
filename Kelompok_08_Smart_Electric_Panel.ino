#include <ThingerESP8266.h>
#include <ESP8266WiFi.h>

#define USERNAME "benhoven29"
#define DEVICE_ID "Smart-Panel"
#define DEVICE_CREDENTIAL "kelompok08"
#define SSID "naek"
#define PASSWORD "benhoven"

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

const int relayPin1 = D1;
const int relayPin2 = D2;
const int relayPin3 = D3;
const int relayPin4 = D4;
const int relayPin5 = D5;
const int relayPin6 = D6;
const int relayPin7 = D7;
const int relayPin8 = D8;

// void scheduleRelay(const String & onTime, const String & offTime) {
//     // Logika untuk menghidupkan/mematikan relay sesuai jadwal
//     Serial.println("Waktu Nyala: " + onTime);
//     Serial.println("Waktu Mati: " + offTime);

//     // Contoh logika sederhana untuk menghidupkan relay
//     digitalWrite(relayPin1, HIGH); // Hidupkan relay
//     delay(5000); // Uji coba selama 5 detik
//     digitalWrite(relayPin1, LOW); // Matikan relay
// }

void setup() {
    // Initialize Serial for debugging
    Serial.begin(115200);

    // Initialize WiFi connection
    WiFi.begin(SSID, PASSWORD);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" WiFi connected");

    // Set relay pins as output
    pinMode(relayPin1, OUTPUT);
    pinMode(relayPin2, OUTPUT);
    pinMode(relayPin3, OUTPUT);
    pinMode(relayPin4, OUTPUT);
    pinMode(relayPin5, OUTPUT);
    pinMode(relayPin6, OUTPUT);
    pinMode(relayPin7, OUTPUT);
    pinMode(relayPin8, OUTPUT);

    // Initialize Thinger.io
    thing.add_wifi(SSID, PASSWORD);
    
    // Menghubungkan relay dengan Thinger.io
    thing["relay1"] << digitalPin(relayPin1);
    thing["relay2"] << digitalPin(relayPin2);
    thing["relay3"] << digitalPin(relayPin3);
    thing["relay4"] << digitalPin(relayPin4);
    thing["relay5"] << digitalPin(relayPin5);
    thing["relay6"] << digitalPin(relayPin6);
    thing["relay7"] << digitalPin(relayPin7);
    thing["relay8"] << digitalPin(relayPin8);

//     // Mengatur jadwal berdasarkan input dari antarmuka
//     thing["schedule"] >> [](protoson::pson & data) {
//         String onTime = data["on"];
//         String offTime = data["off"];
//         scheduleRelay(onTime, offTime);
//     };
// }

void loop() {
    thing.handle();
}
