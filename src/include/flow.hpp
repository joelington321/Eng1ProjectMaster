#ifndef _FLOW_HPP_
#define _FLOW_HPP_

#include<string>
#include"system.hpp"

/**
 * 
 * @interface Flow
 * @brief Interface for class flow.
 *
 * The class flow is used to tranport energy from and/or to a system.
 */
class Flow{
public:
  /**
   * @brief Destroy the Flow object
   * 
   */
  virtual ~Flow(){};
  /**
   * @brief Get the Name object
   * 
   * @return std::string 
   */
  virtual std::string getName() const = 0;
  /**
   * @brief Set the Name object
   * @param string new Flow's Name
   */
  virtual void setName(std::string) = 0;
  /**
   * @brief Get the Source object
   * 
   * @return System* Pointer of the source system
   */
  virtual System* getSource() const = 0;
  /**
   * @brief Set the Source object
   * @param System pointer of Flow's source
   */
  virtual void setSource(System*) = 0;
  /**
   * @brief Get the Target object
   * 
   * @return System* Pointer if the target system
   */
  virtual System* getTarget() const = 0;
  /**
   * @brief Set the Target object
   * @param System pointer of Flow's Target
   */
  virtual void setTarget(System*) = 0;

  /**
   * @brief Execute command the flow math method
   * 
   * @attention It is necessary to create a class that inherits from Flow and defines the calculation that transforms the input and/or output systems
   * @return Float Returns floating point value and changes source and target systems
   */
  virtual float execute() = 0;

};

#endif /* _FLOW_HPP_ */