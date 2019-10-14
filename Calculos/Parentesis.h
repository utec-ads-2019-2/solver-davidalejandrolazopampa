//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_PARENTESIS_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_PARENTESIS_H

#include "Cal.h"
class Parentisis : public cal{
public:
    Parentisis(string dato): cal(dato){
        pct =0;
        operatorr = false;
        tipo ='(';
    };
    Datos execute() override {
        return 0;
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_PARENTESIS_H
