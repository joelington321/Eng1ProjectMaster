#include"../include/flowImpl.hpp"
#include"../include/system.hpp"
#include<iostream>

std::string FlowBody::getName() const{
  return name;
}

void FlowBody::setName(std::string n){
  name = n;
}

System* FlowBody::getSource() const {
  return systemSource;
}
void FlowBody::setSource(System* s){
  systemSource = s;
}
System* FlowBody::getTarget() const{
  return systemTarget;
}
void FlowBody::setTarget(System* t){
  systemTarget = t;
}

float FlowBody::execute(){
  return 0.0;
}