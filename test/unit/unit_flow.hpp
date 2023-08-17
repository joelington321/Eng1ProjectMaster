#ifndef _UNIT_FLOW_HPP_
#define _UNIT_FLOW_HPP_

#include"../../src/include/flow.hpp"


/**
 * @brief Function that call all flow unit tests
 * 
 */
void run_unit_test_Flow();
/**
 * @brief Function to call all constructors unit tests
 * 
 */
void unit_Flow_constructors();
/**
 * @brief Unit test of void constructor
 * 
 */
void unit_Flow_void_constructor();
/**
 * @brief Unit test constructor with params
 * 
 */
void unit_Flow_param_constructor();
/**
 * @brief Unit test of copy constructor 
 * 
 */
void unit_Flow_copy_constructor();
/**
 * @brief Unit test of destructor 
 * 
 */
void unit_Flow_destructor();
/**
 * @brief Unit test of getName
 * 
 */
void unit_Flow_getName();
/**
 * @brief Unit test of setName
 * 
 */
void unit_Flow_setName();
/**
 * @brief Unit test of getSource
 * 
 */
void unit_Flow_getSource();
/**
 * @brief Unit test of setSource
 * 
 */
void unit_Flow_setSource();
/**
 * @brief Unit test of getTarget
 * 
 */
void unit_Flow_getTarget();
/**
 * @brief Unit test of setTarget
 * 
 */
void unit_Flow_setTarget();
/**
 * @brief Unit test of execute
 * 
 */
void unit_Flow_execute();

#endif /* _UNIT_FLOW_HPP_ */