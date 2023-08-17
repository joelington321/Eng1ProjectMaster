#include"../include/systemImpl.hpp"
#include<iostream>

void SystemBody::setEnergy(float e){
  energy = e;
}

float SystemBody::getEnergy() const {
  return energy;
}

void SystemBody::setName(std::string n){
  name = n;
}

std::string SystemBody::getName() const{
  return name;
}