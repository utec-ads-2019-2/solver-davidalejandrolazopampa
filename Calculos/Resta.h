//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_RESTA_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_RESTA_H

#include "Cal.h"
class Resta : public cal{
public:
    Resta(string dato): cal(dato){
        pct = 1;
        operatorr = true;
        tipo ='-';
    };
    Datos execute() override {
        auto X = getLeft()->execute();
        auto Y = getRight()->execute();
        return (X-Y);
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_RESTA_H
