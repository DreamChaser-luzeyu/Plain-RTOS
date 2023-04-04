//
// Created by dream on 2023/3/31.
//

#include "Semaphore.h"

/**
 *
 * @param addr
 * @return 1 - failed  0 - success
 */
static uint8_t test_and_set_bit(uint8_t* addr) {
    if(!__LDREXB(addr)) {
        // return 0 - success / return 1 - mem modified
        return __STREXB(1, addr);
    }
    return 1;       // Bit already set
}

void SpinMutex_Lock_apiFunc(volatile uint8_t* lock) {
    while((*lock) || test_and_set_bit(lock));
}

void SpinMutex_Unlock_apiFunc(volatile uint8_t* lock) {
    *lock = 0;
}