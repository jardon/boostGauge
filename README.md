# boostGauge
Arduino boost gauge using an Adafruit NeoPixel.

## Overview
This is a personal project at making a 52mm boost gauge for a forced induction engine.  Ring Matrix is a library that I created to manage the neopixel meter.  It is a derivative of a circular array that is designed to hold all of the values of each LED.  

## Reading the display
- Green: Indicates postive pressure
- Blue: Indicates vaccume
- Red (flashing): Sensor indicates that the pressure is higher than max

The driver tiles red into the color to indicate that the array has wrapped around itself.

**Note: For a more readable value, the center display should be used. **

## Issues
- I dont like the boundaries that it has mostly because of the lack of predictability without having a specific sensor set aside
- The methodology for how the array is moved needs to be re-evaluated
- I'm bad at blender. There needs to be a gauge face made. Maybe someone could make something better?
- Don't have a center display picked out.  Could do two seven segment displays that fit PERFECT but then theres dealing with resister arrays with a not that flexible display

## Components
- Adruino Microcontroller
- Adafruit Neopixel
- Digit display (Still TBD)
- Pressure Sensor (3 bar)
- Access to a 3D printer

## How to
1. Wire it up
1. Clone the repo
1. Make adjustments to fit your application
1. Upload software to Ardruino
  
**_A better How to will come eventually_** 
