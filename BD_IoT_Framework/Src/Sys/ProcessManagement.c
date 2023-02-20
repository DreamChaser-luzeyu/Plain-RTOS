//
// Created by dream on 2023/2/6.
//
#include "ProcessManagement.h"

//uint32_t StackPointerOfCurrentProcess_GV;




ProcessControlBlock_Def* CurrentProcess_Ptr_GV;
ProcessControlBlock_Def* NextProcess_Ptr_GV;

PCB_Container_Def PCB_Container_GV;

ProcessControlBlock_Def UserProcess_0_PCB_GV;
ProcessControlBlock_Def UserProcess_1_PCB_GV;

void ScheduleProcess_Func() {
    printf("[INFO ] ScheduleProcess_Func()\r\n");

    // 两个进程交替执行
    if (CurrentProcess_Ptr_GV == &UserProcess_0_PCB_GV) {
        NextProcess_Ptr_GV = &UserProcess_1_PCB_GV;
    }
    if (CurrentProcess_Ptr_GV == &UserProcess_1_PCB_GV) {
        NextProcess_Ptr_GV = &UserProcess_0_PCB_GV;
    }

    if ((CurrentProcess_Ptr_GV != NextProcess_Ptr_GV) && InitFinish_Flag_GV) {
        printf("[INFO ] ScheduleProcess_Func() -- Set PendSV Int\r\n");
        SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;   // Set PendSV to pending
    }
}

void ScheduleProcess_TimeSliceCycle_From_Func(PCB_Container_Def* pcbContainer) {
    if (InitFinish_Flag_GV) {
        DoubleLinkedList_Node_Def * header = &(pcbContainer->listHead);

        NextProcess_Ptr_GV = (ProcessControlBlock_Def*) &(CurrentProcess_Ptr_GV->node.next);
        if (NextProcess_Ptr_GV == header) {
            NextProcess_Ptr_GV = (ProcessControlBlock_Def*) &(NextProcess_Ptr_GV->node.next);
        }

        if(CurrentProcess_Ptr_GV != NextProcess_Ptr_GV) {
            printf("[INFO ] ScheduleProcess_Func() -- Set PendSV Int\r\n");
            SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk;   // Set PendSV to pending
        }
    }
}

void AddUserProcess_apiFunc(PCB_Container_Def* pcbContainer, ProcessControlBlock_Def* pcb) {
    List_InsertToHead_typeFunc(&(pcb->node), &(pcbContainer->listHead));
}
