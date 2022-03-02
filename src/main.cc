#include <iostream>

#include "utils/logger.h"
#include "utils/timer.h"

using namespace MonotropicOptimization;

int main() {
    LOG(ALL, "hello world!");
    TIC()
    for (auto i=0; i < 10000; i++) {
        
    }
    TOC(DEBUG)
}