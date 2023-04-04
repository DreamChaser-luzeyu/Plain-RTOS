//
// Created by dream on 2023/1/28.
//
#include "program.h"

uint8_t InitFinish_Flag_GV = 0;

void init() {
    printf("[INFO ] Plain OS by Binarydumplings -- Init\r\n");
    /* Debug Code */
    uint32_t tmp;
    printf("[DEBUG] At init() -- Addr of tmp: %08x\r\n", &tmp);
    HAL_Delay(1000);

    /* Add process here BEGIN */

//    UserProcess_0_PCB_GV.processEntry = UserProcess_0_Func;
//    UserProcess_0_PCB_GV.stack = UserProcess_0_Stack_GArr;
//    UserProcess_0_PCB_GV.uid = 0;
//    // 初始化进程的初始Stack Pointer
//    //                                   初始sp = 栈的最低地址 + 栈的大小 - 16个寄存器所占据的空间
//    UserProcess_0_PCB_GV.processStackPointer = ((uint32_t) UserProcess_0_Stack_GArr) + sizeof(UserProcess_0_Stack_GArr) - (16 * 4);
//    // -- 初始化进程栈帧 --
//    // 初始化XPSR
//    *(uint32_t*)(((uint32_t) UserProcess_0_Stack_GArr) + sizeof(UserProcess_0_Stack_GArr) - (1 * 4)) = 0x01000000;
//    // 初始化栈帧上的PC为进程（函数）的入口(到底是PC还是LR啊…)
//    *(uint32_t*)(((uint32_t) UserProcess_0_Stack_GArr) + sizeof(UserProcess_0_Stack_GArr) - (2 * 4)) = (uint32_t)UserProcess_0_PCB_GV.processEntry;


    UserProcess_1_PCB_GV.processEntry = UserProcess_1_Func;
    UserProcess_1_PCB_GV.stack = UserProcess_1_Stack_GArr;
    UserProcess_1_PCB_GV.uid = 1;
    UserProcess_1_PCB_GV.processStackPointer = ((uint32_t) UserProcess_1_Stack_GArr) + sizeof(UserProcess_1_Stack_GArr) - (16 * 4);
    *(uint32_t*)(((uint32_t) UserProcess_1_Stack_GArr) + sizeof(UserProcess_1_Stack_GArr) - (1 * 4)) = 0x01000000;  // Do not use FPU
    *(uint32_t*)(((uint32_t) UserProcess_1_Stack_GArr) + sizeof(UserProcess_1_Stack_GArr) - (2 * 4)) = (uint32_t)UserProcess_1_PCB_GV.processEntry;

    UserProcess_2_PCB_GV.processEntry = UserProcess_2_Func;
    UserProcess_2_PCB_GV.stack = UserProcess_2_Stack_GArr;
    UserProcess_2_PCB_GV.uid = 2;
    UserProcess_2_PCB_GV.processStackPointer = ((uint32_t) UserProcess_2_Stack_GArr) + sizeof(UserProcess_2_Stack_GArr) - (16 * 4);
    *(uint32_t*)(((uint32_t) UserProcess_2_Stack_GArr) + sizeof(UserProcess_2_Stack_GArr) - (1 * 4)) = 0x01000000;
    *(uint32_t*)(((uint32_t) UserProcess_2_Stack_GArr) + sizeof(UserProcess_2_Stack_GArr) - (2 * 4)) = (uint32_t)UserProcess_2_PCB_GV.processEntry;

    UserProcess_3_PCB_GV.processEntry = UserProcess_3_Func;
    UserProcess_3_PCB_GV.stack = UserProcess_3_Stack_GArr;
    UserProcess_3_PCB_GV.uid = 3;
    UserProcess_3_PCB_GV.processStackPointer = ((uint32_t) UserProcess_3_Stack_GArr) + sizeof(UserProcess_3_Stack_GArr) - (16 * 4);
    *(uint32_t*)(((uint32_t) UserProcess_3_Stack_GArr) + sizeof(UserProcess_3_Stack_GArr) - (1 * 4)) = 0x01000000;
    *(uint32_t*)(((uint32_t) UserProcess_3_Stack_GArr) + sizeof(UserProcess_3_Stack_GArr) - (2 * 4)) = (uint32_t)UserProcess_3_PCB_GV.processEntry;



    List_InitEmptyList_typeFunc(&(PCB_Container_GV.listHead));

    List_InsertToHead_typeFunc(&(UserProcess_1_PCB_GV.node), &(PCB_Container_GV.listHead));
    List_InsertToHead_typeFunc(&(UserProcess_2_PCB_GV.node), &(PCB_Container_GV.listHead));
    List_InsertToHead_typeFunc(&(UserProcess_3_PCB_GV.node), &(PCB_Container_GV.listHead));


    /* Add process here END */

    // 将当前执行的进程设置为进程0
//    CurrentProcess_Ptr_GV = &UserProcess_0_PCB_GV;
    CurrentProcess_Ptr_GV = NULL;


//    __set_PSP((((uint32_t) UserProcess_1_Stack_GArr) + sizeof(UserProcess_1_Stack_GArr))); // Set PSP to top of task 0 stack




//    printf("[DEBUG] UserProcess_0_Func Entry addr: %08lx, UserProcess_1_Func Entry addr: %08lx\r\n", UserProcess_0_Func,
//           UserProcess_1_Func);
//    printf("[DEBUG] processStackPointer1 addr: %08lx, processStackPointer2 addr: %08lx\r\n", UserProcess_0_PCB_GV.processStackPointer, UserProcess_1_PCB_GV.processStackPointer);

//    __set_PSP(CurrentProcess_Ptr_GV->processStackPointer + 16*4);


//    extern volatile uint8_t SC_Mutex_GV;
//    printf("[DEBUG] SC_Mutex_GV: %hhu\r\n", SC_Mutex_GV);
//    extern volatile uint8_t Shared_Counter_GV;
//    printf("[DEBUG] Shared_Counter_GV: %hhu\r\n", Shared_Counter_GV);

//    printf("[DEBUG] Addr of Shared_Counter_GV: %08x  PCB_Container_GV: %08x\r\n", &Shared_Counter_GV, &((PCB_Container_GV.listHead).prev));
//    SC_Mutex_GV = 0;
//    Shared_Counter_GV = 0;


    __set_CONTROL(0x3);        // Switch to use Process Stack, unprivileged state
//    printf("[DEBUG] At init() -- __set_CONTROL(0x3)\r\n");
//    HAL_Delay(1000);
    __ISB();                            // Execute ISB after changing CONTROL (architectural recommendation)
                                        // 清空流水线（指令集建议）
    InitFinish_Flag_GV = 1;             // 立起flag以允许进程切换
//    printf("[DEBUG] At init() -- Init finish\r\n");



    while(1) {}                         // 等待进程切换的中断，防止函数返回后跑飞
//    UserProcess_0_Func();

}

void loop() {
    // do nothing
}