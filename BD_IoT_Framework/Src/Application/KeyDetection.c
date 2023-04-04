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
