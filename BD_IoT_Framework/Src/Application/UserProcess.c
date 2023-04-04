//
// Created by dream on 2023/2/10.
//

#include "UserProcess.h"
#include "stm32f1xx_hal.h"
#include "Semaphore.h"


volatile uint32_t Shared_Counter_GV = 0;

volatile uint8_t SC_Mutex_GV = 0;

// -- Add your process here --

//uint32_t UserProcess_0_Stack_GArr[32];
//void UserProcess_0_Func() {
//    uint32_t counter = 0;
//    for(uint32_t i = 0; i < 100; i++) {
//        printf("[INFO ] Process 0 running, counter %lu\r\n", counter);
//        counter ++;
//        HAL_Delay(300);
//    }
//}

volatile uint32_t UserProcess_1_Stack_GArr[32];
void UserProcess_1_Func() {
//    uint32_t counter = 0;
    for(uint32_t i = 0; i < 200; i++) {
        SpinMutex_Lock_apiFunc(&SC_Mutex_GV);
        volatile uint32_t tmp = Shared_Counter_GV;
        for(uint32_t c = 0; c<100000; c++);
//        HAL_Delay(10);
        tmp ++;
        for(uint32_t c = 0; c<100000; c++);
//        HAL_Delay(10);
        Shared_Counter_GV = tmp;
        SpinMutex_Unlock_apiFunc(&SC_Mutex_GV);

    }

    while(1) {
//        printf("[INFO1] %lu\r\n", Shared_Counter_GV);
        HAL_Delay(300);
    }
}

volatile uint32_t UserProcess_2_Stack_GArr[32];
void UserProcess_2_Func() {
//    uint32_t counter = 0;
    for(uint32_t i = 0; i < 200; i++) {
        SpinMutex_Lock_apiFunc(&SC_Mutex_GV);
        volatile uint32_t tmp = Shared_Counter_GV;
        for(uint32_t c = 0; c<100000; c++);
//        HAL_Delay(10);
        tmp ++;
        for(uint32_t c = 0; c<100000; c++);
//        HAL_Delay(10);
        Shared_Counter_GV = tmp;
        SpinMutex_Unlock_apiFunc(&SC_Mutex_GV);
    }

    while(1) {
//        printf("[INFO2] %lu\r\n", Shared_Counter_GV);
        HAL_Delay(300);
    }
}

volatile uint32_t UserProcess_3_Stack_GArr[32];
void UserProcess_3_Func() {
//    uint32_t counter = 0;
    for(uint32_t i = 0; i < 200; i++) {
        SpinMutex_Lock_apiFunc(&SC_Mutex_GV);
        volatile uint32_t tmp = Shared_Counter_GV;
//        HAL_Delay(10);
        for(uint32_t c = 0; c<100000; c++);
        tmp ++;
//        HAL_Delay(10);
        for(uint32_t c = 0; c<100000; c++);
        Shared_Counter_GV = tmp;
        SpinMutex_Unlock_apiFunc(&SC_Mutex_GV);
    }

    while(1) {
//        printf("[INFO3] %lu\r\n", Shared_Counter_GV);
        HAL_Delay(300);
    }
}