#include <funciones.h>

using namespace std;

int main()
{
    const char* rutaArchivo = "database.txt";
    ifstream archivo(rutaArchivo);
    char codigo[] = "2537101";

    if(archivo.is_open()) {
        char caracter;

        while(archivo.get(caracter)){
            //cout << caracter;
            if(caracter == '\n'){ // verificar si el caracter es una coma

                char cadena[8]; // array de caracteres para almacenar los siguientes 7 caracteres
                char materia[60];
                int indice = 0;
                for(int i = 0; i < 7; i++){
                    if (archivo.get(caracter)) {
                        cadena[indice] = caracter; // almacenar el caracter en el array
                        indice++; // aumentar el índice para el siguiente caracter
                    }

                    else{
                        break;
                    }
                }
                cadena[indice] = '\0'; // agregar un carácter nulo al final del array
                if(strcmp(codigo,cadena)==0){
                    int indice = 0;
                    for(int i = 0; i < 60; i++){
                        if(archivo.get(caracter)){
                            if(caracter=='\n'){
                                break;
                            }

                            else{
                                materia[indice] = caracter; // almacenar el caracter en el array
                                indice++; // aumentar el índice para el siguiente caracter
                            }
                        }

                        else{
                            break;
                        }
                    }
                    cout << materia << endl;
                }
            }//if salto de linea

        }//while
        archivo.close();
    }//if open

    else{
        cout << "Error al abrir el archivo." << endl;
    }

    return 0;
}
