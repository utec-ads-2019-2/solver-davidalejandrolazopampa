//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_DIVICION_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_DIVICION_H

#include "Cal.h"
class Division : public cal{
public:
    Division(string dato): cal(dato){
        pct =2;
        operatorr = true;
        tipo ='/';
    };
    Datos execute() override {
        auto X = getLeft()->execute();
        auto Y = getRight()->execute();
        return (X / Y);
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_DIVICION_H
