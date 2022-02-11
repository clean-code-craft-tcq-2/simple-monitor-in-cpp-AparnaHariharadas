#include "batterManagementSystem.h"

bool checkBatteryHealthParametersInRange(float actualValue, float lowerLimit, float upperLimit){
    bool actualValueOk = true;
    if(actualValue < lowerLimit || actualValue > upperLimit)
        actualValueOk = false;
     
      return actualValueOk;
   }

bool checkTemperature(float temperature)
{
    return (checkBatteryHealthParametersInRange(temperature,TEMP_LOWER_LIMIT,TEMP_UPPER_LIMIT));
}

bool checkSOC(float soc)
{
    return (checkBatteryHealthParametersInRange(soc, SOC_LOWER_LIMIT,SOC_UPPER_LIMIT));
}

bool checkChargeRate(float chargeRate)
{
    return (checkBatteryHealthParametersInRange(chargeRate, CHARGERATE_LOWER_LIMIT,CHARGERATE_UPPER_LIMIT));
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool batteryHealthIsGood = true;
  batteryHealthIsGood = checkTemperature(temperature) && checkSOC(soc) && checkChargeRate(chargeRate);
  
     /* if(!batteryHealthIsGood){
          cout << paramName[i] <<" out of range!\n";
      }*/
 return batteryHealthIsGood;
}
