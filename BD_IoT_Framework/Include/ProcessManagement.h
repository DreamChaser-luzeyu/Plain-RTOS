//
// Created by dream on 2023/2/6.
//

#ifndef STM32F103C8T6_HID_PROCESSMANAGEMENT_H
#define STM32F103C8T6_HID_PROCESSMANAGEMENT_H

#include <stdio.h>
#include "register.h"
#include "interrupt.h"
#include "DoubleLinkedList.h"
#include "SysConfiguration.h"

typedef enum {
    CREATED = 0,
    READY,
    RUNNING,
    FINISHED,
    BLOCKED
} ProcessState_enumDef;

typedef struct {
    DoubleLinkedList_Node_Def node;
    ProcessContext_Def context;
    ProcessState_enumDef processState;
    uint16_t uid;
    void (*processEntry)();
    uint32_t* stack;
    uint32_t processStackPointer;
} ProcessControlBlock_Def;

typedef struct {
    void (*addProcess_apiFunc)(ProcessControlBlock_Def* pcb);

} PCB_Manager_Def;

typedef struct {
    DoubleLinkedList_Node_Def listHead;
    ProcessControlBlock_Def pcbArray[TCB_CONTAINER_SIZE];
} PCB_Container_Def;



extern ProcessControlBlock_Def* CurrentProcess_Ptr_GV;
extern ProcessControlBlock_Def* NextProcess_Ptr_GV;
extern ProcessControlBlock_Def UserProcess_0_PCB_GV;
extern ProcessControlBlock_Def UserProcess_1_PCB_GV;
extern ProcessControlBlock_Def UserProcess_2_PCB_GV;
extern ProcessControlBlock_Def UserProcess_3_PCB_GV;

extern PCB_Container_Def PCB_Container_GV;

extern uint8_t InitFinish_Flag_GV;

void ScheduleProcess_Func();
void ScheduleProcess_TimeSliceCycle_From_Func(PCB_Container_Def* pcbContainer);
void AddUserProcess_apiFunc(PCB_Container_Def* pcbContainer, ProcessControlBlock_Def* pcb);

#endif //STM32F103C8T6_HID_PROCESSMANAGEMENT_H
