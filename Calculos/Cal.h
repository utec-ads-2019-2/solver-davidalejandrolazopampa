//
// Created by David Lazo on 13/10/2019.
//

#ifndef SOLVER_DAVIDALEJANDROLAZOPAMPA_CAL_H
#define SOLVER_DAVIDALEJANDROLAZOPAMPA_CAL_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <vector>
#include <stack>
using namespace std;
//Iniciamos
typedef float Datos;
class cal{
protected:
    string dato;
    int pct;
    bool operatorr;
    char tipo;
    cal *left = nullptr;
    cal *right = nullptr;
public:
    cal(string dato) : dato(dato) {};
    virtual Datos execute() =0;
    const string &getData() const {
        return dato;
    }
    bool operatorrr() const {
        return operatorr;
    }
    cal *getLeft()const {
        return left;
    }
    void setLeft(cal *left){
        cal::left = left;
    }
    cal *getRight() const{
        return right;
    }
    void setRight(cal *right){
        cal::right = right;
    }
    int getpct() const {
        return pct;
    }
    char getTipo()const {
        return tipo;
    }
    void destrosar(){
        if (this->left)
            this->left->destrosar();
        else if (this->right)
            this->right->destrosar();

        delete this;
    }
};
#endif //SOLVER_DAVIDALEJANDROLAZOPAMPA_CAL_H
