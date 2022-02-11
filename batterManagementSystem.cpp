#include "batterManagementSystem.h"

bool batteryManagementClass::checkBatteryHealthParametersInRange(parameters parameter){
    bool actualValueOk = true;
    if(parameter.paramName.actualValue < parameter.paramName.lLimit || parameter.paramName.actualValue > parameter.paramName.hLimit)
        actualValueOk = false;
     
      return actualValueOk;
   }


bool batteryIsOk(float *value) {
    bool batteryHealthIsGood[3] = {true};
    struct batteryManagementClass::parameters para;
    for (int i = 0; i < 3; i++)
    {
        para.paramName = parameterNames[i]
        para.paramName.actualValue = value[i]
        para.paramName.lLimit = lowerLimit[i]
        para.paramName.hLimit = upperLimit[i]
        batteryHealthIsGood[i] = checkBatteryHealthParametersInRange(parameter);
        if (batteryHealthIsGood[i] == false){
            cout << para.paramName <<" out of range!\n";
            return false;
        }
      return true;       
    }

 return batteryHealthIsGood;
}

 int main() {
    float values[3] = {25, 70, 0.7};
    assert(batteryIsOk(values[]) == true);
}
