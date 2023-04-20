#include <funciones.h>

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

void matricular(char *nombre, char *codigo){
    ifstream matri(nombre);
    if (matri.peek() == ifstream::traits_type::eof()){
        ofstream archivo_salida(nombre);
        archivo_salida << endl;
        archivo_salida.close();
    }
    matri.close();

    ifstream archivo("database.txt");
    if(archivo.is_open()) {
        char caracter;
        char cadena[7];
        char materia[60]={0};
        bool flag = false;
        char dia[3];
        char hora[3];

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
                    ofstream matricula(nombre, ios_base::app);
                    cout << "Ingrese el dia (1-6): ";
                    cin >> dia;
                    cout << "Ingrese la hora (6-21): ";
                    cin >> hora;
                    matricula << materia << "," << dia << "," << hora << "\n";
                    cout << endl << materia << "," << dia << "," << hora << endl << endl;
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

char*** horario(char *nombre){
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

    int dia =1, hora=0;
    int contador =0;
    bool salir = false;
    char materia[7];

    do {
        ifstream archivo(nombre);
        if(archivo.is_open()) {
            char caracter = '\0';
            do{
                if(caracter == '\n'){
                    dia = 1;
                    hora= 0;
                    contador = 0;
                    int indice = 0;

                    for(int i = 0; i < 5; i++){
                        if (archivo.get(caracter)) {
                            materia[indice] = caracter;
                            indice++;

                        }

                        else{
                            break;
                        }
                    }
                    materia[indice] = '\0';
                }
                if(caracter == ','){
                    contador++;
                    archivo.get(caracter);
                    if(contador==2){
                        dia = caracter - '0';
                    }
                    if(contador==3){
                        for(int i = 0; i < 1; i++){
                            char caracterfinal[2] = {caracter, 0};
                            if(archivo.get(caracter)){
                                if(caracter!='\n'){
                                    caracterfinal[1] = caracter;
                                    hora = ((caracterfinal[0] - '0') * 10) + (caracterfinal[1] - '0');
                                }
                                else{
                                    archivo.unget();
                                    caracterfinal[1] = '0';
                                    hora = ((caracterfinal[0] - '0') * 10) + (caracterfinal[1] - '0');
                                    hora = hora/10;
                                }

                            }
                            else{
                                break;
                            }
                        }
                    }
                }
                if (dia >= 1 && dia <= 6 && hora >= 6 && hora <= 21) {
                    for (int i = 0; i < strlen(materia); i++) {
                        horario[dia-1][hora-6][i] = materia[i];
                    }
                    horario[dia-1][hora-6][strlen(materia)] = '\0';
                }

                if(caracter=='\0'){
                    salir = true;
                    continue;
                }
            }while(archivo.get(caracter));
        archivo.close();
        }

        else{
            cout << "Error al abrir el archivo." << endl;
            exit(1);
        }
        archivo.close();

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
