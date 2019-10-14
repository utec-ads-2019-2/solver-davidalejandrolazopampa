//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_SUMA_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_SUMA_H

#include "Cal.h"
class Suma : public cal{
public:
    Suma(string dato): cal(dato){
        pct = 1;
        operatorr = true;
        tipo ='+';
    };
    Datos execute() override {
        auto X = getLeft()->execute();
        auto Y = getRight()->execute();
        return (X+Y);
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_SUMA_H
