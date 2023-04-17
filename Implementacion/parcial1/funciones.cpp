#include <funciones.h>

int len(char *texto){
    int longitud = 0;
    ifstream archivo(texto, ios_base::in | ios_base::binary | ios_base::ate);
    if (!archivo.is_open()) {
        return 0;
    }
    else{
        longitud = archivo.tellg();
    }
    return longitud;
}

int strcmp(const char* cadena1, const char* cadena2){
    int i = 0;
    while (cadena1[i]==cadena2[i] && cadena1[i]!='\0'){
        i++;
    }

    if (cadena1[i]>cadena2[i])
        return 1;

    else if (cadena1[i]<cadena2[i])
        return -1;

    else
        return 0;
}
