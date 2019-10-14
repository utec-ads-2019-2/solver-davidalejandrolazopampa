//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_NUMERO_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_NUMERO_H

#include "Cal.h"
class Numero : public cal {
    int numero=0;
public:
    Numero(string dato):cal(dato){
        numero = atoi(dato.c_str());
        operatorr = false;
        tipo = 'C';
    };
    Datos execute() override {
        return this->numero;
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_NUMERO_H
