#ifndef _MODEL_HPP_
#define _MODEL_HPP_

#include<string>
#include<vector>

class System;
class Flow;

/**
 * @interface Model 
 * @brief Interface for class Model.
 * 
 * The class Model is the program's main class.
 */
class Model{
public:

  /**
   * @brief Destroy the Model object
   * 
   */
  virtual ~Model(){};

  typedef typename std::vector<Flow*>::iterator iteratorFlow;
  typedef typename std::vector<System*>::iterator iteratorSystem;

  /**
   * @brief iterator flow structure begin
   * 
   * @return iteratorFlow returns the beginning of the flows that are in the models
   */
  virtual iteratorFlow flowBegin() = 0;
  /**
   * @brief iterator flow structure end
   * 
   * @return iteratorFlow The end of the flows that are in the models
   */
  virtual iteratorFlow flowEnd() = 0;
  /**
   * @brief iterator system structure begin
   * 
   * @return iteratorSystem The beginning of the systems that are in the models
   */
  virtual iteratorSystem systemBegin() = 0;
  /**
   * @brief iterator system structure end
   * 
   * @return iteratorSystem The end of the systems that are in the models
   */
  virtual iteratorSystem systemEnd() = 0;

  /**
   * @brief Create a Model object
   * 
   * @return Model* 
   * @param string that represents the name of Model
   */
  static Model* createModel(std::string name = "");
  /**
   * @brief Create a Flow object
   * 
   * @return Flow* 
   * @param string that represents the name of Flow
   * @param System the Flow's source system
   * @param System the Flow's target system
   */
  
  template<typename TYPE>
  Flow* createFlow(std::string name = "", System* s = nullptr, System* t = nullptr){
    Flow* f = new TYPE(name, s, t);
    add(f);
    return f;
  }

  /**
   * @brief Create a System object
   * 
   * @return System* 
   * @param string that represents the name of System
   * @param int value of System's energy
   */
  virtual System* createSystem(std::string, float) = 0;

  /**
   * @brief Get the Name object
   * 
   * @return String Reference name of the Model
   */
  virtual std::string getName() const = 0;
  /**
   * @brief Set the Name object
   * @param string new Model's name
   */
  virtual void setName(std::string) = 0;

  /**
   * @brief Add System pointer to data structure
   * @param System* pointer of system that will add to Model's data struct
   */
  virtual void add(System*) = 0;
  /**
   * @brief Add Flow pointer to data structure
   *  @param Flow* pointer of flow that will add to Model's data struct
   */
  virtual void add(Flow*) = 0;

  /**
   * @brief remove a System pointer to data structure
   *  @param System* pointer of system that will be delete in Model's data struct
   */
  virtual void remove(System*) = 0;
  /**
   * @brief remove a Flow pointer to data structure
   *  @param Flow* pointer of flow that will be delete in Model's data struct
   */
  virtual void remove(Flow*) = 0;

  /**
   * @brief clean all pointers of Flows and Systems
   * 
   */
  virtual void clear() = 0;

  /**
   * @brief Run simulation framework
   * 
   * @param initialTime represents the initial time value of the simulation
   * @param finalTime represents the final time value of the simulation
   * @param increment represents how the system simulator time will flow
   */
  virtual void run(int initialTime, int finalTime, int increment) = 0;
};

#endif /* _MODEL_HPP_ */