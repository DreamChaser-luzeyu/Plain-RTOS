//
// Created by dream on 2023/2/10.
//

#include "interrupt.h"

void EnableContextSwitchInterrupt_Func() {
    HAL_TIM_Base_Start_IT(&htim2);
}

void DoContextSwitchInterrupt_Func() {
    printf("[DEBUG] DoContextSwitchInterrupt\r\n");
    ScheduleProcess_Func();
//    ScheduleProcess_TimeSliceCycle_From_Func(&PCB_Container_GV);
}