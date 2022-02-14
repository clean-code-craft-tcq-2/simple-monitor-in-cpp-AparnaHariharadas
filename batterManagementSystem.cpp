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


float convertTempIfInFarenheit(float temperature, string unit)
{
    if(unit == "F")
        return ((temperature - 32.0)/1.8);
    else 
        return temperature;
}

bool batteryIsOk(string temp, float soc, float chargeRate) {
    bool batteryHealthIsGood[3] = {true};
    struct batteryManagementClass::parameters para;
    float tempInCelsius;
  
   
    string delim;
    size_t pos = 0;
    //pos = temp.find (delim);
    //float temperature = 25.0;
    //string temperature = temp.substr(0, temp.find(delim));
    temp.erase(0, temp.find (delim) + delim.length());
   //pos = temp.find (delim))
    string temperature = temp.substr(temp.find (delim), temp.find(delim));
    temp.erase(0, pos + delim.length());
    string unit =  temp; 
    //tempInCelsius = convertTempIfInFarenheit(temperature,unit);
    tempInCelsius=25.0;
    cout << temperature << "yes" <<unit << "\n";
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
     
     assert(batteryIsOk("25.0#C", 70.0, 0.7) == true);
     assert(batteryIsOk("150.0#F", 70.0, 0.7) == true);
     assert(batteryIsOk("25.0#C", 60.0, 0.7) == true);
}
