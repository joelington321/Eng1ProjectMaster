#ifndef _UNIT_SYSTEMS_HPP_
#define _UNIT_SYSTEMS_HPP_

#include"../../src/include/system.hpp"

/**
 * @brief Function that call all unit system functions 
 * 
 */
void run_unit_test_System();
/**
 * @brief Function that call all types of contructor of System
 * 
 */
void unit_System_constructors();
/**
 * @brief Unit test of void constructor
 * 
 */
void unit_System_void_constructor();
/**
 * @brief Unit test of constructor with params
 * 
 */
void unit_System_param_constructor();
/**
 * @brief Unit test of copy constructor
 * 
 */
void unit_System_copy_constructor();
/**
 * @brief Unit test of destructor
 * 
 */
void unit_System_destructor();
/**
 * @brief Unit test of getName
 * 
 */
void unit_System_getName();
/**
 * @brief Unit test of setName
 * 
 */
void unit_System_setName();
/**
 * @brief Unit test of getEnergy
 * 
 */
void unit_System_getEnergy();
/**
 * @brief Unit test of setEnergy
 * 
 */
void unit_System_setEnergy();

#endif /* _UNIT_SYSTEMS_HPP_ */