#include <Arduino.h>
#include <BluetoothA2DPSink.h>
#include <FastLED.h>

#define NUM_LEDS 1
#define LED_DATA_PIN 2

CRGB leds[NUM_LEDS]; 

I2SStream out;
BluetoothA2DPSink a2dp_sink(out);

void setup() 
{
    FastLED.addLeds<WS2812, LED_DATA_PIN, GRB>(leds, NUM_LEDS);
    FastLED.setBrightness(30);

    a2dp_sink.start("MyMusic");  
}

void loop() 
{
    leds[0] = CRGB::Red;
    FastLED.show();
    delay(1000);
    leds[0] = CRGB::Green;
    FastLED.show();
    delay(1000);
    leds[0] = CRGB::Blue;
    FastLED.show();
    delay(1000);
}