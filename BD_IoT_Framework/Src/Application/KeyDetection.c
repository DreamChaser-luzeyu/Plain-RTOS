//
// Created by dream on 2023/1/28.
//
#include "KeyDetection.h"

uint16_t CurrentRowIndex_GV;


void DetectAllKeys_Func() {
    PullDownRow_HDFunc(CurrentRowIndex_GV);

    readCurrentRow_pFunc();

    PullUpRow_HDFunc(CurrentRowIndex_GV);
    updateRowIndex_pFunc();
}

//void readCurrentRow_pFunc() {
//    for(uint16_t i = 0; i < COL_SIZE; i++) {
//        if(ReadCol_HDFunc(i) == 0) {
//            // 按键被按下
//            DoBehavior_Func(CurrentRowIndex_GV, i);
//        }
//    }
//}