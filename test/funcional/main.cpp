#include<iostream>
#include "funcional_tests.hpp"

int main(){
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    std::cout << "All functional tests passed!" << std::endl;
    return 0;
}