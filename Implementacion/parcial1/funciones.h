#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <fstream>

using namespace std;

int strcmp(const char* cadena1, const char* cadena2);
void matricular(char *nombre, char *codigo);
void imprimir(char *nombreArchivo);
char *anexar_txt(char* cadena_original);
char*** horario(char *nombre);
size_t strlen(const char* str);

#endif // FUNCIONES_H
