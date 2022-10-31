SFE_BMP180 pressure;
//rev Dimitris
int Altitude = 5; //current altitude in meters
char strTempout[10];
char strPressure[10];  
void GetPressure()
{
  Serial.begin(9600);
  bool success = pressure.begin();

  if (success) 
  {
    Serial.println("BMP180 init success");
    char status;
    double T,P;
    //measure pressure & air temperatrue from GY-68
    status = pressure.startTemperature();
    if (status != 0)
    {
      // Wait for the measurement to complete:
      delay(status);
      status = pressure.getTemperature(T);
      if (status != 0)
      {
        status = pressure.startPressure(3);
        if (status != 0)
        {
          // Wait for the measurement to complete:
          delay(status);
          status = pressure.getPressure(P,T);
        }
      }
    }
    dtostrf(T,7,2,strTempout); 
    strLogline += strTempout;
    strLogline += ';';
    dtostrf(P,7,2,strPressure); 
    strLogline += strPressure;
    strLogline += ';';
  }
}
