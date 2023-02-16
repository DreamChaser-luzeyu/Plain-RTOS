//
// Created by dream on 2023/2/10.
//

#include "UserProcess.h"
#include "stm32f1xx_hal.h"

uint32_t UserProcess_0_Stack_GArr[64];
uint32_t UserProcess_1_Stack_GArr[64];

void UserProcess_0_Func() {
    uint32_t counter = 0;
    while(1) {
        printf("[INFO ] Process 0 running, counter %lu\r\n", counter);
        counter ++;
        HAL_Delay(100);
    }
}

void UserProcess_1_Func() {
    uint32_t counter = 0;
    while(1) {
        printf("[INFO ] Process 1 running, counter %lu\r\n", counter);
        counter ++;
        HAL_Delay(300);
    }
}
