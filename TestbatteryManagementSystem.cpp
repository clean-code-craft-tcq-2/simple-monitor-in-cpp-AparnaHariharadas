
#include <assert.h>
#include "batteryManagementSystem.h"


 int testBatterIsOkFunc(string temperature, float soc, float chargeRate, bool expectedResult){
  
     assert(batteryIsOk(temperature, soc, chargeRate) == expectedResult);
  }
  
 int main() {
     
     testBatterIsOkFunc("25.0#C", 70.0, 0.7, true);
     testBatterIsOkFunc("150.0#F", 70.0, 0.7, false);
     testBatterIsOkFunc("25.0#C", 78.0, 0.7, true);
}

