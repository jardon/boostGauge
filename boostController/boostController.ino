#include <ringMatrix.h>

#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 16

Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, 11);
ringMatrix ring(16);
int change;
int modifier;
int blue = 255;
int green = 255;
int target = 25;
int average = 0;
int previous = 0;


void updateAll()
{
  if(average > 0)
  {
    blue = 0;
    green = 255;
  }
  else
  {
    blue = 255;
    green = 0;
  }
  
  for(int i = 0; i < NUM_LEDS; i++)
  {
    if(ring.getValue(i) < 9999)
    {
      calculateMod(ring.getValue(i));
      strip.setPixelColor(i, modifier * change, green, blue);
    }
    else
      strip.setPixelColor(i, 0, 0, 0);
  }

  strip.show();
}

void calculateMod(int mod)
{
  mod = abs(mod);
  if(mod % NUM_LEDS > 0)
    modifier = (mod / NUM_LEDS) + 1;
  else
    modifier = mod / NUM_LEDS;

  modifier--;
}

void alert()
{
  for(int j = 0; j < 4; j++)
  {
    for(int i = 0; i < NUM_LEDS; i++)
    {
      strip.setPixelColor(i, 0, 0, 0);
    }
    strip.show();
    delay(100);
  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      strip.setPixelColor(i, 255, 0, 0);
    }
    strip.show();
    delay(100);
  }
  
}

void setup() 
{
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(50);
  strip.show();

  calculateMod(target);
  change = 255 / modifier;
}

void loop() 
{
  // put your main code here, to run repeatedly:
/*
  for(int i = -35; i < 36; i++)
  {
    average = i;
    moveTowards();
    updateAll();
    delay(1000);
  }

  for(int i = 35; i > -36; i--)
  {
    average = i;
    moveTowards();
    updateAll();
    delay(1000);
  }

  alert();
*/
  
  

}
