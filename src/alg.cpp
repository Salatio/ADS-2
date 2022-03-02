// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (0 == n)
        return 1;
    else
        return pown(value, n - 1) * value;
}

uint64_t fact(uint16_t n) {
    if (1 == n)
        return 1;
    else
        return fact(n - 1) * n;
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    if (0 == count)
        return 1;
    else
        return calcItem(x, count) + expn(x, count - 1);
}

double sinn(double x, uint16_t count) {
    if (1 == count)
        return x;
    else {
        int n = 2 * count - 1;
        if (0 == count % 2) {
            return -1 * calcItem(x, n) + sinn(x, count - 1);
        } else
              return calcItem(x, n) + sinn(x, count - 1);
    }
}

double cosn(double x, uint16_t count) {
    if (1 == count)
        return 1;
    else {
        int n = 2 * count - 2;
        if (0 == count % 2) {
            return -1 * calcItem(x, n) + cosn(x, count - 1);
        } else {
              return calcItem(x, n) + cosn(x, count - 1);
          }
    }
}
