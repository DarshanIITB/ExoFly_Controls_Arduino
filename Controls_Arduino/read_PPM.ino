#include <Servo.h>

unsigned long int a,b,c;
int x[15],ch1[15],ch[7],i;
//specifing   arrays and variables to store values 

Servo ESC;
int ch1_in;
int ch2_in;
int ch3_in;
int ch4_in;
int ch5_in;
int ch6_in;
int potValue;

void setup() {
Serial.begin(9600);
   pinMode(2, INPUT_PULLUP);
   ESC.attach(3);
  attachInterrupt(digitalPinToInterrupt(2), read_me,   FALLING);
  // enabling interrupt at pin 2
}

void loop() {
read_rc();
ch1_in = ch[1];
ch2_in = ch[2];
ch3_in = ch[3];
ch4_in = ch[4];
ch5_in = ch[5];
ch6_in = ch[6];
Serial.print(ch1_in);
Serial.print(" ");
Serial.print(ch2_in);
Serial.print(" ");
Serial.print(ch3_in);
Serial.print(" ");
Serial.print(ch4_in);
Serial.print(" ");
Serial.print(ch5_in);
Serial.print(" ");
Serial.print(ch6_in);
Serial.print(" ");
Serial.print("\n");
potValue = ch3_in;   // reads the value of the potentiometer (value between 0 and 1023)
potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
ESC.write(potValue);    // Send the signal to the ESC
// Serial.print(ch[1]);Serial.print("\n");
// Serial.print(ch[2]);Serial.print("\n");
// Serial.print(ch[3]);Serial.print("\n");
// Serial.print(ch[4]);Serial.print("\n");
// Serial.print(ch[5]);Serial.print("\n");
// Serial.print(ch[6]);Serial.print("\n");
delay(100);
}


void   read_me()  {
 //this code reads value from RC reciever from PPM pin (Pin 2 or   3)
 //this code gives channel values from 0-1000 values 
 //    -: ABHILASH   :-    //
a=micros(); //store time value a when pin value falling
c=a-b;      //calculating   time inbetween two peaks
b=a;        // 
x[i]=c;     //storing 15 value in   array
i=i+1;       if(i==15){for(int j=0;j<15;j++) {ch1[j]=x[j];}
             i=0;}}//copy   store all values from temporary array another array after 15 reading  
void read_rc(){
int   i,j,k=0;
  for(k=14;k>-1;k--){if(ch1[k]>10000){j=k;}}  //detecting separation   space 10000us in that another array                     
  for(i=1;i<=6;i++){ch[i]=(ch1[i+j]-1000);}}      //assign 6 channel values after separation space
