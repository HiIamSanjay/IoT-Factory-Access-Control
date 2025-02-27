#define BLYNK_TEMPLATE_ID "TMPL33sqafsV-"
#define BLYNK_TEMPLATE_NAME "test"
#define BLYNK_AUTH_TOKEN "keQo5OckLh0Z7ruWY_1xfkjoSo4IB7Af"
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <Stepper.h>
#define STEPS_PER_REVOLUTION 1024
#define ledPin 22
#define buzzerPin 23
//                                    IN1,IN2,IN3,IN4
Stepper stepper1(STEPS_PER_REVOLUTION, 18, 12, 19, 13);  // Motor 1
Stepper stepper2(STEPS_PER_REVOLUTION, 5, 14, 21, 4);    // Motor 2

char auth[] = "keQo5OckLh0Z7ruWY_1xfkjoSo4IB7Af";
char ssid[] = "";
char pass[] = "";
WidgetTerminal terminal(V1);
BLYNK_WRITE(V2) {
  int pinValue = param.asInt();  // Assigning incoming value from pin V1 to a variable
  for (int i = 0; i != 3; i++) {
    if (pinValue == 1) {
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      delay(500);
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      delay(500);
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
    }
  }
}
// WidgetTerminal terminal(V1);
BLYNK_WRITE(V1) {
  if (String("Y22RA044") == param.asStr()) {
    terminal.println("Welcome Sanjay K S");
    terminal.println("Authorised");
    openCloseGates();
  }
  if (String("Y22RA043") == param.asStr()) {
    terminal.println("Welcome Sager Binsal");
    terminal.println("Authorised");
    openCloseGates();
  }
  if (String("Y22RA039") == param.asStr()) {
    terminal.println("Welcome Rishi A");
    terminal.println("Authorised");
    openCloseGates();
  }
  if (String("Y22RA004") == param.asStr()) {
    terminal.println("Welcome Adithya R Pai");
    terminal.println("Authorised");
    openCloseGates();
  }
  if (String("Y22RA001") == param.asStr()) {
    terminal.println("Welcome Aashna Bhai");
    terminal.println("Authorised");
    openCloseGates();
  } else {
    terminal.println("Unauthorised");
  }
}
void openCloseGates() {
  stepper1.step(STEPS_PER_REVOLUTION);
  stepper2.step(-STEPS_PER_REVOLUTION);
  delay(500);
  stepper1.step(-STEPS_PER_REVOLUTION);
  stepper2.step(STEPS_PER_REVOLUTION);
}
BLYNK_WRITE(V3){
    int pinValue = param.asInt();
    if(pinValue==-1){
      stepper1.step(-STEPS_PER_REVOLUTION);
    }
    if(pinValue==1){
      stepper1.step(STEPS_PER_REVOLUTION);
    }
}
BLYNK_WRITE(V4){
    int pinValue = param.asInt();
    if(pinValue==-1){
      stepper2.step(-STEPS_PER_REVOLUTION);
    }
    if(pinValue==1){
      stepper2.step(STEPS_PER_REVOLUTION);
    }
}
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  terminal.clear();
  terminal.println(F("Please Enter Your Employee ID "));
  terminal.flush();
  stepper1.setSpeed(20);
  stepper2.setSpeed(20);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}
void loop() {
  Blynk.run();
}