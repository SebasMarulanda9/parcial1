#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>

using namespace std;

int len(char *texto);
int strcmp(const char* cadena1, const char* cadena2);
char *my_strtok(char* cadena, char delimitador);
void matricular(char *nombre, char *codigo);
void imprimir(char *nombreArchivo);
char *anexar_txt(char* cadena_original);
void horario();

#endif // FUNCIONES_H
