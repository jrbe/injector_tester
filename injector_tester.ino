//ARUINO FUEL INJECTOR CLEANER/TESTER

//NEED A SAFETY STOP INPUT WITTEN IN - NOT DONE YET
//VOLTAGE DISPLAY INPUT?

// injmode is 1 for 360 degrees and 2 for 720 degree mode
//EQUATION 1000000(#_of_injectors/injmode)/60=revolution_time
//revolution_time - off time = available injector on time
// available injector on time / #_of_injectors = injector sequence gap time

unsigned int injqty = 8;
//WILL EVENTUALLY BE MENU ADJUSTABLE TO SET # OF INJECTORS

unsigned int RPM = 7000; //NOT PROGRAMMED YET - WILL BE MENU DRIEN AND WILL CALCULATE INJECTOR OFF TIME AND AVAILABLE ON TIME
unsigned int offtime = 1000; //TO BE ALCULATED AND MENU DRIVEN

const byte FUEL_PUMP = 4;
//TO BE ON FOR 4 SECONDS BEFORE, DURING, AND 4 SECONDS AFTER RUN CYCLE - NOT PROGRAMMED YET

const byte INJ1_PIN = 5;
const byte INJ2_PIN = 6;
const byte INJ3_PIN = 7;
const byte INJ4_PIN = 8;
const byte INJ5_PIN = 9;
const byte INJ6_PIN = 10;
const byte INJ7_PIN = 11;
const byte INJ8_PIN = 12;
//SKIPPED PIN 13 BECAUSE OF ITS BOOT/WRITE BEHAVIORS 

//1 MILLSECOND = 1000 MICROSECONDS - WILL EVENTUALLY BE MENU DRVEN - IDIVIDUAL OR BATCHTIME?
const unsigned long INJ1_ON = 16000UL;     //microseconds on
const unsigned long INJ2_ON = 16000UL;
const unsigned long INJ3_ON = 16000UL;     //microseconds on
const unsigned long INJ4_ON = 16000UL;
const unsigned long INJ5_ON = 16000UL;     //microseconds on
const unsigned long INJ6_ON = 16000UL;
const unsigned long INJ7_ON = 16000UL;     //microseconds on
const unsigned long INJ8_ON = 16000UL;

//MINIMUM OFF TIME?  OFF TIME AS MICROSECONSDS OR DUTY CYCE?
const unsigned long INJ1_OFF = 2000000UL;  //microseconds off - WILL BE MENU DRIVEN AND CALC'D FROM RPM
const unsigned long INJ2_OFF = 2000000UL;
const unsigned long INJ3_OFF = 2000000UL;
const unsigned long INJ4_OFF = 2000000UL;
const unsigned long INJ5_OFF = 2000000UL;
const unsigned long INJ6_OFF = 2000000UL;
const unsigned long INJ7_OFF = 2000000UL;
const unsigned long INJ8_OFF = 2000000UL;

unsigned long mcs1;        //time from micros()
unsigned long mcs1Last;    //last time the inj changed state
unsigned long mcs2;        //time from micros()
unsigned long mcs2Last;    //last time the inj changed state
unsigned long mcs3;        //time from micros()
unsigned long mcs3Last;    //last time the inj changed state
unsigned long mcs4;        //time from micros()
unsigned long mcs4Last;    //last time the inj changed state
unsigned long mcs5;        //time from micros()
unsigned long mcs5Last;    //last time the inj changed state
unsigned long mcs6;        //time from micros()
unsigned long mcs6Last;    //last time the inj changed state
unsigned long mcs7;        //time from micros()
unsigned long mcs7Last;    //last time the inj changed state
unsigned long mcs8;        //time from micros()
unsigned long mcs8Last;    //last time the inj changed state
boolean inj1State;        //current inj1 state
boolean inj2State;        //current inj2 state
boolean inj3State;        //current inj3 state
boolean inj4State;        //current inj4 state
boolean inj5State;        //current inj5 state
boolean inj6State;        //current inj6 state
boolean inj7State;        //current inj7 state
boolean inj8State;        //current inj8 state

void setup(void) {

    pinMode (INJ1_PIN, OUTPUT);
    pinMode (INJ2_PIN, OUTPUT);
    pinMode (INJ3_PIN, OUTPUT);
    pinMode (INJ4_PIN, OUTPUT);
    pinMode (INJ5_PIN, OUTPUT);
    pinMode (INJ6_PIN, OUTPUT);
    pinMode (INJ7_PIN, OUTPUT);
    pinMode (INJ8_PIN, OUTPUT);
    pinMode (FUEL_PUMP, OUTPUT); //NOT PROGRAMMED YET
}

void loop(void)
{
    mcs1 = micros();
    mcs2 = micros();
    mcs3 = micros();
    mcs4 = micros();
    mcs5 = micros();
    mcs6 = micros();
    mcs7 = micros();
    mcs8 = micros();
    pulseINJ1();
    pulseINJ2();
    pulseINJ3();
    pulseINJ4();
    pulseINJ5();
    pulseINJ6();
    pulseINJ7();
    pulseINJ8();    
    
//NEEDS SEQUENTIAL TIME CALCULATED FROM # OF INJECTORS. INITIAL DELAY OR DELAY EACH CYCLE?
//NEEDS COUNTERS ADDED TO EACH/LAST? INJECTOR TO KEEP TRACK OF RUN

}

void pulseINJ1(void)
{
    if (( injqty > 0) && (mcs1 - mcs1Last > (inj1State ? INJ1_ON : INJ1_OFF))) {
        digitalWrite(INJ1_PIN, inj1State = !inj1State);
        mcs1Last = mcs1;
    }
}

void pulseINJ2(void)
{
    if (( injqty > 1) && (mcs2 - mcs2Last > (inj2State ? INJ2_ON : INJ2_OFF))) {
        digitalWrite(INJ2_PIN, inj2State = !inj2State);
        mcs2Last = mcs2;
    }
}

void pulseINJ3(void)
{
    if (( injqty > 2) && (mcs3 - mcs3Last > (inj3State ? INJ3_ON : INJ3_OFF))) {
        digitalWrite(INJ3_PIN, inj3State = !inj3State);
        mcs3Last = mcs3;
    }
}

void pulseINJ4(void)
{
    if (( injqty > 3) && (mcs4 - mcs4Last > (inj4State ? INJ4_ON : INJ4_OFF))) {
        digitalWrite(INJ4_PIN, inj4State = !inj4State);
        mcs4Last = mcs4;
    }
}

void pulseINJ5(void)
{
    if (( injqty > 4) && (mcs5 - mcs5Last > (inj5State ? INJ5_ON : INJ5_OFF))) {
        digitalWrite(INJ5_PIN, inj5State = !inj5State);
        mcs5Last = mcs5;
    }
}

void pulseINJ6(void)
{
    if (( injqty > 5) && (mcs6 - mcs6Last > (inj6State ? INJ6_ON : INJ6_OFF))) {
        digitalWrite(INJ6_PIN, inj6State = !inj6State);
        mcs6Last = mcs6;
    }
}

void pulseINJ7(void)
{
    if (( injqty > 6) && (mcs7 - mcs7Last > (inj7State ? INJ7_ON : INJ7_OFF))) {
        digitalWrite(INJ7_PIN, inj7State = !inj7State);
        mcs7Last = mcs7;
    }
}

void pulseINJ8(void)
{
    if (( injqty > 7) && (mcs8 - mcs8Last > (inj8State ? INJ8_ON : INJ8_OFF))) {
        digitalWrite(INJ8_PIN, inj8State = !inj8State);
        mcs8Last = mcs8;
    }
}
