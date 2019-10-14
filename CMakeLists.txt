cmake_minimum_required(VERSION 3.14)
project(solver_davidalejandrolazopampa)

set(CMAKE_CXX_STANDARD 14)

add_executable(solver_davidalejandrolazopampa
        README.md main.cpp Calculos/Cal.h Calculos/Numero.h Calculos/Variable.h Calculos/Divicion.h Calculos/Multiplicacion.h Calculos/Parentesis.h Calculos/Exponente.h Calculos/Resta.h Calculos/Suma.h arbolcalculos.h)
