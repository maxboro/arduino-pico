#define INDICATOR_PIN 4
#define MIN_VAL 0
#define MAX_VAL 100
#define INDICATOR_BOUND 50

void setup() {
  Serial1.begin(115200);
  pinMode(INDICATOR_PIN, OUTPUT);

  Serial1.println("Raspberry Pi Pico is set!");
}

// Switch on led on value higher than threshold 
void update_led(int value) {
  if (value > INDICATOR_BOUND){
    digitalWrite(INDICATOR_PIN, HIGH);
  } else {
    digitalWrite(INDICATOR_PIN, LOW);
  }
}

void loop() {
  int rand_val = random(MIN_VAL, MAX_VAL);
  Serial1.println("Random value is: " + String(rand_val));
  update_led(rand_val);
  delay(7000);
}
