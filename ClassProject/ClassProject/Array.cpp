#include "Array.h"

#include <iostream>

// int myArray[5]

// POD = Plain Old Data, por ejemplo: int, float, bool, etc.
// NO-POD: objetos de clases y structs definidos por usuarios.

RawArray::RawArray(int in_Size): Size(in_Size)
{
	// Size = in_Size;
	// estoy pidiendo espacio en memoria igual a n ints, donde n = Size.
	InitialElement = new int[Size];

	// Internamente "new int[Size]" har�a:
	// InitialElement = new int;
	// int* auxPosition = InitialElement;
	// for (int i = 0; i < Size; i++)
	// {
	// 	 auxPosition++;
	// 	 auxPosition = new int;
	// }
}

RawArray::~RawArray()
{
	std::cout << "entrada destructor de RawArray" << '\n';
	// Hay que liberar la memoria din�mica
	delete[] InitialElement;
	/*int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		int* toDelete = auxPosition;
		delete toDelete;
		auxPosition++;
	}*/
	std::cout << "salida destructor de RawArray" << '\n';
}

void RawArray::Init(int InitialValue)
{
	int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		*auxPosition = InitialValue;
		auxPosition++;
	}
}  // El return nos manda autom�ticamente hasta fuera del Scope de la funci�n en que est�s.
// al llegar ac�, se manda llamar el destructor de TODAS las variables (est�ticas) 
// que solo viven en ese scope.

void RawArray::Print()
{
	int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		std::cout<<*auxPosition << ", ";
		auxPosition++;
	}
	std::cout << '\n';
}

