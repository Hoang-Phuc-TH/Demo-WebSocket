
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"

#define BLYNK_TEMPLATE_ID "TMPL6NfXKTu89"
#define BLYNK_TEMPLATE_NAME "Button"
#define BLYNK_AUTH_TOKEN "oNzzdVrbKtpQoAM_BbnPBGFOXWPevQP0"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "oNzzdVrbKtpQoAM_BbnPBGFOXWPevQP0";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "NIGHT";
char pass[] = "saomachoduoc@?";

#define led1 D1
#define led2 D2
#define led3 D3
// #define button1 D2
// #define button2 D2
// #define button3 D2
boolean bt_state = HIGH;

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  Blynk.begin(auth, ssid, pass);
}
void loop() {
  Blynk.run();
}
BLYNK_WRITE(V1) {
  int p = param.asInt();
  digitalWrite(led1, p);
}
BLYNK_WRITE(V2) {
  int p = param.asInt();
  digitalWrite(led2, p);
}
BLYNK_WRITE(V3) {
  int p = param.asInt();
  digitalWrite(led3, p);
}

// void check_button(int button,int led)
// {
//   if(digitalRead(button)==LOW)
//   {
//     if(bt_state==HIGH)
//     {
//       digitalWrite(led,!digitalRead(led));
//       Blynk.virtualWrite(V1,digitalRead(led));
//       bt_state=LOW;
//       delay(1000);
//     }
//   }
//   else
//   {
//     bt_state=HIGH;
//   }
// }
