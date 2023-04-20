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
        cout << "3. Sugerir horas de estudio" << endl;
        cout << "4. Salir" << endl << endl;

        int opcion;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        system("cls");
        char*** horarios = new char**[6];

        switch(opcion){
             case 1: {
                horarios = horario();
                break;
            }
            case 2: {
                imprimir(database);
                cout << endl;
                break;
            }
            case 3: {
                cout << "\nHORARIO\n";
                cout << "      LUNES    MARTES MIERCOLES JUEVES   VIERNES  SABADO\n";
                for (int j = 0; j < 16; j++) {
                    printf("%02d:00 ", j+6);
                    for (int i = 0; i < 6; i++) {
                        printf("%-9s", horarios[i][j]);
                    }
                }
                cout << endl;

                break;
            }
            case 4: {
                cout << "Saliendo del programa..." << endl;
                continuar = false;
                break;
            }
            default: {
                cout << "Opcion invalida. Intente nuevamente." << endl;
                break;
            }
        }
    }

    return 0;
}
