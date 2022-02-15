#include "batteryManagementSystem.h"

float lowerLimit[3] = {TEMP_LOWER_LIMIT, SOC_LOWER_LIMIT, CHARGERATE_LOWER_LIMIT};
float upperLimit[3] = {TEMP_UPPER_LIMIT, SOC_UPPER_LIMIT, CHARGERATE_UPPER_LIMIT};
string parameterNames[3] = {"Temperature", "SOC", "ChargeRate"};

void printParameterStatus(string parameterName, string message){
    cout << parameterName << message;
}

void CheckParametersForEarlyWarning(batteryManagementClass::batteryManagementRange parameter)
{
    if ((parameter.actualValue - parameter.lowerWaringLimitmax) * (parameter.actualValue - parameter.lLimit) <= 0)
         printParameterStatus(parameter.paramName, " Lower limit WARNING!\n");
    else if ((parameter.actualValue - parameter.hLimit) * (parameter.actualValue - parameter.upperWaringLimitmin) <= 0)
        printParameterStatus(parameter.paramName, " Upper limit WARNING!\n");
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

float separateParameterValueAndUnit (string parameter){
    string delim="#";
    float parameterValue = stof(parameter.substr(0, parameter.find(delim)));
    parameter.erase(0, parameter.find (delim) + delim.length());
    string unit =  parameter;
    return (convertTempIfInFarenheit(parameterValue, unit));
}

bool batteryIsOk(string temp, float soc, float chargeRate) {
    bool batteryHealthIsGood[NO_OF_PARAMETERS] = {true};
    struct batteryManagementClass::batteryManagementRange parameter;
    float tempInCelsius;
    tempInCelsius = separateParameterValueAndUnit(temp);
    float paramActuals[NO_OF_PARAMETERS] ={tempInCelsius, soc, chargeRate};
    for (int i = 0; i < NO_OF_PARAMETERS; i++)
    {  
        //separateParameterValueAndUnit(paramActuals[i])/*for future use for other parameters
        parameter.paramName = parameterNames[i];
        parameter.actualValue = paramActuals[i];
        parameter.lLimit = lowerLimit[i];
        parameter.hLimit = upperLimit[i];
        parameter.lowerWaringLimitmax = lowerLimit[i] + upperLimit[i] * TOLERANCE_MULTIPLICANT ;
        parameter.upperWaringLimitmin = upperLimit[i] - upperLimit[i] * TOLERANCE_MULTIPLICANT;
        batteryHealthIsGood[i] = checkBatteryHealthParametersInRange(parameter);
        if (batteryHealthIsGood[i] == false){
            printParameterStatus(parameter.paramName, " out of range!\n");
            return false;
        }
    
    }

 return true;
}

