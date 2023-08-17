#include"unit_flow.hpp"

#include<assert.h>
#include<iostream>
#include"../../src/include/flowImpl.hpp"
#include"../../src/include/systemImpl.hpp"

#define EXECUTE_RETURN 10.5

/**
 * @class UnitFlow
 * 
 * @brief Class to perform unit tests of Flow
 * 
 */
class UnitFlow: public FlowHandle{
public:
  UnitFlow(std::string name = "", System* systemSource = nullptr, System* systemTarget = nullptr): FlowHandle(name, systemSource, systemTarget){}
  ~UnitFlow(){}
  virtual float execute() override{
    return EXECUTE_RETURN;
  }
};


void run_unit_test_Flow(){
  unit_Flow_constructors();
  std::cout << "-----------------" << std::endl;
  std::cout << "Constructors: Ok!" << std::endl;  
  unit_Flow_destructor();
  std::cout << "-----------------" << std::endl;
  std::cout << "Destructors: Ok!" << std::endl;  
  unit_Flow_getName();
  std::cout << "-----------------" << std::endl;
  std::cout << "getName: Ok!" << std::endl;  
  unit_Flow_setName();
  std::cout << "-----------------" << std::endl;
  std::cout << "setName: Ok!" << std::endl;  
  unit_Flow_getSource();
  std::cout << "-----------------" << std::endl;
  std::cout << "getSource: Ok!" << std::endl;  
  unit_Flow_setSource();
  std::cout << "-----------------" << std::endl;
  std::cout << "setSource: Ok!" << std::endl;  
  unit_Flow_getTarget();
  std::cout << "-----------------" << std::endl;
  std::cout << "getTarget: Ok!" << std::endl;  
  unit_Flow_setTarget();
  std::cout << "-----------------" << std::endl;
  std::cout << "setTarget: Ok!" << std::endl;  
  unit_Flow_execute();
  std::cout << "-----------------" << std::endl;
  std::cout << "execute: Ok!" << std::endl;  
  std::cout << "-----------------" << std::endl;
}
void unit_Flow_constructors(){
  unit_Flow_void_constructor();
  unit_Flow_param_constructor();
  unit_Flow_copy_constructor();
}
void unit_Flow_void_constructor(){
  Flow* f = new UnitFlow();

  delete f;
}
void unit_Flow_param_constructor(){
  std::string name = "unit";
  System* s = nullptr;
  Flow* f = new UnitFlow(name, s, s);
  assert(f->getName() == name && f->getSource() == s && f->getTarget() == s);
  delete f;
}
void unit_Flow_copy_constructor(){}
void unit_Flow_destructor(){}
void unit_Flow_getName(){
  Flow* f = new UnitFlow();
  assert(f->getName() == "");
  delete f;
}
void unit_Flow_setName(){
  std::string name = "set";
  Flow* f = new UnitFlow();
  f->setName(name);
  assert(f->getName() == name);
  delete f;
}
void unit_Flow_getSource(){
  Flow* f = new UnitFlow();
  assert(f->getSource() == nullptr);
  delete f;
}
void unit_Flow_setSource(){
  System* s = NULL;
  Flow* f = new UnitFlow("name", s, s);
  f->setSource(nullptr);
  assert(f->getSource() == nullptr);
  delete f;
}
void unit_Flow_getTarget(){
  Flow* f = new UnitFlow();
  assert(f->getTarget() == nullptr);
  delete f;
}
void unit_Flow_setTarget(){
  System* s = NULL;
  Flow* f = new UnitFlow("name", s, s);
  f->setTarget(nullptr);
  assert(f->getTarget() == nullptr);
  delete f;
}

void unit_Flow_execute(){
  Flow* f = new UnitFlow();
  assert(f->execute() == EXECUTE_RETURN);
  delete f;
}