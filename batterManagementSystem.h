#include <assert.h>
#include <iostream>
using namespace std;

#define TEMP_UPPER_LIMIT 45.0
#define TEMP_LOWER_LIMIT 0.0
#define SOC_UPPER_LIMIT 80.0
#define SOC_LOWER_LIMIT 20.0
#define CHARGERATE_UPPER_LIMIT 0.8
#define CHARGERATE_LOWER_LIMIT 0.0
#define NO_OF_PARAMETERS 3
float lowerLimit[3] = {0.0,20.0, 0.0};
float upperLimit[3] = {45.0,80.0, 0.8};
string parameterNames[3] = {"Temperature", "SOC", "ChargeRate"};
class batteryManagementClass
{

 public: 
 struct batteryManagementRange
 {
  float lLimit;
  float hLimit;
  float actualValue;
  struct range{
   float min;
   float max;
  };
  string paramName;
 };
 struct parameters
 {
  struct batteryManagementRange param;
  };
  //bool checkBatteryHealthParametersInRange(parameters parameter);
 };

