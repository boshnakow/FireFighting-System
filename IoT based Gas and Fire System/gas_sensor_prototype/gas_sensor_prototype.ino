int sensor_Value;
#define red_led 25
#define orange_led 26
#define yellow_led 27
#define green_led_2 14
#define green_led_1 12
#define mq6 2
#define buzzer 33

void setup()
{
  pinMode(buzzer, OUTPUT);
  pinMode(red_led, OUTPUT);
  pinMode(orange_led, OUTPUT);
  pinMode(yellow_led, OUTPUT);
  pinMode(green_led_2, OUTPUT);
  pinMode(green_led_1, OUTPUT);
  Serial.begin(115200); 
}

void loop()
{
  sensor_Value = analogRead(mq6);
  sensor_Value = map(sensor_Value, 1800, 4095, 0, 100);//Here I re-map a number from one range to another
  Serial.println(sensor_Value); 
  digitalWrite(green_led_1, HIGH);
  digitalWrite(green_led_2, sensor_Value >= 20 ? HIGH : LOW);
  digitalWrite(yellow_led, sensor_Value >= 40 ? HIGH : LOW);
  digitalWrite(orange_led, sensor_Value >= 60 ? HIGH : LOW);
  digitalWrite(red_led, sensor_Value >= 80 ? HIGH : LOW);
  if(red_led, sensor_Value >= 80 ? HIGH : LOW)
  {
    digitalWrite(green_led_1, HIGH);
    digitalWrite(green_led_2, HIGH);
    digitalWrite(yellow_led, HIGH);
    digitalWrite(orange_led, HIGH);
    digitalWrite(red_led, HIGH);
    delay(500);
    digitalWrite(green_led_1, LOW);
    digitalWrite(green_led_2, LOW);
    digitalWrite(yellow_led, LOW);
    digitalWrite(orange_led, LOW);
    digitalWrite(red_led, LOW);
  }
    if(red_led, sensor_Value >= 80 ? HIGH : LOW)
  {
    digitalWrite(buzzer, HIGH); // Here the buzzer is simulated with blinking a blue led
    delay (800);
    digitalWrite(buzzer, LOW);
  }
  else
  {
    digitalWrite(buzzer, LOW);
  }
  delay(250); 
}
