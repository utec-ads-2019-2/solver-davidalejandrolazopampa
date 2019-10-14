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
    return EXIT_SUCCESS;
}
