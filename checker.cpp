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
  string paramName[3] = {"Temperature", "State_Out_Charge", "ChargeRate"};
  float paramActual[3] = {temperature, soc, chargeRate};
  float paramLowerLim[3] =  {0, 20 , 0.0};
  float paramUpperLim[3] =  {45, 80 , 0.8};
  for(int i = 0; i<+2 ;i++){
      if(!everythingIsInRange(paramActual[i], paramLowerLim[i], paramUpperLim[i])){
          batteryHealthIsGood = false;
          cout << paramName[i] <<" out of range!\n";
      }
  }
 return batteryHealthIsGood;
}
      
                                                            
                                                        
                                                        
                                                    
                                                        
  /*if(!(everythingIsInRange(temperature, 0, 45))) {
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
}*/

int main() {
  assert(batteryIsOk(25, 70, 0.7) == true);
  assert(batteryIsOk(50, 85, 0) == false);
}
