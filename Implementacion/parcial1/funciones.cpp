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

void imprimir(char *nombreArchivo){
    ifstream archivo(nombreArchivo);

    if(archivo.is_open()){
        char c;

        while(archivo.get(c)){
            cout << c;
        }
        archivo.close();
    }

    else
        cout << "No se pudo abrir el archivo." << endl;
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

void matricular(char *codigo){
    ifstream archivo("database.txt");
    if(archivo.is_open()) {
        char caracter;
        char cadena[7];
        char materia[60];
        bool flag = false;

        while(archivo.get(caracter)){
            //cout << caracter;
            if(caracter == '\n'){
                int indice = 0;

                for(int i = 0; i < 7; i++){
                    if (archivo.get(caracter)) {
                        cadena[indice] = caracter;
                        indice++;
                    }

                    else{
                        break;
                    }
                }
                cadena[indice] = '\0';

                if(strcmp(codigo,cadena)==0){
                    flag = true;
                    int indice = 0;

                    for(int i = 0; i < 60; i++){
                        if(archivo.get(caracter)){
                            if(caracter=='\n'){
                                break;
                            }

                            else{
                                if(i==0){
                                    continue;
                                }
                                materia[indice] = caracter;
                                indice++;
                            }
                        }

                        else{
                            break;
                        }
                    }
                    ofstream matricula("matricula.txt", ios_base::app);
                    matricula << materia << "\n";
                    cout << materia << " (MATERIA AGREGADA CON EXITO)" << endl << endl;
                    matricula.close();
                }
            }
        }
        archivo.close();
        if(!flag){
            cout << "Codigo incorrecto o no pertenece al pensum de ing. en telecomunicaciones.\n" << endl;
        }
    }

    else{
        cout << "Error al abrir el archivo." << endl;
    }
}
