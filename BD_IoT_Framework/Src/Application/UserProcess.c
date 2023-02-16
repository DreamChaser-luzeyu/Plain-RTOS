//
// Created by dream on 2023/2/10.
//

#include "UserProcess.h"
#include "stm32f1xx_hal.h"

uint32_t UserProcess1_Stack_GArr[64];
uint32_t UserProcess2_Stack_GArr[64];

void UserProcess_1_Func() {
    uint32_t counter = 0;
    while(1) {
        printf("[INFO] Process 1 running, counter %lu\r\n", counter);
        counter ++;
//        printf("*");
//        printf("*");
//        printf("*");
        HAL_Delay(100);
    }
}

void UserProcess_2_Func() {
    uint32_t counter = 0;
    while(1) {
        printf("[INFO] Process 2 running, counter %lu\r\n", counter);
        counter ++;
//        printf("#");
//        printf("#");
//        printf("#");
        HAL_Delay(300);
    }
}
