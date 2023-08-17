#include "unit_handlebody.hpp"
#include <cstdlib>
#include <iostream>

#include "../../src/include/model.hpp"
#include "../../src/include/systemImpl.hpp"
#include "../../src/include/handleBodySemDebug.h"

#include "../Flows/test_flow.hpp"

using namespace std;

int numHandleDeleted = 0;
int numHandleCreated = 0;
int numBodyCreated = 0;
int numBodyDeleted = 0;

void run_unit_handle_body()
{
    // zerando contadores
    numHandleDeleted = 0;
    numHandleCreated = 0;
    numBodyCreated = 0;
    numBodyDeleted = 0;
    cout << "\n------------------------\nTESTE HANDLE BODY\n------------------------" << endl;

    Model *m = Model::createModel("Modelo Populacional");
    System *s1 = m->createSystem("populacao", 10.0);
    System *s2 = m->createSystem("Teste", 7.90);
    Flow *f1 = m->createFlow<Logistic>("Logistc", s1, s2);

    // USANDO REFERENCIAS PARA INTERFACE (CLASSE ABSTRATA)
    // System& s1 = m.createSystem("populacao",10.0);
    // System& s2 = m.createSystem("Teste", 7.90)   ;
    // cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;
    // s1 = s2;  // nao funciona pq s1 eh uma referencia, portanto nao pode ser redefinida
    // cout << "s1: " << s1.getName() << ", s2: " <<  s2.getName() << endl;

    // USANDO PONTEIROS PARA INTERFACE (CLASSE ABSTRATA)
    ;
    cout << "s1: " << s1->getName() << ", s2: " << s2->getName() << endl;
    // s1 = s2;
    *s1 = *s2;
    cout << "s1: " << s1->getName() << ", s2: " << s2->getName() << endl;
    cout << "s1: " << s1 << ", s2: " << s2 << endl;

    // Faca o teste COM e SEM as chaves abaixo
    {
        // USANDO OBJETOS HANDLES (DELEGACAO)
        SystemHandle s3("tiago", 7), s4("joelington", 8);
        cout << "s3: " << s3.getName() << ", s2: " << s4.getName() << endl;
        s3 = s4; // comente esta linha e veja que o resultado muda
        cout << "s3: " << s3.getName() << ", s2: " << s4.getName() << endl;
        s3 = s3;
        cout << "s3: " << s3.getName() << ", s2: " << s4.getName() << endl;
    }

    // executa o modelo
    m->run(0, 30, 1);

    // imprime relatorio
    // cout << s1.getValue() << endl;
    cout << s1->getEnergy() << endl;
    cout << "Created handles: " << numHandleCreated << endl;
    cout << "Deleted handles: " << numHandleDeleted << endl;
    cout << "Created bodies: " << numBodyCreated << endl;
    cout << "Deleted bodies: " << numBodyDeleted << endl;
    // system("PAUSE");
    // return EXIT_SUCCESS;
    return;
}