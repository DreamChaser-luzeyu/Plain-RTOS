//
// Created by dream on 2023/2/6.
//
#include "ProcessManagement.h"

//uint32_t StackPointerOfCurrentProcess_GV;
ProcessControlBlock_Def* CurrentProcess_Ptr_GV;
ProcessControlBlock_Def* NextProcess_Ptr_GV;
ProcessControlBlock_Def UserProcess_0_PCB_GV;
ProcessControlBlock_Def UserProcess_1_PCB_GV;

void ScheduleProcess_Func() {
    printf("[INFO ] ScheduleProcess_Func()\r\n");

    // 两个进程交替执行
    if(CurrentProcess_Ptr_GV == &UserProcess_0_PCB_GV) {
        NextProcess_Ptr_GV = &UserProcess_1_PCB_GV;
    }
    if(CurrentProcess_Ptr_GV == &UserProcess_1_PCB_GV) {
        NextProcess_Ptr_GV = &UserProcess_0_PCB_GV;
    }

    if((CurrentProcess_Ptr_GV != NextProcess_Ptr_GV) && InitFinish_Flag_GV) {
        printf("[INFO ] ScheduleProcess_Func() -- Set PendSV Int\r\n");
        SCB->ICSR  |= SCB_ICSR_PENDSVSET_Msk;   // Set PendSV to pending
    }
}
