#include"../include/modelImpl.hpp"
#include"../include/flow.hpp"
#include"../include/systemImpl.hpp"
#include"../include/system.hpp"


std::vector <Model*> ModelBody::models;

ModelBody::~ModelBody(){
  for(System *system : systems){
    if (system !=NULL)
      delete system;
  }

  for(Flow *flow : flows){
    if (flow !=NULL)
      delete flow;
  }

  for(auto itModel = models.begin(); itModel < models.end(); itModel++){
    if ((*itModel) == (Model*)this)
          models.erase(itModel);
  }
}

std::string ModelBody::getName() const{
  return name;
}
void ModelBody::setName(std::string n){
  name = n;
}

Model::iteratorFlow ModelBody::flowBegin(){
  return flows.begin();
}

Model::iteratorFlow ModelBody::flowEnd(){
  return flows.end();
}
Model::iteratorSystem ModelBody::systemBegin(){
  return systems.begin();
}
Model::iteratorSystem ModelBody::systemEnd(){
  return systems.end();
}

void ModelBody::add(System* addSystem){
  systems.push_back(addSystem);
}
void ModelBody::add(Flow* addFlow){
  flows.push_back(addFlow);
}

void ModelBody::remove(System* system2Remove){
  for(Model::iteratorSystem it = systemBegin(); it <= systemEnd(); it++){
    if((*it) == system2Remove)
      systems.erase(it);
  }
}
void ModelBody::remove(Flow* flow2Remove){
  for(auto it = flowBegin(); it <= flowEnd(); it++){
    if(*it == flow2Remove)
      flows.erase(it);
  }
}

void ModelBody::clear(){
  setName("");
  systems.clear();
  flows.clear();
}

void ModelBody::run(int initialTime = 0, int finalTime = 100, int increment = 1){
  Model::iteratorFlow it = flows.begin();
  System *source, *target;
  std::vector<float> flowChanges;
  for(unsigned int i = 0; i < flows.size(); i++)
    flowChanges.push_back(0.0);

  for(int i = initialTime; i < finalTime; i+=increment){
    it = flows.begin();
    for(unsigned int j = 0; j < flows.size(); j++){
      flowChanges[j] = (*it)->execute();
      it++;
    }
    for(unsigned int j = 0; j < flows.size(); j++){
      source = flows[j]->getSource();
      target = flows[j]->getTarget();

      source->setEnergy(source->getEnergy() - flowChanges[j]);
      target->setEnergy(target->getEnergy() + flowChanges[j]);
    }

  }
}

Model* Model::createModel(std::string name){   
    return ModelBody::createModel(name);
}

Model* ModelBody::createModel(std::string name){
  Model* m = new ModelHandle(name);
  models.push_back(m);
  return m;
}

System* ModelBody::createSystem(std::string name = "", float e = 0.0){
    System* system = new SystemHandle(name, e);
    add(system);
    return system;
}