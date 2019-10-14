//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_ARBOLCALCULOS_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_ARBOLCALCULOS_H

#include <algorithm>
#include "Calculos/Numero.h"
#include "Calculos/Variable.h"
#include "Calculos/Suma.h"
#include "Calculos/Resta.h"
#include "Calculos/Multiplicacion.h"
#include "Calculos/Divicion.h"
#include "Calculos/Exponente.h"
#include "Calculos/Parentesis.h"

class Arbol{
private:
    cal *raiz;
    stack<cal *> *post;
    vector<Variable *> *variables;
    cal * prev;
public:
    Arbol(){
        raiz = nullptr;
        post = new stack<cal *>();
    }
    float evalor(){
        return this->raiz->execute();
    }
    void calculadora(string Exp){
        auto stackk = new stack<cal*>();
        cal *newCal = nullptr;
        string numeroString;
        string letraString;
        int sum=0;
        variables = new vector<Variable *>();
        prev =nullptr;

    }

};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_ARBOLCALCULOS_H
