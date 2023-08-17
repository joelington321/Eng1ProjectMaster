#include"unit_model.hpp"
#include"../Flows/test_flow.hpp"

#include<assert.h>
#include<iostream>

void run_unit_test_Model(){
  run_unit_test_constructors();
  std::cout << "-----------------" << std::endl;
  std::cout << "Constructors: Ok!" << std::endl;
  
  run_unit_test_destructor();
  std::cout << "-----------------" << std::endl;
  std::cout << "destructor: Ok!" << std::endl;
  
  unit_Model_getName();
  std::cout << "-----------------" << std::endl;
  std::cout << "getName: Ok!" << std::endl;  
  
  unit_Model_setName();
  std::cout << "-----------------" << std::endl;
  std::cout << "setName: Ok!" << std::endl;  
  
  unit_Model_addSystem();
  std::cout << "-----------------" << std::endl;
  std::cout << "addSystem: Ok!" << std::endl;  
  
  unit_Model_addFlow();
  std::cout << "-----------------" << std::endl;
  std::cout << "addFlow: Ok!" << std::endl;  
  
  unit_Model_removeSystem();
  std::cout << "-----------------" << std::endl;
  std::cout << "removeSystem: Ok!" << std::endl;  
  
  unit_Model_removeFlow();
  std::cout << "-----------------" << std::endl;
  std::cout << "removeFlow: Ok!" << std::endl;  
  
  unit_Model_clear();
  std::cout << "-----------------" << std::endl;
  std::cout << "clear: Ok!" << std::endl;  
  
  unit_Model_run();  
  std::cout << "-----------------" << std::endl;
  std::cout << "run: Ok!" << std::endl;  
  std::cout << "-----------------" << std::endl;
}
void run_unit_test_constructors(){
  run_unit_test_void_constructor();
  run_unit_test_param_constructor();
}
void run_unit_test_void_constructor(){
  Model* m = Model::createModel();
  assert(m->getName() == "");
  delete m;
}
void run_unit_test_param_constructor(){
  std::string name = "model";
  Model* m = Model::createModel(name);
  assert(m->getName() == name);
  delete m;
}

void run_unit_test_destructor(){}

void unit_Model_getName(){
  Model* m = Model::createModel();
  assert(m->getName() == "");
  delete m;
}

void unit_Model_setName(){
  std::string name = "set";
  Model* m = Model::createModel();
  m->setName(name);
  assert(m->getName() == name);
  delete m;
}

void unit_Model_addSystem(){
  Model* m = Model::createModel();
  System* s = NULL;
  System* s2 = NULL;
  m->add(s);
  m->add(s2);

  int i = 0;
  for(Model::iteratorSystem it = m->systemBegin(); it < m->systemEnd(); it++){
    i++;
  }
  assert(i == 2);
  delete m;
}

void unit_Model_addFlow(){
  Model* m = Model::createModel();
  Flow * f = NULL;
  Flow* f2 = NULL;
  m->add(f);
  m->add(f2);

  int i = 0;
  for(Model::iteratorFlow it = m->flowBegin(); it < m->flowEnd(); it++){
    i++;
  }
  assert(i == 2);
  delete m;
}

void unit_Model_removeSystem(){
  Model *m = Model::createModel();
  System* s1 = m->createSystem("s1", 100.0);
  System* s2 = m->createSystem("s2", 0.0);
  m->remove(s2);
  int i = 0;
  for(Model::iteratorSystem it = m->systemBegin(); it < m->systemEnd(); it++){
    i++;
  }
  assert(i == 1);
  delete m;
}

void unit_Model_removeFlow() {
  Model *m = Model::createModel();
  Flow *f1 = m->createFlow<Logistic>("fluxoLogistico");
  Flow *f2 = m->createFlow<Logistic>("fluxoLogistico");
  m->remove(f2);
  int i = 0;
  for(Model::iteratorFlow it = m->flowBegin(); it < m->flowEnd(); it++){
    i++;
  }
  assert(i == 1);
  delete m;
}

void unit_Model_clear(){
  Model *m = Model::createModel();
  System* s1 = m->createSystem("s1", 100.0);
  System* s2 = m->createSystem("s2", 0.0);
  Flow *f1 = m->createFlow<Logistic>("fluxoLogistico");
  Flow *f2 = m->createFlow<Exponential>("fluxoLogistico");
  int i = 0;
  for(Model::iteratorSystem it = m->systemBegin(); it < m->systemEnd(); it++){
    i++;
  }
  assert(i == 2);
  int j = 0;
  for(Model::iteratorFlow it = m->flowBegin(); it < m->flowEnd(); it++){
    j++;
  }
  assert(j == 2);

  m->clear();
  i = 0;
  for(Model::iteratorSystem it = m->systemBegin(); it < m->systemEnd(); it++){
    i++;
  }
  assert(i == 0);
  j = 0;
  for(Model::iteratorFlow it = m->flowBegin(); it < m->flowEnd(); it++){
    j++;
  }
  assert(j == 0);
  
  delete m;
}

void unit_Model_run(){
  Model *m = Model::createModel();
  System *s = m->createSystem("s", 10);
  System *s2 = m->createSystem("s", 1000);
  Flow *f = m->createFlow<Exponential>("f", s2, s);
  m->run(0, 10, 1);

  // std::cout << s->getEnergy() << std::endl;
  // std::cout << s2->getEnergy() << std::endl;

  assert(s->getEnergy() - 105.618 < 0.0001);
  assert(s2->getEnergy() - 904.382 < 0.0001);
  
  delete m;
}