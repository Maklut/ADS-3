// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_val = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > max_val) {
            max_val = num;
        }
    }
    return max_val;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int best_num = lbound;
    unsigned int best_len = collatzLen(lbound);

    for (uint64_t i = lbound + 1; i <= rbound; i++) {
        unsigned int current_len = collatzLen(i);
        if (current_len > best_len) {
            best_len = current_len;
            best_num = i;
        }
    }

    *maxlen = best_len;
    return best_num;
}
