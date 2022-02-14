#include "batterManagementSystem.h"

void printParametersState(string parameterName, string message){
    cout << parameterName << message;
}

void CheckParametersForEarlyWarning(batteryManagementClass::parameters parameter)
{

    if ( parameter.param.actualValue >= parameter.param.lowerWaringLimitmin || parameter.param.actualValue <= parameter.param.lowerWaringLimitmax)
         printParametersState(parameter.param.paramName, " Lower limit WARNING!\n");
    else if ( parameter.param.actualValue >= parameter.param.upperWaringLimitmin || parameter.param.actualValue <= parameter.param.upperWaringLimitmax)
        printParametersState(parameter.param.paramName, " Upper limit WARNING!\n");
}

bool checkBatteryHealthParametersInRange(batteryManagementClass::parameters parameter){
    if(parameter.param.actualValue < parameter.param.lLimit || parameter.param.actualValue > parameter.param.hLimit)
        return false;
     CheckParametersForEarlyWarning(parameter);
      return true;
   }


float convertFarenheitToCelcius(float tempInFarenheit)
{
    return ((tempInFarenheit - 32.0)/1.8);
}

bool batteryIsOk(float temp, float soc, float chargeRate,  char unit) {
    bool batteryHealthIsGood[3] = {true};
    struct batteryManagementClass::parameters para;
    float tempInCelsius;
    if (unit == 'F'){
        tempInCelsius = convertFarenheitToCelcius(temp);
        para.param.paramUnit = "Farenheit";
    }else if(unit == 'C'){
        tempInCelsius = temp;
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
            printParametersState(para.param.paramName, " out of range!\n");
            return false;
        }
        else
            
      return true;       
    }

 return batteryHealthIsGood;
}

 int main() {
     assert(batteryIsOk(25.0, 70.0, 0.7, 'C') == true);
     assert(batteryIsOk(25.0, 70.0, 0.7, 'F') == false);
     assert(batteryIsOk(25.0, 60.0, 0.7, 'F') == true);
}
