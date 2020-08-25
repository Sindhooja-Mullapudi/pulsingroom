#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>
const int OUTPUT_TYPE = SERIAL_PLOTTER;
/*
 PULSE_INPUT = Analog Input. Connected to the pulse sensor
 PULSE_BLINK = digital Output. Connected to an LEDSTRIP
*/
const int PULSE_INPUT = A0;
const int PULSE_BLINK = 13; // Pin 13 is the LedStrip
const int PULSE_FADE = 5;
const int THRESHOLD = 550;
/*
 All the PulseSensor Playground functions.
*/
PulseSensorPlayground pulseSensor;
const int PIN_SPEAKER = 2; // speaker on pin2 makes a beep with heartbeat
void setup() {
 /*
 Use 115200 baud because that's what the Processing Sketch expects to read,
 and because that speed provides about 11 bytes per millisecond.
 If we used a slower baud rate, we'd likely write bytes faster than
 they can be transmitted, which would mess up the timing
 of readSensor() calls, which would make the pulse measurement
 not work properly.
 */
 Serial.begin(115200);
 // Configure the PulseSensor manager.
 pulseSensor.analogInput(PULSE_INPUT);
 pulseSensor.blinkOnPulse(PULSE_BLINK);
 pulseSensor.fadeOnPulse(PULSE_FADE);
 pulseSensor.setSerial(Serial);
 pulseSensor.setOutputType(OUTPUT_TYPE);
 pulseSensor.setThreshold(THRESHOLD);
