#include "easyco.h"
#include <iostream>

int main(int argn, char*[] argv) {

    if (easyco_init() != 0) {
        std::cout << easyco_error() << std::endl;
        return -1;
    }

    int rc = easyco_create(NULL, [] {
        
    });

    if (rc != 0) {
        std::cout << easyco_error() << std::endl;
        return -1;
    }
    
    if (easyco_run() != 0) {
        std::cout << easyco_error() << std::endl;
        return -1;
    }
    easyco_unit();
    return 0;
}
