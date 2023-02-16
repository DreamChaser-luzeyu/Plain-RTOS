//
// Created by dream on 2023/1/28.
//

#ifndef STM32F103C8T6_HID_KEYDETECTION_H
#define STM32F103C8T6_HID_KEYDETECTION_H

#include "utils.h"
#include "stm32f1xx_hal.h"
#include "HardwareDefinition.h"
#include "KeyBehavior.h"

extern uint16_t CurrentRowIndex_GV;


void DetectAllKeys_Func();

static void readCurrentRow_pFunc() {
    for(uint16_t i = 0; i < COL_SIZE; i++) {
        if(ReadCol_HDFunc(i) == 0) {
            // 按键被按下
            DoBehavior_Func(CurrentRowIndex_GV, i);
        }
    }
}

static void updateRowIndex_pFunc() {
    CurrentRowIndex_GV ++;
    if(CurrentRowIndex_GV == ROW_SIZE) { CurrentRowIndex_GV = 0; }
}

//void PullDownRow_Func();
//void PullUpRow_Func();

#endif //STM32F103C8T6_HID_KEYDETECTION_H
