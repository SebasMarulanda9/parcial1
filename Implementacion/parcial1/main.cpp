#include <funciones.h>

using namespace std;

int main()
{
    char codigo[7];
    cout << "ingrese el codigo de la materia: ";
    cin >> codigo;
    Leer("database.txt", codigo);
    return 0;
}
