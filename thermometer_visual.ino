const int sensorPin = A0 ; 

void setup(){
  Serial.begin(9600) ; 
  for(int x = 2 ; x < 5 ; x++){
    pinMode(x , OUTPUT);
    digitalWrite(x , LOW) ; 
  }
}

void loop(){
  const float baselineTemp = 23 ; 
  int sensorVal = analogRead(sensorPin);
  Serial.print(sensorVal) ;
  Serial.print(" ADC, ") ; 
  float voltage = (sensorVal/1024.0) * 5.0 ; 
  Serial.print(voltage) ; 
  Serial.print(" Volts, ") ; 
  float temperature = (voltage - 0.5) * 100 ; 
  Serial.print(temperature) ; 
  Serial.println(" degrees C") ; 


  if(temperature >= baselineTemp - 1 && <= baselineTemp + 1){
    digitalWrite(2 , LOW )          // purple bulb
    digitalWrite(3 , LOW )          // blue bulb
    digitalWrite(4 , HIGH )         // white bulb - ambient
    digitalWrite(5 , LOW )          // orange bulb
    digitalWrite(6 , LOW )          // red bulb
  }

  else if (temperature <= baselinetemp - 1 && temperature > baselineTemp -3) {
    digitalWrite(2 , LOW )
    digitalWrite(3 , HIGH )         //blue bulb - cold
    digitalWrite(4 , LOW )
    digitalWrite(5 , LOW )
    digitalWrite(6 , LOW )
    
  }

    else if (temperature <= baselinetemp - 3 ) {
    digitalWrite(2 , HIGH )         // purple bulb - frigid
    digitalWrite(3 , LOW )
    digitalWrite(4 , LOW )
    digitalWrite(5 , LOW )
    digitalWrite(6 , LOW )
    
  }


  else if(temperature >= baselineTemp + 1 && temperature < baselineTemp + 3) {
    digitalWrite(2 , LOW )
    digitalWrite(3 , LOW )
    digitalWrite(4 , LOW )
    digitalWrite(5 , HIGH )         // orange bulb - warm
    digitalWrite(6 , LOW )

  }

  else if(temperature >= baselineTemp + 3 ) {
    digitalWrite(2 , LOW )
    digitalWrite(3 , LOW )
    digitalWrite(4 , LOW )
    digitalWrite(5 , LOW )
    digitalWrite(6 , HIGH )         // red bulb - hottest
  }
}
