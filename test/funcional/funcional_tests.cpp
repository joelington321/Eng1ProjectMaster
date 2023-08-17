#include"funcional_tests.hpp"
#include"../Flows/test_flow.hpp"
#include<assert.h>
#include<cmath>
#include<iostream>

void exponentialFuncionalTest(){

    Model* model = Model::createModel("exponencial");
    System* s1 = model->createSystem("s1", 100.0);
    System* s2 = model->createSystem("s2", 0.0);
    Flow *flow = model->createFlow<Exponential>("Exponencial", s1, s2);    
    model->run(0, 100, 1);

    // model->show();

    assert(round((s1->getEnergy() - 36.6032) * 10000) == 0);
    assert(round((s2->getEnergy() - 63.3968) * 10000) == 0);


    delete model;
}

void logisticalFuncionalTest(){

    Model *model = Model::createModel("Modelo Logistico");
    System *p1 = model->createSystem("p1", 100.0);
    System *p2 = model->createSystem("p2", 10.0);
    Flow *flow = model->createFlow<Logistic>("fluxoLogistico", p1, p2);
    

    model->run(0, 100, 1);
    // // model->show();
    assert(round((p1->getEnergy() - 88.2167) * 10000) == 0);
    assert(round(p2->getEnergy() - 21.7833) * 10000 == 0);

    delete model;
}

void complexFuncionalTest(){

    Model* model = Model::createModel("Modelo Complexo");
    System* q1 = model->createSystem("q1", 100.0);
    System* q2 = model->createSystem("q2", 0.0);
    System* q3 = model->createSystem("q3", 100.0);
    System* q4 = model->createSystem("q4", 0.0);
    System* q5 = model->createSystem("q5", 0.0);
    Flow *f = model->createFlow<Exponential>("f", q1, q2);
    Flow *t = model->createFlow<Exponential>("t", q2, q3);
    Flow *u = model->createFlow<Exponential>("u", q3, q4);
    Flow *v = model->createFlow<Exponential>("v", q4, q1);
    Flow *g = model->createFlow<Exponential>("g", q1, q3);
    Flow *r = model->createFlow<Exponential>("r", q2, q5);
    
    model->run(0, 100, 1);
    // // model->show();

    assert(round((q1->getEnergy() - 31.8513) * 10000) == 0);
    assert(round((q2->getEnergy() - 18.4003) * 10000) == 0);
    assert(round((q3->getEnergy() - 77.1143) * 10000) == 0);
    assert(round((q4->getEnergy() - 56.1728) * 10000) == 0);
    assert(round((q5->getEnergy() - 16.4612) * 10000) == 0);

    delete model;
}