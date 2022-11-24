
void ahtBegin(){
  while (aht10.begin(0, 2) != true)  //for ESP-01 use aht10.begin(0, 2);
  {
    sensorData.status="AHT1x not connected or fail to load calibration coefficient";



    //Serial.println(F("AHT1x not connected or fail to load calibration coefficient"));  //(F()) save string to flash & keeps dynamic memory free

   // delay(5000);
  }

}

void printStatus()
{
  switch (aht10.getStatus())
  {
    case AHTXX_NO_ERROR:
    sensorData.status="no error";
     //Serial.println(F("no error"));
      break;

    case AHTXX_BUSY_ERROR:
     // Serial.println(F("sensor busy, increase polling time"));
      sensorData.status="sensor busy, increase polling time";
      break;

    case AHTXX_ACK_ERROR:
     sensorData.status="sensor didn't return ACK";
     // Serial.println(F("sensor didn't return ACK, not connected, broken, long wires (reduce speed), bus locked by slave (increase stretch limit)"));
      break;

    case AHTXX_DATA_ERROR:
      Serial.println(F("received data smaller than expected, not connected, broken, long wires (reduce speed), bus locked by slave (increase stretch limit)"));
      break;

    case AHTXX_CRC8_ERROR:
      Serial.println(F("computed CRC8 not match received CRC8, this feature supported only by AHT2x sensors"));
      break;

    default:
    sensorData.status="unknown status";
      //Serial.println(F("unknown status"));    
      break;
  }
}

void readSensorsAHT(){

 ahtValue = aht10.readTemperature(); //read 6-bytes via I2C, takes 80 milliseconds
    //sendWS("Temperature "+ String(ahtValue));
 
 sensorData.temp=ahtValue;
  // Serial.print(F("Temperature...: "));
  
   if (ahtValue != AHTXX_ERROR) //AHTXX_ERROR = 255, library returns 255 if error occurs
  {
     
     // Serial.print(ahtValue);
    // Serial.println(F(" +-0.3C"));
  }
  else
  {
    // printStatus(); //print temperature command status
     
    if   (aht10.softReset() == true)  sensorData.status="aht10 reset success";
    //Serial.println(F("reset success") 
    //as the last chance to make it alive
    else                             sensorData.status="aht10 reset failed";
    // Serial.println(F("reset failed")
  }

  // delay(2000); //measurement with high frequency leads to heating of the sensor, see NOTE

  ahtValue = aht10.readHumidity(); //read another 6-bytes via I2C, takes 80 milliseconds

  // sendWS("Humidity"+ String(ahtValue));
  //Serial.print(F("Humidity......: "));
   sensorData.hum=ahtValue;
   
  if (ahtValue != AHTXX_ERROR) //AHTXX_ERROR = 255, library returns 255 if error occurs
  {
    
    // sendWS("Error "+ String(AHTXX_ERROR));
    // Serial.print(ahtValue);
    // Serial.println(F(" +-2%"));
  }
  else
  {
    // printStatus(); //print humidity command status
  }

 





}
