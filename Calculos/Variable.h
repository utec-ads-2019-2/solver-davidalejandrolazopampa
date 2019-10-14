//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_VARIABLE_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_VARIABLE_H

#include "Cal.h"
class Variable : public cal{
    int valor;
public:
    Variable(string dato):cal(dato){
            valor = 0;
            operatorr = false;
            tipo = 'V';
    };
    void setValor(int valor){
        Variable::valor=valor;
    }
    Datos execute() override {
        return valor;
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_VARIABLE_H
