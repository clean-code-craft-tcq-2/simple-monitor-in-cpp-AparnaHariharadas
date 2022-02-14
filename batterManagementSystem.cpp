#include "batterManagementSystem.h"

bool checkBatteryHealthParametersInRange(batteryManagementClass::parameters parameter){
    bool actualValueOk = true;
    if(parameter.param.actualValue < parameter.param.lLimit || parameter.param.actualValue > parameter.param.hLimit)
        actualValueOk = false;
     else if ( parameter.param.actualValue >= parameter.param.lowerWaringLimitmin || parameter.param.actualValue <= parameter.param.lowerWaringLimitmax)
         cout << parameter.param.paramName <<" Lower limit WARNING!\n";
    else if ( parameter.param.actualValue >= parameter.param.upperWaringLimitmin || parameter.param.actualValue <= parameter.param.upperWaringLimitmax)
        cout << parameter.param.paramName <<" Upper limit WARNING!\n";
      return actualValueOk;
   }
float convertFarenheitToCelcius(float tempInFarenheit)
{
    return ((tempInFarenheit - 32.0)/1.8);
}

bool batteryIsOk(float temp, float soc, floatvchargeRate,  char unit) {
   bool batteryHealthIsGood[3] = {true};
    struct batteryManagementClass::parameters para;
    if (unit == "F"){
            float tempInCelsius = convertFarenheitToCelcius(temp);
            para.param.paramUnit = "Farenheit";
    }else if(unit == "C"){
        float tempInCelsius = temp;
        para.param.paramUnit = "Celsius";
    }
    
    float paramActuals[4] ={tempInCelsius, soc, chargeRate, unit};
    for (int i = 0; i < 3; i++)
    {        
        para.param.paramName = parameterNames[i];
        para.param.actualValue = paramActuals[i];
        para.param.lLimit = lowerLimit[i];
        para.param.hLimit = upperLimit[i];
        para.param.lowerWaringLimitmin = lowerLimit[i];
        para.param.lowerWaringLimitmax = lowerLimit[i] + lowerLimit[i]*0.05 ;
        para.param.upperWaringLimitmin = upperLimit[i] - upperLimit[i]*0.05;
        para.param.upperWaringLimitmax = upperLimit[i];
        batteryHealthIsGood[i] = checkBatteryHealthParametersInRange(para);
        if (batteryHealthIsGood[i] == false){
            cout << para.param.paramName << para.param.paramUnit <<" out of range!\n";
            return false;
        }
      return true;       
    }

 return batteryHealthIsGood;
}

 int main() {
     assert(batteryIsOk(25.0, 70.0, 0.7, "C") == true);
     assert(batteryIsOk(25.0, 70.0, 0.7, "F") == false);
}
