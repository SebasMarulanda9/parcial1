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
        cout << "No se ha creado su horario." << endl;
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

char *matricular(char *codigo){
    ifstream archivo("database.txt");
    if(archivo.is_open()) {
        char caracter;
        char cadena[7];
        char *materia = new char[5];
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

                    for(int i = 0; i < 6; i++){
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
                    cout << materia;
                    return materia;
                }
            }
        }
        archivo.close();
        if(!flag){
            cout << "Codigo incorrecto o no pertenece al pensum de ing. en telecomunicaciones.\n" << endl;
            exit(1);
        }
    }

    else{
        cout << "Error al abrir el archivo." << endl;
        exit(1);
    }

}

char *anexar_txt(char *cadena_original){

    char extension[] = ".txt";

    int longitud_original = 0;
    while (cadena_original[longitud_original] != '\0') {
        longitud_original++;
    }

    char* nueva_cadena = new char[longitud_original + sizeof(extension)];

    for (int i = 0; i < longitud_original; i++) {
        nueva_cadena[i] = cadena_original[i];
    }

    for (int i = 0; i < sizeof(extension); i++) {
        nueva_cadena[longitud_original + i] = extension[i];
    }

    nueva_cadena[longitud_original + sizeof(extension) - 1] = '\0';

    return nueva_cadena;
}

char*** horario(){
    char*** horario = new char**[6];
    for (int i = 0; i < 6; i++) {
        horario[i] = new char*[16];
        for (int j = 0; j < 16; j++) {
            horario[i][j] = new char[20];
            horario[i][j][0] = '-';
            horario[i][j][1] = '-';
            horario[i][j][2] = '-';
            horario[i][j][3] = '-';
            horario[i][j][4] = '-';
            horario[i][j][5] = '\0';
        }
    }

    int dia, hora;
    bool salir = false;

    do {
        char codigo[7];
        char *materia;

        cout << "Ingrese el codigo de la materia: ";
        cin >> codigo;

        materia = matricular(codigo);

        cout << "\nIngresa el dia: (1-6) (0 para salir): ";
        cin >> dia;

        if (dia == 0) {
            salir = true;
            continue;
        }

        cout << "Ingresa la hora (6 a 21): ";
        cin >> hora;

        if (dia >= 1 && dia <= 6 && hora >= 6 && hora <= 21) {
            for (int i = 0; i < strlen(materia); i++) {
                horario[dia-1][hora-6][i] = materia[i];
            }
            horario[dia-1][hora-6][strlen(materia)] = '\0';
        } else {
            cout << "Entrada invalida. Intentalo de nuevo.\n";
        }

        cout << "\nHORARIO\n";
        cout << "      LUNES    MARTES MIERCOLES JUEVES   VIERNES  SABADO\n";
        for (int j = 0; j < 16; j++) {
            printf("%02d:00 ", j+6);
            for (int i = 0; i < 6; i++) {
                printf("%-9s", horario[i][j]);
            }
            cout << endl;
        }
        cout << endl;
        delete[] materia;
    } while (!salir);

    return horario;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 16; j++) {
            delete[] horario[i][j];
        }
        delete[] horario[i];
    }

    delete[] horario;
}

size_t strlen(const char* str) {
    const char* p = str;
    while (*p) {
        ++p;
    }
    return p - str;
}
