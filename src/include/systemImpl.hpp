#ifndef _SYSTEMIMPL_HPP_
#define _SYSTEMIMPL_HPP_

#include"system.hpp"
#include"handleBodySemDebug.h"

class SystemBody: public Body{
protected:
  std::string name;
  float energy;
public:
  /**
   * @brief Get the Energy object
   * 
   * @return float 
   */
  virtual float getEnergy() const;
  /**
   * @brief Set the Energy object
   * @param float new value of energy
   */
  virtual void setEnergy(float);
  /**
   * @brief Get the Name object
   * 
   * @return std::string 
  */
  virtual std::string getName() const;
  /**
   * @brief Set the Name object
   * @param string new System's name
   */
  virtual void setName(std::string);
};

class SystemHandle: public System, public Handle<SystemBody> {
public:
  SystemHandle(std::string name, float energy){
  pImpl_->setName(name);
  pImpl_->setEnergy(energy);
  }
  float getEnergy() const{
      return pImpl_->getEnergy();
  }
  void setEnergy(float value){
      pImpl_->setEnergy(value);
  }
  std::string getName() const{
      return pImpl_->getName();
  }
  void setName(std::string name){
      pImpl_->setName(name);
  }
};


#endif /* _SYSTEMIMPL_HPP_ */