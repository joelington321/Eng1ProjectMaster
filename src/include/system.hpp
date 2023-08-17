#ifndef _SYSTEM_HPP_
#define _SYSTEM_HPP_

#include<string>

/**
 * @interface System
 * @brief Interface for class system.
 *
 * This class system has a name and an energy value.
 */
class System {
public:
  /**
   * @brief Destroy the System object
   * 
   */
  virtual ~System(){};
  /**
   * @brief Get the Energy object
   * 
   * @return float 
   */
  virtual float getEnergy() const = 0;
  /**
   * @brief Set the Energy object
   * @param float new value of energy
   */
  virtual void setEnergy(float) = 0;
  /**
   * @brief Get the Name object
   * 
   * @return std::string 
  */
  virtual std::string getName() const = 0;
  /**
   * @brief Set the Name object
   * @param string new System's name
   */
  virtual void setName(std::string) = 0;
};

#endif /* _SYSTEM_HPP_ */