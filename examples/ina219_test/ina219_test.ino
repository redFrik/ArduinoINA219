/**********************************************
* INA219 library example
* 10 May 2012 by johngineer
*
* this code is public domain.
**********************************************/


#include <Wire.h>
#include <INA219.h>

INA219 monitor;


void setup()
{
  Serial.begin(9600);
  monitor.begin();
  // configure with default values RANGE_16V, GAIN_8_320MV, ADC_12BIT, ADC_12BIT, CONT_SH_BUS
  monitor.configure(); 
  // calibrate with default values D_SHUNT=0.25, D_V_BUS_MAX=6, D_V_SHUNT_MAX=0.3, D_I_MAX_EXPECTED=1
  monitor.calibrate(); 
}

void loop()
{

  Serial.println("******************");
  
  Serial.print("raw shunt voltage: ");
  Serial.println(monitor.shuntVoltageRaw());
  
  Serial.print("raw bus voltage:   ");
  Serial.println(monitor.busVoltageRaw());
  
  Serial.println("--");
  
  Serial.print("shunt voltage: ");
  Serial.print(monitor.shuntVoltage() * 1000, 4);
  Serial.println(" mV");
  
  Serial.print("shunt current: ");
  Serial.print(monitor.shuntCurrent() * 1000, 4);
  Serial.println(" mA");
  
  Serial.print("bus voltage:   ");
  Serial.print(monitor.busVoltage(), 4);
  Serial.println(" V");
  
  Serial.print("bus power:     ");
  Serial.print(monitor.busPower() * 1000, 4);
  Serial.println(" mW");
  
  Serial.println(" ");
  Serial.println(" ");
  
  delay(10000);

}


