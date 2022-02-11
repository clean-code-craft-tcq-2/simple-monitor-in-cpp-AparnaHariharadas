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


bool batteryIsOk(float *value) {
    bool batteryHealthIsGood[3] = {true};
    struct batteryManagementClass::parameters para;
    for (int i = 0; i < 3; i++)
    {
        para.param.paramName = parameterNames[i];
        para.param.actualValue = value[i];
        para.param.lLimit = lowerLimit[i];
        para.param.hLimit = upperLimit[i];
        para.param.lowerWaringLimitmin = lowerLimit[i];
        para.param.lowerWaringLimitmax = lowerLimit[i] + lowerLimit[i]*0.05 ;
        para.param.upperWaringLimitmin = upperLimit[i] - upperLimit[i]*0.5;
        para.param.upperWaringLimitmax = upperLimit[i];
        batteryHealthIsGood[i] = checkBatteryHealthParametersInRange(para);
        if (batteryHealthIsGood[i] == false){
            cout << para.param.paramName <<" out of range!\n";
            return false;
        }
      return true;       
    }

 return batteryHealthIsGood;
}

 int main() {
    float values[3] = {25, 70, 0.7};
    assert(batteryIsOk(values) == true);
}
