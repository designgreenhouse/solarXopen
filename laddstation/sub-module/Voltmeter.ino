/* Function Analog voltmeter -------------------------------------------------------
 * analogvalue is the reading from the analog input pin A0
 * DigitalWrite D3 is to set a digital output
 * This means that it will map input voltages between 0 and 5 volts into integer values between 0 and 1023. 
 * This yields a resolution between readings of: 5 volts / 1024 units or, .0049 volts (4.9 mV) per unit
 * konstant 112 is calibrated depending on resistor
 *----------------------------------------------------------------------------/
 int analogvalue;
 float temp;
 float batteryVoltage;
 
 void setup()
{
    pinMode(D3, OUTPUT);
    pinMode(A0, INPUT);
 }
 
 /* This function loops forever --------------------------------------------*/
void loop()

 // check to see what the value of the A0 input is and store it in the int(heltal) variable analogvalue
 // batteryVoltage är ett flyttal som visar decimaler. Formel : batteryVoltage = A0 * 2 / 112
    analogvalue = analogRead(A0);
    temp = analogvalue*2;
    batteryVoltage = temp/112;


    if (analogvalue>2000) {
        digitalWrite(D3,HIGH);

    }
    else if (analogvalue<2000) {
        digitalWrite(D3,LOW);
    }
    else {

    }

}
