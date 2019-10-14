//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_MULTIPLICACION_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_MULTIPLICACION_H

#include "Cal.h"
class Multiplicacion : public cal{
public:
    Multiplicacion(string dato): cal(dato){
        pct =2;
        operatorr = true;
        tipo ='*';
    };
    Datos execute() override {
        auto X = getLeft()->execute();
        auto Y = getRight()->execute();
        return (X * Y);
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_MULTIPLICACION_H
