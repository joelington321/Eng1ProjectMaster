#ifndef _UNIT_MODEL_HPP_
#define _UNIT_MODEL_HPP_

#include"../../src/include/model.hpp"

/**
 * @brief Function that call all Model unit tests
 * 
 */
void run_unit_test_Model();
/**
 * @brief Function that call all type of Model's constructor unit tests
 * 
 */
void run_unit_test_constructors();
/**
 * @brief Unit test of void constructor
 * 
 */
void run_unit_test_void_constructor();
/**
 * @brief Unit test of Model constructor with params
 * 
 */
void run_unit_test_param_constructor();
/**
 * @brief Unit test of Model's destructor
 * 
 */
void run_unit_test_destructor();
/**
 * @brief Unit test of getName
 * 
 */
void unit_Model_getName();
/**
 * @brief Unit test of Model's setName
 * 
 */
void unit_Model_setName();
/**
 * @brief Unit test of add System
 * 
 */
void unit_Model_addSystem();
/**
 * @brief Unit test of add Flow
 * 
 */
void unit_Model_addFlow();
/**
 * @brief Unit test of remove System
 * 
 */
void unit_Model_removeSystem();
/**
 * @brief Unit test of remove Flow
 * 
 */
void unit_Model_removeFlow();
/**
 * @brief Unit test of clear
 * 
 */
void unit_Model_clear();
/**
 * @brief Unit test of run
 * 
 */
void unit_Model_run();

#endif /* _UNIT_MODEL_HPP_ */