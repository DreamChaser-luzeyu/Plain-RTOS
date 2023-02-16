//
// Created by dream on 2023/2/6.
//

#ifndef STM32F103C8T6_HID_PROCESSMANAGEMENT_H
#define STM32F103C8T6_HID_PROCESSMANAGEMENT_H

#include <stdio.h>
#include "register.h"
#include "interrupt.h"

typedef enum {
    CREATED = 0,
    READY,
    RUNNING,
    FINISHED,
    BLOCKED
} ProcessState_enumDef;

typedef struct {
    ProcessContext_Def context;
    ProcessState_enumDef processState;
    uint16_t uid;
    void (*processEntry)();
    uint32_t* stack;
    uint32_t processStackPointer;
} ProcessControlBlock_Def;

extern ProcessControlBlock_Def* CurrentProcess_Ptr_GV;
extern ProcessControlBlock_Def* NextProcess_Ptr_GV;
extern ProcessControlBlock_Def UserProcess_0_PCB_GV;
extern ProcessControlBlock_Def UserProcess_1_PCB_GV;

extern uint8_t InitFinish_Flag_GV;

void ScheduleProcess_Func();


#endif //STM32F103C8T6_HID_PROCESSMANAGEMENT_H
