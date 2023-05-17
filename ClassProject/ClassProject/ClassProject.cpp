// ClassProject.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

// En C++ solo se usan los archivos de código que se referencien en el main a través del include.
#include <iostream>
// i input
// o output
// stream

// A diferencia de Java, no es necesaria una clase para ejecutar código.
// El código inicia a partir de la función "main"


// Definición:
// Generalmente se lleva a cabo en los archivos .cpp (c plus plus, o archivos de fuente)
int myFunction()
{
    return 0;
}


// Nótese que el tipo de retorno es "int", pues devuelve un entero que representa el código
// de cómo terminó el programa, siendo 0 un término exitoso.
// En Java, main es de tipo "void", pues no retorna ningún valor.
int main()
{
    // Declaración
    int myDeclaration;
    // Generalmente en los archivos .h (header)

    // Inicialización:
    myDeclaration = 5;



     int myInt = 5;

    // int j; // No está inicializado, no nos deja usarlo el compilador, traería basura.

    // c de console y out de salida: salida a consola
    // std::cout << i << '\n';

    // std::cout << j << '\n';

    int myArray[5] = { 0, 11, 22, 337, 45 };

    for (int i = 0; i < 5; i++)
    {
        std::cout << myArray[i] << '\n';
    }
    
    std::cout << &myInt << '\n';

    int* myAddress = &myInt;

    std::cout << "Dirección de memoria a que apunta MyAddress: " << myAddress << '\n';
    std::cout <<  "Valor de la variable a la que apunta MyAddress: " << *myAddress << '\n';

    std::cout << &myAddress << '\n';

    int** myAddressAddress = &myAddress;

    // myArray[iésimo] ~ *

    // myTable[][] ~ []* ~ **

    // c de consola, in de entrada: entrada a consola (cin)

    int* myArrayPtr = &myArray[0];

    for (int i = 0; i < 5; i++)
    {
        std::cout <<"Dirección de memoria de myArray[" <<i<<"] : " << myArrayPtr << '\n';

        std::cout << "Valor del objeto de myArray[" << i << "] : " << *myArrayPtr << '\n';

        ++myArrayPtr;
        ++myArrayPtr;
    }

    // Anteriormente, se cerraba la consola en cuenta terminaba de ejecutarse la aplicación.
    // Ahora ya no, lo cual es bastante útil.

    // Si bien ya no es indispensable, es buena práctica poner este return 0,
    // que indica que el programa finalizó con el código 0 (correcto).
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
