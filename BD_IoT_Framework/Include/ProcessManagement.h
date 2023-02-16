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
//    void (*processBreakPoint)();
//    uint32_t* stackTop_ptr;
    uint8_t* stack;
    uint32_t processStackPointer;
} ProcessControlBlock_Def;

//uint32_t StackPointerOfCurrentProcess_GV;
extern ProcessControlBlock_Def* CurrentProcess_Ptr_GV;
extern ProcessControlBlock_Def* NextProcess_Ptr_GV;
extern ProcessControlBlock_Def KernelProcess0_PCB_GV;
extern ProcessControlBlock_Def KernelProcess1_PCB_GV;

extern uint8_t InitFinish_Flag_GV;

void ScheduleProcess_Func();

void SwitchToProcess_apiFunc(ProcessControlBlock_Def* pcb);

#endif //STM32F103C8T6_HID_PROCESSMANAGEMENT_H
