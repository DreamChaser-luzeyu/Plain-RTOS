//
// Created by dream on 2023/1/28.
//

#ifndef STM32F103C8T6_HID_PROGRAM_H
#define STM32F103C8T6_HID_PROGRAM_H

#include <stdio.h>
#include "interrupt.h"
#include "ProcessManagement.h"
#include "UserProcess.h"
#include "DoubleLinkedList.h"
//#include "KeyDetection.h"

extern uint8_t InitFinish_Flag_GV;
//extern uint8_t ScheduleProcess_Flag;

//extern PCB_Container_Def PCB_Container_GV;


void init();
void loop();

#endif //STM32F103C8T6_HID_PROGRAM_H
