#ifndef __MAIN_H
#define __MAIN_H
#include "main.hpp"
#endif

double getAvgDrivetrainTemp() {
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += leftMG.get_temperature();
        sum += rightMG.get_temperature();
    }
    return sum * 0.3 + 32;
}