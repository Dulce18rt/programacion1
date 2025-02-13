#include <iostream>
#include <cstdlib>
//
using namespace std;

int main()
{
    // Variables
    float alturaMetros, pesoLibras, alturaPulgadas, pesoKilogramos;
    int opcionSeleccionada;
    char salidaMenu;

    // Inicia el ciclo
    do
    {
        system("cls");
        cout << "Calculadora de Peso" << endl;
        cout << "1. Calcular peso con formula 1" << endl;
        cout << "2. Calcular peso con formula 2" << endl;
        cout << "3. Calcular ambas formulas" << endl;
        cout << "   Opcion: ";
        cin >> opcionSeleccionada;

        if (opcionSeleccionada >= 1 && opcionSeleccionada <= 3)
        {
            cout << "Ingrese su altura: ";
            cin >> alturaMetros, alturaPulgadas;
        }

        switch (opcionSeleccionada)
        {
            case 1:
                pesoIdeal1 = (pesoLibras * 703) / alturaPulgadas * alturaPulgadas; // Fórmula 1 (Ejemplo, reemplazar con la real)
                cout << "BMI: " << pesoLibras << " lb " << endl;
                break;
            case 2:
                pesoIdeal2 = (pesoKilogramos / alturaMetros * alturaMetros); // Fórmula 2 (Ejemplo, reemplazar con la real)
                cout << "BMI: " << pesoKilogramos << " kg" << endl;
                break;
            case 3:
                pesoIdeal1 = (pesoLibras * 703) / alturaPulgadas * alturaPulgadas; // Fórmula 1
                pesoIdeal2 = (pesoKilogramos / alturaMetros * alturaMetros); // Fórmula 2
                cout << "BMI: " << pesoLibras << " lb" << endl;
                cout << "BMI: " << pesoKilogramos << " kg" << endl;
                break;
            default:
                cout << "Error: opcion seleccionada no valida" << endl;
        }

        cout << "Desea realizar otro calculo? (Si/No): ";
        cin >> salidaMenu;
    } while (salidaMenu == 'si' || salidaMenu == 'Si');

    return 0;
}
