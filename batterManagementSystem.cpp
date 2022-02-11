#include "batterManagementSystem.h"

bool checkBatteryHealthParametersInRange(batteryManagementStucture parameter){
    bool actualValueOk = true;
    if(parameter.actualValue < parameter.lLimit || parameter.actualValue > parameter.hLimit)
        actualValueOk = false;
     
      return actualValueOk;
   }

/*bool checkTemperature(float temperature)
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
}*/

bool batteryIsOk(batteryManagementStucture parameter) {
  bool batteryHealthIsGood = true;
  batteryHealthIsGood = checkBatteryHealthParametersInRange(parameter);
  
     /* if(!batteryHealthIsGood){
          cout << paramName[i] <<" out of range!\n";
      }*/
 return batteryHealthIsGood;
}
