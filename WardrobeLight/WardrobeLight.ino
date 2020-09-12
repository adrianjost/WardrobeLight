#define LED_PIN 1
#define DOOR_PIN 2
// #define BRIGHTNESS_PIN 0
#define BRIGHTNESS_ON 150
#define BRIGHTNESS_OFF 0
#define BRIGHTNESS_STEP 1
#define BRIGHTNESS_STEP_DURATION 5
#define DOOR_OPEN_VALUE LOW
#define BRIGHTNESS_THRESHOLD 200

unsigned int brightness = 0;
unsigned int target_brightness = 0;

void setup() {
  pinMode(DOOR_PIN, INPUT_PULLUP);
  #ifdef BRIGHTNESS_PIN
    pinMode(BRIGHTNESS_PIN, INPUT);
  #endif

  pinMode(LED_PIN, OUTPUT);
}

bool doorOpen(){
  return digitalRead(DOOR_PIN) == DOOR_OPEN_VALUE;
}

bool roomDark(){
  #ifndef BRIGHTNESS_PIN
    return true;
  #else
    return analogRead(BRIGHTNESS_PIN) <= BRIGHTNESS_THRESHOLD;
  #endif
}

void loop() {
  if(doorOpen() && roomDark()){
    target_brightness = BRIGHTNESS_ON;
  }else if(!doorOpen()){
    target_brightness = BRIGHTNESS_OFF;
  }

  if(brightness == target_brightness){
    delay(1000);
  }else{
    if(brightness < target_brightness){
      brightness += BRIGHTNESS_STEP;
    }else{
      brightness -= BRIGHTNESS_STEP;
    }
    analogWrite(LED_PIN, brightness);
    delay(BRIGHTNESS_STEP_DURATION);
  }
}