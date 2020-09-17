#define LED_PIN 1
#define DOOR_PIN 2
#define BRIGHTNESS_ON 25
#define BRIGHTNESS_OFF 0
#define BRIGHTNESS_STEP 1
#define BRIGHTNESS_STEP_DURATION 50

unsigned int brightness = 0;
unsigned int target_brightness = 0;

void setup()
{
  pinMode(DOOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

bool doorOpen()
{
  return digitalRead(DOOR_PIN) == LOW;
}

void loop()
{
  if (doorOpen())
  {
    target_brightness = BRIGHTNESS_ON;
  }
  else
  {
    target_brightness = BRIGHTNESS_OFF;
  }
  if (brightness != target_brightness)
  {
    if (brightness < target_brightness)
    {
      brightness += BRIGHTNESS_STEP;
    }
    else
    {
      brightness -= BRIGHTNESS_STEP;
    }
    analogWrite(LED_PIN, brightness);
    delay(BRIGHTNESS_STEP_DURATION);
  }
}
