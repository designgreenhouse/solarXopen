/* Smart Power Module A11*********************************************
  The SMP A11 is built as a state machine to control and select powersource.
  The powermodule will be able to sense the energy level from the sources and
  depending on Voltagelevel and current from different source change the state 
  accorodingly.
  
I/O setup: corresponding to A11 board layout
  A0 analog in for voltage sensor
  A1 analog in for voltage sensor
  A2 analog in for ampsensor C1
  A3 analog in for ampsensor C2
  
************************************************************************/

/* Function Analog voltmeter -------------------------------------------------------
 * analogvalue is the reading from the analog input pin A0
 * This means that it will map input voltages between 0 and 5 volts into integer values between 0 and 1023. 
 * This yields a resolution between readings of: 5 volts / 1024 units or, .0049 volts (4.9 mV) per unit
 * konstant 112 is calibrated depending on resistor
 *----------------------------------------------------------------------------*/ 
 int analogvalue;
 float temp;
 float batteryVoltage;

/* Function analog output --------------------------------------------------- 
 * For the Arduino, you write a value from 0 to 255 on a PWM pin, and the Arduino library will cause the pin to output 
 * a PWM signal whose on time is in proportion to the value written.
 * For our purposes, we will assume the Arduino is running at Vcc = 5 volts.
 * Pin Value (0-255) = 255 * (AnalogVolts / 5);
 * -----------------------------------------------------------------------------*/
int pwmPin = 9; // output pin supporting PWM
int inPin = 3; // voltage connected to analog pin 3, e.g. a potentiometer
int val = 0; // variable to store the read value
float volt = 0; // variable to hold the voltage read

void setup()
  // put your setup code here, to run once:
  {
    pinMode(A0, INPUT); // Analog input for Voltage reading at point
    pinMode(A1, Input); // Analog input for Voltage reading at point
    pinMode(A2, INPUT); // Analog input for Ampere reading at point
    pinMode(A3, INPUT); // 
    pinMode(D2, OUTPUT); // Convert to analog output for status display (0-255)
    pinMode(D3, OUTPUT); // Digital output 1 for button 1
    pinMode(D4, OUTPUT); // Digital output 2 for button 2
    pinMode(D5, OUPUT); // Digital outbut 3 for button 3
  }


void loop() {
  // put your main code here, to run repeatedly:
  
  // Voltmeter reading
    analogvalue = analogRead(A0);
    temp = analogvalue*2;
    batteryVoltage = temp/112;
  // Ampmeter reading
  *
    *
  
  // Setting analog value on output
  val = analogRead(inPin); // read the input pin
  volt =(5.0 * val) / 1023;
  val = 255 * (volt / 5);
  analogWrite(pwmPin, val);
  
}
