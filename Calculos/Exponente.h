//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_EXPONENTE_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_EXPONENTE_H

#include "Cal.h"
class Exponente : public cal{
public:
    Exponente(string dato): cal(dato){
        pct = 3;
        operatorr = true;
        tipo ='^';
    };
    Datos execute() override {
        auto X = getLeft()->execute();
        auto Y = getRight()->execute();
        return pow(X,Y);
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_EXPONENTE_H
