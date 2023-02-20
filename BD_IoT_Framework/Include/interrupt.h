//
// Created by dream on 2023/2/10.
//

#ifndef STM32F103C8T6_HID_INTERRUPT_H
#define STM32F103C8T6_HID_INTERRUPT_H

#include "stm32f1xx_hal.h"
#include "tim.h"
#include "ProcessManagement.h"
#include <stdio.h>


//extern PCB_Container_Def PCB_Container_GV;

void EnableContextSwitchInterrupt_Func();
void DoContextSwitchInterrupt_Func();


#endif //STM32F103C8T6_HID_INTERRUPT_H
