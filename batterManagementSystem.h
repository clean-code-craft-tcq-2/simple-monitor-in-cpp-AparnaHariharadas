#include <iostream>
using namespace std;
#define TEMP_UPPER_LIMIT 45.0
#define TEMP_LOWER_LIMIT 0.0
#define SOC_UPPER_LIMIT 80.0
#define SOC_LOWER_LIMIT 20.0
#define CHARGERATE_UPPER_LIMIT 0.8
#define CHARGERATE_LOWER_LIMIT 0.0
#define NO_OF_PARAMETERS 3
#define TOLERANCE_MULTIPLICANT 0.05
float lowerLimit[3] = {TEMP_LOWER_LIMIT, SOC_LOWER_LIMIT, CHARGERATE_LOWER_LIMIT};
float upperLimit[3] = {TEMP_UPPER_LIMIT, SOC_UPPER_LIMIT, CHARGERATE_UPPER_LIMIT};
string parameterNames[3] = {"Temperature", "SOC", "ChargeRate"};
class batteryManagementClass
{

 public: 
 struct batteryManagementRange
 {
  float lLimit;
  float hLimit;
  float actualValue;
 
  float upperWaringLimitmin;
  float upperWaringLimitmax;
  float lowerWaringLimitmin;
  float lowerWaringLimitmax;
  string paramUnit;
  string paramName;
 };
 };
bool batteryIsOk(string temp, float soc, float chargeRate);
