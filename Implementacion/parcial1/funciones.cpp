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
