//
// Created by dream on 2023/2/10.
//

#ifndef STM32F103C8T6_HID_USERPROCESS_H
#define STM32F103C8T6_HID_USERPROCESS_H

#include <stdio.h>

extern uint32_t UserProcess_0_Stack_GArr[64];
extern uint32_t UserProcess_1_Stack_GArr[64];

void UserProcess_0_Func();
void UserProcess_1_Func();

#endif //STM32F103C8T6_HID_USERPROCESS_H
