//
// Created by dream on 2023/2/7.
//

/**
 * 为了便于移植，并尽可能减小OS的指令集依赖性，
 * 在此文件中，我们将不区分不同指令集架构下，相同或类似寄存器的不同叫法，
 * 如x86架构下的eip与ARM架构下的
 */

#ifndef STM32F103C8T6_HID_REGISTER_H
#define STM32F103C8T6_HID_REGISTER_H

#include <stdint-gcc.h>

/**
 * 此结构体需要根据体系架构的不同做出调整。
 */
typedef struct {
    // 中断时自动入栈的寄存器
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t LR;
    uint32_t PC;
    uint32_t XPSR;
    // 需要手动保存的寄存器
    uint32_t r4;
    uint32_t r5;
    uint32_t r6;
    uint32_t r7;
    uint32_t r8;
    uint32_t r9;
    uint32_t r10;
    uint32_t r11;

    uint32_t sp;
} ProcessContext_Def;


/**
 * 获得 用于时间片切换的中断 触发时 的 程序计数器的数值
 * 此函数需要根据体系架构的不同做出调整。
 * @return PC数值
 */
uint32_t GetProgramCounter_Func();
uint32_t GetStackBasePointer_Func();
uint32_t GetStackPointer_Func();

#endif //STM32F103C8T6_HID_REGISTER_H
