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
        for(auto i = Exp.begin(); i !=Exp.end();++i){
            auto caracter = *i;
            if(isdigit(caracter)){
                numeroString=numeroString+caracter;
            } else if(isalpha(caracter)){
                letraString = letraString+caracter;
            }else{
                if(numeroString != ""){
                    newCal = new Numero(numeroString);
                    post ->push(newCal);
                    numeroString = "";
                    prev = newCal;
                }
                getVariable(&letraString);
                switch (caracter){
                    case ' ':
                        continue;
                    case '(':{
                        newCal = new Parentisis(string(1, caracter));
                        stackk->push(newCal);
                    }
                        break;
                    case ')':{
                        auto cal = stackk->top();
                        newCal = new Parentisis(string(1,caracter));
                        while(cal -> getTipo() != '('){
                            post -> push(cal);
                            stackk -> pop();
                            cal = stackk ->top();
                        }
                        if (cal -> getTipo() == 'C')
                            stackk -> pop();
                        prev = newCal;
                    }
                        break;
                    default:{
                        newCal = moverOperador(caracter);
                        validarTipo(stackk,newCal);
                        prev = newCal;
                    }
                }
            }
            if(i==Exp.end() -1){
                if(numeroString != "")
                    post->push(new Numero(numeroString));
                getVariable(&letraString);
                while (!stackk->empty()){
                    post->push(stackk->top());
                    stackk->pop();
                }
            }
        }ConstructorArbol();
    }
    void getVariable(string *letraString)const {
        string aux = * letraString;
        if (*letraString != "") {
            auto exists = find_if(variables->begin(), variables->end(),
                                  [aux](Variable *var) { return var->getData() == aux; }
            );

            if (exists != variables->end()) {
                post->push(*exists);
            } else {
                auto pNodeVar = new Variable(*letraString);
                post->push(pNodeVar);
                variables->push_back(pNodeVar);
            }

            *letraString = "";
        }
    }
    void ConstructorArbol(){
        auto stackk = new stack<cal *>();

        while (!post->empty()) {
            stackk->push(post->top());
            post->pop();
        }

        while (!stackk->empty()) {
            auto cal = stackk->top();

            if (cal->operatorrr()) {
                auto nodeRight = post->top();
                post->pop();
                auto nodeLeft = post->top();
                post->pop();

                cal->setRight(nodeRight);
                cal->setLeft(nodeLeft);
            }
            post->push(cal);
            stackk->pop();
        }
        if (!post->empty()) {
            raiz = post->top();
            post->pop();
        }
    }
    void askvalueVariables() {
        int value;
        for (auto elem: *variables) {
            cout << "Value for variable " << elem->getData() << " = ";
            cin >> value;
            elem->setValor(value);
        }
    }

    cal *moverOperador( char caracter) {
        cal *newCal = nullptr;
        switch (caracter) {
            case '^':
                newCal = new Exponente(string(1, caracter));
                break;
            case '/': {
                newCal = new Division(string(1, caracter));
            }
                break;
            case '*': {
                newCal = new Multiplicacion(string(1, caracter));
            }
                break;
            case '+': {
                newCal = new Suma(string(1, caracter));
            }
                break;
            case '-': {
                newCal = new Resta(string(1, caracter));
            }
                break;
        }

        return newCal;
    }

    void validarTipo(stack<cal *> *aux, cal *newCal) const {
        if (aux->empty())
            aux->push(newCal);
        else {
            if (newCal->getpct() > aux->top()->getpct()) {
                aux->push(newCal);
            } else if (newCal->getpct() < aux->top()->getpct()) {

                while (!aux->empty()) {
                    auto cal = aux->top();
                    if (cal->getTipo() == '(')
                        break;
                    post->push(cal);
                    aux->pop();
                }
                aux->push(newCal);
            } else { // Equal
                post->push(aux->top());
                aux->pop();
                aux->push(newCal);
            }
        }
    }

    ~Arbol() {
        variables->clear();
        variables = nullptr;

        if (!this->raiz)
            return;
        else
            this->raiz->destrosar();
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_ARBOLCALCULOS_H
