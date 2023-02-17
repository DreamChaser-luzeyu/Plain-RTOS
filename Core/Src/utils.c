//
// Created by dream on 2023/1/28.
//

#include "utils.h"

uint16_t IndexToGPIO_Pin_HDFunc(uint16_t pinIndex) {
    uint16_t pin = (uint16_t)0x0001;
    for(uint16_t i = 0; i < (uint16_t)pinIndex; i++) { pin = pin << 1; }
    return pin;
}

