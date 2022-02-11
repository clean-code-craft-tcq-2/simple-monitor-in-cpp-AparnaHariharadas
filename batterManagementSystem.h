#include <assert.h>
#include <iostream>
using namespace std;

#define TEMP_UPPER_LIMIT 45.0
#define TEMP_LOWER_LIMIT 0.0
#define SOC_UPPER_LIMIT 80.0
#define SOC_LOWER_LIMIT 20.0
#define CHARGERATE_UPPER_LIMIT 0.8
#define CHARGERATE_LOWER_LIMIT 0.0

class batteryManagementStucture
{
struct range
{
int low;
int high;
}
 bool checkBatteryHealthParametersInRange(float actualValue, float lowerLimit, float upperLimit);
