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

void matricular(char *nombre, char *codigo){
    ifstream archivo("database.txt");
    if(archivo.is_open()) {
        char caracter;
        char cadena[7];
        char materia[60]={0};
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
                    ofstream matricula(nombre, ios_base::app);
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

void horario(){
    //asignamos memoria dinamica para las 6 filas (dias) y 15 columnas (horas)
    int **matrix;
    matrix = new int *[17];
    for(int i=0;i<17; i++){
        matrix[i]=new int[7];
    }
    //las inicializamos en cero para que no haya basura y para que todas esten en "LIBRE".
    for(int j=0;j<17;j++){
        for(int k=0;k<7;k++){
            *(*(matrix+j)+k) = 0;
        }

    }
    bool finished = false; //ponemos una bandera.

    char name[] = "Materia";

    while(finished==false){
        for(int j=0;j<17;j++){
            for(int k=0;k<7;k++){
                if(k==0 && j==0)
                    cout << "      ";
                else if(k==0 && j==1)
                    cout << "06:00";
                else if(k==0 && j==2)
                    cout << "07:00";
                else if(k==0 && j==3)
                    cout << "08:00";
                else if(k==0 && j==4)
                    cout << "09:00";
                else if(k==0 && j==5)
                    cout << "10:00";
                else if(k==0 && j==6)
                    cout << "11:00";
                else if(k==0 && j==7)
                    cout << "12:00";
                else if(k==0 && j==8)
                    cout << "01:00";
                else if(k==0 && j==9)
                    cout << "02:00";
                else if(k==0 && j==10)
                    cout << "03:00";
                else if(k==0 && j==11)
                    cout << "04:00";
                else if(k==0 && j==12)
                    cout << "05:00";
                else if(k==0 && j==13)
                    cout << "06:00";
                else if(k==0 && j==14)
                    cout << "07:00";
                else if(k==0 && j==15)
                    cout << "08:00";
                else if(k==0 && j==16)
                    cout << "09:00";
                else if(k==1 && j==0)
                    cout << "LUNES    ";
                else if(k==2 && j==0)
                    cout << "MARTES   ";
                else if(k==3 && j==0)
                    cout << "MIERCOLES   ";
                else if(k==4 && j==0)
                    cout << "JUEVES   ";
                else if(k==5 && j==0)
                    cout << "VIERNES   ";
                else if(k==6 && j==0)
                    cout << "SABADO";

                else{
                    if((*(*(matrix+j)+k))==0) cout<<" LIBRE    ";  //es como tener matriz[j][k] y empezaramos a pasar de posiciones.
                    else cout<<name;  //para cuando esta matriz es = 1, que es cuando esta ocupada.
                }
            }
            cout<<endl;
        }
        char fila, option; int columna;
        cout<<"Ingrese a para reservar una hora de su horario. "<<endl<<"Ingrese b para quitar un horario.  "<<endl<<"Ingrese una letra diferente para salir "<<endl;
        cin>>option;
        if(option!='a' && option!='b') break;
        cout<<"Ingrese el dia, lunes a sabado, solo la inicial y en mayuscula. EJM: martes = M... "<<endl; cin>>fila;
        cout<<"Ingrese la columna 6-20 "<<endl; cin>>columna;
        switch (fila) {
        case 'L':{
            if(option=='a') *(*(matrix)+(columna-6))=1;   //usamos algebra de punteros para posicionarnos en cada fila que indica los dias.
            else *(*(matrix)+(columna-6))=0;  //a las columnas les quitamos 6 porque el dia de estudio empieza a las 6 am.
            break;
        }
        case 'M':{
            if(option=='a') *(*(matrix+1)+(columna-6))=1;  //con algebra de punteros nos empezamos a mover en la matriz, ahora pasando a la siguiente fila.
            else *(*(matrix+1)+(columna-6))=0;  //cuando escogio la opcion a, e ingreso este dia martes, solo seria movernos entre la fila del martes. cero esta libre, 1 esta ocupada.
            break;
        }
        case 'W':{
            if(option=='a') *(*(matrix+2)+(columna-6))=1;
            else *(*(matrix+2)+(columna-6))=0;
            break;
        }
        case 'J':{
            if(option=='a') *(*(matrix+3)+(columna-6))=1;
            else *(*(matrix+3)+(columna-6))=0;
            break;
        }
        case 'V':{
            if(option=='a') *(*(matrix+4)+(columna-6))=1;
            else *(*(matrix+4)+(columna-6))=0;
            break;
        }
        case 'S':{
            if(option=='a') *(*(matrix+5)+(columna-6))=1;
            else *(*(matrix+5)+(columna-6))=0;
            break;
            }
            default:{
                cout<<"Los valores ingresados son invalidos "<<endl;
            }
            }
        }
        delete [] matrix;
}
