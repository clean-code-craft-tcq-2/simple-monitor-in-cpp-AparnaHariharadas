//#include <iostream>
//using namespace std;
#include "batterManagementSystem.h"

void printParametersStatus(string parameterName, string message){
    cout << parameterName << message;
}

void CheckParametersForEarlyWarning(batteryManagementClass::batteryManagementRange parameter)
{
    if ((parameter.actualValue - parameter.lowerWaringLimitmax) * (parameter.actualValue - parameter.lLimit) <= 0)
         printParametersStatus(parameter.paramName, " Lower limit WARNING!\n");
    else if ((parameter.actualValue - parameter.hLimit) * (parameter.actualValue - parameter.upperWaringLimitmin) <= 0)
        printParametersStatus(parameter.paramName, " Upper limit WARNING!\n");
}

bool checkBatteryHealthParametersInRange(batteryManagementClass::batteryManagementRange parameter){
    if(parameter.actualValue < parameter.lLimit || parameter.actualValue > parameter.hLimit)
        return false;
     CheckParametersForEarlyWarning(parameter);
      return true;
   }


float convertTempIfInFarenheit(float temperature, string unit)
{
    if(unit == "F")
        return ((temperature - 32.0)/1.8);
    else 
        return temperature;
}

bool batteryIsOk(string temp, float soc, float chargeRate) {
    bool batteryHealthIsGood[3] = {true};
    struct batteryManagementClass::batteryManagementRange parameter;
    float tempInCelsius;
    string delim="#";
    float temperature = stof(temp.substr(0, temp.find(delim)));
    temp.erase(0, temp.find (delim) + delim.length());
    string unit =  temp; 
    tempInCelsius = convertTempIfInFarenheit(temperature,unit);
    float paramActuals[4] ={tempInCelsius, soc, chargeRate};
    for (int i = 0; i < NO_OF_PARAMETERS; i++)
    {        
        parameter.paramName = parameterNames[i];
        parameter.actualValue = paramActuals[i];
        parameter.lLimit = lowerLimit[i];
        parameter.hLimit = upperLimit[i];
        parameter.lowerWaringLimitmax = lowerLimit[i] + upperLimit[i] * TOLERANCE_MULTIPLICANT ;
        parameter.upperWaringLimitmin = upperLimit[i] - upperLimit[i] * TOLERANCE_MULTIPLICANT;
        batteryHealthIsGood[i] = checkBatteryHealthParametersInRange(parameter);
        if (batteryHealthIsGood[i] == false){
            printParametersStatus(parameter.paramName, " out of range!\n");
            return false;
        }
    
    }

 return true;
}

