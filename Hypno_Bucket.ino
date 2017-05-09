#include <Adafruit_NeoPixel.h>

#define KNOB A0
#define STRIP_PIN 8

#define BRIGHTNESS 180

int stripLen = 34;
int timeDelay = 100;
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;
unsigned long stepMillis = 1000;
int knobValue = 0;
int toggleRedBlue = 0;

#define MINSTEP 22 // 45 hz
#define MAXSTEP 250 // 4 hz




Adafruit_NeoPixel strip = Adafruit_NeoPixel(stripLen, STRIP_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  //pinMode(STRIP_PIN, OUTPUT);
  pinMode(KNOB, INPUT);

  strip.begin();
  strip.show();
  strip.setBrightness(BRIGHTNESS );



}


void loop() {
  // put your main code here, to run repeatedly:
  //strip.setPixelColor(random(8), random(255), random(255), random(255));

  currentMillis = millis();

  //Gets Input and 
  knobValue = analogRead(KNOB);
  stepMillis = map(knobValue, 0, 1023, MINSTEP, MAXSTEP);

 if  (currentMillis - previousMillis >= stepMillis) {
  previousMillis = currentMillis;
  if (toggleRedBlue == 0 ) {
    // do RED
    for(int pixel = 0; pixel < stripLen; pixel ++ ) {
      strip.setPixelColor( pixel, 0, 255, 0 );   
    }
    strip.show();
    toggleRedBlue = 1;
  } else { 
    // do Blue
    for(int pixel = 0; pixel < stripLen; pixel ++ ) { 
      strip.setPixelColor( pixel, 0, 0 , 255 );
    }
    strip.show();
    toggleRedBlue = 0;
    } 
 }



}
