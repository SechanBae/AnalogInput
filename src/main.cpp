#include <Arduino.h>
//I Sechan Bae, 000803348 certify that this material is my original work. No other person's work has been used without due acknowledgement. I have not made my work available to anyone else."
String getJudgement(double temp){
  double upper[]={10,15,25,30,35,50};
  double lower[]={0,10,15,25,30,35};
  String judgements[]={"Cold!","Cool","Perfect","Warm","Hot","Too Hot!"};
  for(int i=0;i<6;i++){
    if((temp<upper[i])&&(temp>=lower[i])){
      return judgements[i];
    }
  }
  return "Out of Range";
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  int iVal; 
 
  // read digitized value from the D1 Mini's A/D convertor 
  iVal = analogRead(A0);
  double temp=iVal*0.048828125;
  String judgement=getJudgement(temp);
  // print value to the USB port 
  Serial.println("Digitized Value of is " + String(iVal)+ " to a temperature input of "+ String(temp)+" deg. C, which is "+judgement); 
 
 
  delay(2000);
}
