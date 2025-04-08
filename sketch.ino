#define INDICATOR_PIN 4
#define BUTTON_PIN 28
#define MIN_VAL 0
#define MAX_VAL 100
#define INDICATOR_BOUND 50

bool button_is_pressed;

void setup() {
  Serial1.begin(115200);
  pinMode(INDICATOR_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial1.println("Raspberry Pi Pico is set!");
}

// Switch on led on value higher than threshold 
// or when button is pressed
void update_led(int value) {
  if (value > INDICATOR_BOUND || button_is_pressed){
    digitalWrite(INDICATOR_PIN, HIGH);
  } else {
    digitalWrite(INDICATOR_PIN, LOW);
  }
}

void button_handler() {
  String button_status_str;
  int button_state = digitalRead(BUTTON_PIN);
  
  if (button_state == LOW) {
    button_is_pressed = true;
    button_status_str = " ";
  } else {
    button_is_pressed = false;
    button_status_str = " not ";
  }
  Serial1.println("Button is" + button_status_str + "pressed");
}

void loop() {
  int rand_val = random(MIN_VAL, MAX_VAL);
  Serial1.println("Random value is: " + String(rand_val));

  button_handler();
  update_led(rand_val);
  delay(1000);
}
