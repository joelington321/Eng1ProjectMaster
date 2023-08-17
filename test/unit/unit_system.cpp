#include"unit_system.hpp"
#include"../../src/include/systemImpl.hpp"
#include<iostream>
#include<assert.h>

void run_unit_test_System(){
  unit_System_constructors();
  std::cout << "-----------------" << std::endl;
  std::cout << "Constructors: Ok!" << std::endl;
  unit_System_destructor();
  std::cout << "-----------------" << std::endl;
  std::cout << "Desstructor: Ok!" << std::endl;
  unit_System_getName();
  std::cout << "-----------------" << std::endl;
  std::cout << "getName: Ok!" << std::endl;
  unit_System_setName();
  std::cout << "-----------------" << std::endl;
  std::cout << "setName: Ok!" << std::endl;
  unit_System_getEnergy();
  std::cout << "-----------------" << std::endl;
  std::cout << "getEnergy: Ok!" << std::endl;
  unit_System_setEnergy();
  std::cout << "-----------------" << std::endl;
  std::cout << "setEnergy: Ok!" << std::endl;
  std::cout << "-----------------" << std::endl;
}

void unit_System_constructors(){
  unit_System_void_constructor();
  unit_System_param_constructor();
  unit_System_copy_constructor();
}
void unit_System_void_constructor(){
  System* s = new SystemHandle("s", 0.0);
  
  assert(s->getName() == "s" && s->getEnergy() == 0.0);
  delete s;
}
void unit_System_param_constructor(){
  std::string name = "sistema";
  float energy = 5.7;
  System* s = new SystemHandle(name, energy);
  assert(s->getName() == name);
  assert(s->getEnergy() == energy);
  delete s;
}
void unit_System_copy_constructor(){
  std::string name = "sistema";
  float e = 1.1;
  System* s = new SystemHandle(name, e);
  System* s1 = new SystemHandle(s->getName(), s->getEnergy());
  assert(s1->getName() == name && s1->getEnergy() == e);
  delete s;
  delete s1;
}


void unit_System_destructor(){}
void unit_System_getName(){
  System* s = new SystemHandle("", 0.0);
  assert(s->getName() == "");
  delete s;
}
void unit_System_setName(){
  System* s = new SystemHandle("", 0.0);
  std::string name = "set";
  s->setName(name);
  assert(s->getName() == name);
  delete s;
}
void unit_System_getEnergy(){
  System* s = new SystemHandle("", 0.0);
  assert(s->getEnergy() == 0.0);
  delete s;
}
void unit_System_setEnergy(){
  System* s = new SystemHandle("s", 0.0);
  int e = 1.5;
  s->setEnergy(e);
  assert(s->getEnergy() == e);
  delete s;
}