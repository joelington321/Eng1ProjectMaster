#ifndef _MODELIMPL_HPP_
#define _MODELIMPL_HPP_

#include"model.hpp"
#include"handleBodySemDebug.h"
#include<vector>

/**
 * @class ModelImpl
 * 
 * @brief Model implementation class
 * 
 */
class ModelBody: public Body{
protected:
  std::string name;
  std::vector<System*> systems;
  std::vector<Flow*> flows;
  static std::vector<Model*> models;
public:
  /**
   * @brief Destroy the Model Body object
   * 
   */
  ~ModelBody();
  /**
   * @brief iterator flow structure begin
   * 
   * @return iteratorFlow returns the beginning of the flows that are in the models
   */
  Model::iteratorFlow flowBegin();
  /**
   * @brief iterator flow structure end
   * 
   * @return iteratorFlow The end of the flows that are in the models
   */
  Model::iteratorFlow flowEnd();
  /**
   * @brief iterator system structure begin
   * 
   * @return iteratorSystem The beginning of the systems that are in the models
   */
  Model::iteratorSystem systemBegin();
  /**
   * @brief iterator system structure end
   * 
   * @return iteratorSystem The end of the systems that are in the models
   */
  Model::iteratorSystem systemEnd();

  /**
   * @brief Get the Name object
   * 
   * @return String Reference name of the Model
   */
  virtual std::string getName() const;
  /**
   * @brief Set the Name object
   * @param string new Model's name
   */
  void setName(std::string);

  /**
   * @brief Add System pointer to data structure
   * @param System* pointer of system that will add to Model's data struct
   */
  void add(System*);
  /**
   * @brief Add Flow pointer to data structure
   *  @param Flow* pointer of flow that will add to Model's data struct
   */
  void add(Flow*);

  /**
   * @brief remove a System pointer to data structure
   *  @param System* pointer of system that will be delete in Model's data struct
   */
  void remove(System*);
  /**
   * @brief remove a Flow pointer to data structure
   *  @param Flow* pointer of flow that will be delete in Model's data struct
   */
  void remove(Flow*);

  /**
   * @brief clean all pointers of Flows and Systems
   * 
   */
  void clear();

  /**
   * @brief Run simulation framework
   * 
   * @param initialTime represents the initial time value of the simulation
   * @param finalTime represents the final time value of the simulation
   * @param increment represents how the system simulator time will flow
   */
  virtual void run(int initialTime, int finalTime, int increment);

    /**
   * @brief Create a Model object
   * 
   * @return Model* 
   * @param string that represents the name of Model
   */
  static Model* createModel(std::string);

  /**
   * @brief Create a System object
   * 
   * @return System* 
   * @param string that represents the name of System
   * @param int value of System's energy
   */
  System* createSystem(std::string, float);
};

class ModelHandle: public Model, public Handle<ModelBody> {
public:
  ModelHandle(std::string name){
    pImpl_->setName(name);
  }

  Model::iteratorSystem systemBegin(){
    pImpl_->systemBegin();
  }
  Model::iteratorSystem systemEnd(){
    pImpl_->systemEnd();
  }
  Model::iteratorFlow flowBegin(){
    pImpl_->flowBegin();
  }
  Model::iteratorFlow flowEnd(){
    pImpl_->flowEnd();
  }

  void clear(){
    pImpl_->clear();
  }

  void run(int initialTime, int endTime, int increment){
    pImpl_->run(initialTime, endTime, increment);
  }

  void add(System* system){
    pImpl_->add(system);
  }

  void add(Flow* flow){
    pImpl_->add(flow);
  }

  void remove(System* system){
    pImpl_->remove(system);
  }

  void remove(Flow* flow){
    pImpl_->remove(flow);
  }

  std::string getName() const {
    return pImpl_->getName();
  }

  void setName(std::string sName){
    pImpl_->setName(sName);
  }

  std::vector<System*>::iterator SystemBegin(void){
    return pImpl_->systemBegin();
  }

  std::vector<System*>::iterator SystemEnd(void){
    return pImpl_->systemEnd();
  }

  std::vector<Flow*>::iterator FlowBegin(void){
    return pImpl_->flowBegin();
  }

  std::vector<Flow*>::iterator FlowEnd(void){
    return pImpl_->flowEnd();
  }

  System* createSystem(std::string name, float energy){
    return pImpl_->createSystem(name, energy);
  }
};

#endif /* _MODEL_HPP_ */