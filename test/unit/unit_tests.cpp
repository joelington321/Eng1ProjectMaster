#include"unit_tests.hpp"
#include"unit_system.hpp"
#include"unit_flow.hpp"
#include"unit_model.hpp"
#include"unit_handlebody.hpp"
#include<iostream>

void run_unit_tests_globals() {
  std::cout << std::endl << "===========SYSTEM===========" << std::endl;
  std::cout << "Running unit Tests: " << std::endl
            << "System unit tests:  " << std::endl;
  run_unit_test_System();
  std::cout << "======UNIT SYSTEM PASSED======" << std::endl;
  std::cout << std::endl << "============FLOW============" << std::endl;
  std::cout << "Flow unit tests:  " << std::endl;
  run_unit_test_Flow();
  std::cout << "=====UNIT FLOW PASSED=======" << std::endl;
  std::cout << std::endl << "===========MODEL===========" << std::endl;
  std::cout << "Model unit tests:  " << std::endl;
  run_unit_test_Model();
  std::cout  << "======UNIT MODEL PASSED======" << std::endl;
  std::cout << "Handle unit tests:  " << std::endl;
  run_unit_handle_body();
  std::cout  << "======UNIT HANDLE PASSED======" << std::endl
            << std::endl << "ALL UNIT TESTS PASSED" << std::endl;
}