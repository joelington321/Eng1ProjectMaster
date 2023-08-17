#ifndef _FLOWIMPL_HPP_
#define _FLOWIMPL_HPP_

#include"flow.hpp"
#include"handleBodySemDebug.h"

class FlowBody: public Body {
protected:
  std::string name;
  System* systemSource;
  System* systemTarget;
public:
  /**
   * @brief Get the Name object
   * 
   * @return std::string 
   */
  virtual std::string getName() const;
  /**
   * @brief Set the Name object
   * @param string new Flow's Name
   */
  virtual void setName(std::string);
  /**
   * @brief Get the Source object
   * 
   * @return System* Pointer of the source system
   */
  virtual System* getSource() const;
  /**
   * @brief Set the Source object
   * @param System pointer of Flow's source
   */
  virtual void setSource(System*);
  /**
   * @brief Get the Target object
   * 
   * @return System* Pointer if the target system
   */
  virtual System* getTarget() const;
  /**
   * @brief Set the Target object
   * @param System pointer of Flow's Target
   */
  virtual void setTarget(System*);

  /**
   * @brief Execute command the flow math method
   * 
   * @attention It is necessary to create a class that inherits from Flow and defines the calculation that transforms the input and/or output systems
   * @return Float Returns floating point value and changes source and target systems
   */
  float execute();
};

class FlowHandle: public Flow, public Handle<FlowBody> {
public:
  FlowHandle(std::string name, System* source, System* target){
      pImpl_->setName(name);
      pImpl_->setSource(source);
      pImpl_->setTarget(target);
  }

  std::string getName() const {
    return pImpl_->getName();
  }

  void setName(std::string n) {
    pImpl_->setName(n);
  }

  System *getSource() const{
      return pImpl_->getSource();
  }

  System *getTarget() const{
      return pImpl_->getTarget();
  }

  void setSource(System* ssource){
      pImpl_->setSource(ssource);
  }

  void setTarget(System* starget){
      pImpl_->setTarget(starget);
  }

  float execute(){
      return pImpl_->execute();
  }
};

#endif /* _FLOWIMPL_HPP_ */