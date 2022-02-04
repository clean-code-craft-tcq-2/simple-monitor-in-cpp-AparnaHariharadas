#include <assert.h>
#include <iostream>
using namespace std;

bool everythingIsInRange(float actualValue, float lowerLimit, float upperLimit){
    bool actualValueOk = true;
    if(actualValue < lowerLimit || actualValue > upperLimit)
        actualValueOk = false;
     
      return actualValueOk;
   }

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool batteryHealthIsGood = true;
  if(!(everythingIsInRange(temperature, 0, 45))) {
    cout << "Temperature out of range!\n";
    batteryHealthIsGood = false;
     } else if(!(everythingIsInRange(soc, 20 , 80))){
    cout << "State of Charge out of range!\n";
    batteryHealthIsGood = false;
  } else if(!(everythingIsInRange(chargeRate, 0.0 , 0.8))) {
    batteryHealthIsGood = false;
    cout << "Charge Rate out of range!\n";
  }
  return batteryHealthIsGood;
}

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
