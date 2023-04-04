//
// Created by dream on 2023/3/31.
//

#include <stdint-gcc.h>
#include "cmsis_gcc.h"

#ifndef STM32F103C8T6_HID_SEMAPHORE_H
#define STM32F103C8T6_HID_SEMAPHORE_H

void SpinMutex_Lock_apiFunc(volatile uint8_t* lock);
void SpinMutex_Unlock_apiFunc(volatile uint8_t* lock);

#endif //STM32F103C8T6_HID_SEMAPHORE_H
