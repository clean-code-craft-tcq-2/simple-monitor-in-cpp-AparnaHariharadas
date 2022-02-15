
#include <assert.h>
#include "batteryManagementSystem.h"
 int main() {
     
     assert(batteryIsOk("25.0#C", 70.0, 0.7) == true);
     assert(batteryIsOk("150.0#F", 70.0, 0.7) == false);
     assert(batteryIsOk("25.0#C", 78.0, 0.7) == true);
}

