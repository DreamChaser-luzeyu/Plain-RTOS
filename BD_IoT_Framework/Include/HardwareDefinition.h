//
// Created by dream on 2023/1/28.
//

#ifndef STM32F103C8T6_HID_HARDWAREDEFINITION_H
#define STM32F103C8T6_HID_HARDWAREDEFINITION_H

//#define ROW_GPIO GPIOA

#define ROW_SIZE ((uint16_t)3)
#define COL_SIZE ((uint16_t)5)

//uint16_t RowIndexToGPIO_Index_HDFunc(uint16_t rowIndex) {
//    switch(rowIndex) {
//        case 0: return 0;
//        case 1: return 1;
//        case 2: return 2;
//        default: return -1;
//    }
//}
//
//uint16_t ColIndexToGPIO_Index_HDFunc(uint16_t colIndex) {
//    switch(colIndex) {
//        case 0: return 3;
//        case 1: return 4;
//        case 2: return 5;
//        case 3: return 6;
//        case 4: return 7;
//        default: return -1;
//    }
//}

inline void PullDownRow_HDFunc(uint16_t rowIndex) {
    switch(rowIndex) {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 0);
            return;
        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
            return;
        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
            return;
        default: return;
    }
}

inline void PullUpRow_HDFunc(uint16_t rowIndex) {
    switch(rowIndex) {
        case 0:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, 1);
            return;
        case 1:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
            return;
        case 2:
            HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
            return;
        default: return;
    }
}

inline uint8_t ReadCol_HDFunc(uint16_t colIndex) {
    switch(colIndex) {
        case 0:
            return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
        case 1:
            return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
        case 2:
            return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
        case 3:
            return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);
        case 4:
            return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);
        default: return 2;
    }
}


#endif //STM32F103C8T6_HID_HARDWAREDEFINITION_H
