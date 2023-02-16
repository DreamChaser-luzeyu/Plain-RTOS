//
// Created by dream on 2023/2/10.
//

#ifndef STM32F103C8T6_HID_USERPROCESS_H
#define STM32F103C8T6_HID_USERPROCESS_H

#include <stdio.h>

extern uint32_t UserProcess1_Stack_GArr[64];
extern uint32_t UserProcess2_Stack_GArr[64];

void UserProcess_1_Func();
void UserProcess_2_Func();

#endif //STM32F103C8T6_HID_USERPROCESS_H
