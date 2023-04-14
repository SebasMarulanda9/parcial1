#include <funciones.h>

using namespace std;

int main()
{
    char codigo[7];
    //cout << "ingrese el codigo de la materia: ";
    //cin >> codigo;
    //Leer("database.txt", codigo);
    char prueba1[40] = "Este es un texto\ncon un salto de linea";
    char prueba2[40] = "Este es un texto\ncon un salto de linea";
    int a = strcmp(prueba1, prueba2);
    cout << a << endl;
    return 0;
}
