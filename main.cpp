//
// Created by David Lazo on 13/10/2019.
//
#include <iostream>
#include "arbolcalculos.h"
using namespace std;
int main(){
    string ecuacion = "";
    Arbol *tree = new  Arbol();

    cin >> ecuacion;
    tree->calculadora(ecuacion);
    cout << tree->evalor() << endl;

    /*
     * Formulas de prueba
    7/4*((3+1)*3)+3
    2+(3)
    7/4*((1+2)^4*2)+3
    1-2*5/2+1-2^4+1
    ((7*3)/4+6*(3^2)/2)
     * */
    return EXIT_SUCCESS;
}
