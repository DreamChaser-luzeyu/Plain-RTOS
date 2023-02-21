//
// Created by dream on 2023/2/10.
//

#include "UserProcess.h"
#include "stm32f1xx_hal.h"




// -- Add your process here --

uint32_t UserProcess_0_Stack_GArr[32];
void UserProcess_0_Func() {
    uint32_t counter = 0;
    while(1) {
        printf("[INFO ] Process 0 running, counter %lu\r\n", counter);
        counter ++;
        HAL_Delay(300);
    }
}

uint32_t UserProcess_1_Stack_GArr[32];
void UserProcess_1_Func() {
    uint32_t counter = 0;
    while(1) {
        printf("[INFO ] Process 1 running, counter %lu\r\n", counter);
        counter ++;
        HAL_Delay(300);
    }
}

uint32_t UserProcess_2_Stack_GArr[32];
void UserProcess_2_Func() {
    uint32_t counter = 0;
    while(1) {
        printf("[INFO ] Process 2 running, counter %lu\r\n", counter);
        counter ++;
        HAL_Delay(300);
    }
}

uint32_t UserProcess_3_Stack_GArr[32];
void UserProcess_3_Func() {
    uint32_t counter = 0;
    while(1) {
        printf("[INFO ] Process 3 running, counter %lu\r\n", counter);
        counter ++;
        HAL_Delay(300);
    }
}