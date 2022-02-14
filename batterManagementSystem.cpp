#include "batterManagementSystem.h"

void printParametersState(string parameterName, string message){
    cout << parameterName << message;
}

void CheckParametersForEarlyWarning(batteryManagementClass::parameters parameter)
{
    if ((parameter.param.actualValue-parameter.param.lowerWaringLimitmin) <= (parameter.param.lowerWaringLimitmax-parameter.param.actualValue))
         printParametersState(parameter.param.paramName, " Lower limit WARNING!\n");
    if ((parameter.param.actualValue-parameter.param.upperWaringLimitmin) <= (parameter.param.upperWaringLimitmax-parameter.param.actualValue))
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

bool batteryIsOk(string temp, float soc, float chargeRate) {
    bool batteryHealthIsGood[3] = {true};
    struct batteryManagementClass::parameters para;
    float tempInCelsius;
    float temperature = (float)s.substr(0, s.find("#"));
    string unit = s.substr(1, s.find("#"));
    /*if (unit == 'F'){
        tempInCelsius = convertFarenheitToCelcius(temp);
        para.param.paramUnit = "Farenheit";
    }else if(unit == 'C'){
        tempInCelsius = temp;
        para.param.paramUnit = "Celsius";
    }*/
     cout << temperature << unit;
    float paramActuals[4] ={tempInCelsius, soc, chargeRate};
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
       
      return true;       
    }

 return batteryHealthIsGood;
}

 int main() {
     
     assert(batteryIsOk("25.0#F", 70.0, 0.7) == true);
     assert(batteryIsOk("25.0#C", 70.0, 0.7) == false);
     assert(batteryIsOk("25.0#C", 60.0, 0.7) == false);
}
