#define TRIG_PIN 10
#define ECHO_PIN 9
#define buzzer 3

const int PULSE_WIDTH = 10; // Microseconds to send trigger pulse

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(PULSE_WIDTH);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  float distance_cm = duration * 0.034 / 2; // Speed of sound in cm/us / 2 (round trip)

  if (distance_cm > 0 && distance_cm <= 400) {
    Serial.print("Distance (cm): ");
    Serial.println(distance_cm);
  } else {
    Serial.println("Object out of range or sensor error.");
  }

if (distance_cm < 20){
  digitalWrite(buzzer, HIGH);
  delay(100);
  digitalWrite(buzzer, LOW);
  delay(100);
}
else if(distance_cm >20 && distance_cm < 60){
   digitalWrite(buzzer, HIGH);
  delay(500);
  digitalWrite(buzzer, LOW);
  delay(500);
}
else if(distance_cm >60 && distance_cm < 200){
   digitalWrite(buzzer, HIGH);
  delay(700);
  digitalWrite(buzzer, LOW);
  delay(700);
}
else{
   digitalWrite(buzzer, HIGH);
  delay(1000);
  digitalWrite(buzzer, LOW);
  delay(1000);
}
  delay(100);
}
