#include <funciones.h>

void Leer(char *c, char *cod){
    char materias[1000];

    ifstream archivo(c);
    if(!archivo.is_open()){
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    while(archivo.getline(materias,1000)){
        cout << materias << endl;
    }
    archivo.close();
}

int strcmp(const char* cadena1, const char* cadena2){
    int i = 0;
    while (cadena1[i] == cadena2[i] && cadena1[i] != '\0'){
        i++;
    }

    if (cadena1[i] > cadena2[i])
        return 1;

    else if (cadena1[i] < cadena2[i])
        return -1;

    else
        return 0;
}
