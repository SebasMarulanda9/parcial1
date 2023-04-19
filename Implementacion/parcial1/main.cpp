#include <funciones.h>

using namespace std;

int main()
{
    bool continuar = true;
    char database[] = "database.txt";

    while(continuar){
        cout << "\n============ Menu ============" << endl;
        cout << "1. Ingresar materias" << endl;
        cout << "2. Ver pensum" << endl;
        cout << "3. Ver horario" << endl;
        cout << "4. Sugerir horas de estudio" << endl;
        cout << "5. Salir" << endl << endl;

        int opcion;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");

        switch(opcion){
             case 1:
                char codigo[7];
                char cedula[10];
                char *cedulatxt;
                cout << "Ingrese su cedula: ";
                cin >> cedula;

                cedulatxt = anexar_txt(cedula);

                cout << "Ingrese el codigo de la materia: ";
                cin >> codigo;
                cout << endl;
                matricular(cedulatxt,codigo);
                delete[] cedulatxt;
                break;
            case 2:
                imprimir(database);
                cout << endl;
                break;
            case 3:
                char cedula1[10];
                char *cedulatxt1;
                cout << "Ingrese su cedula: ";
                cin >> cedula1;
                cout << endl;
                cedulatxt1 = anexar_txt(cedula1);
                imprimir(cedulatxt1);
                cout << endl;
                horario();
                cout << endl;
                delete[] cedulatxt1;
                break;
            case 4:
                cout << "En construccion" << endl;
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                continuar = false;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
        }
    }

    return 0;
}
