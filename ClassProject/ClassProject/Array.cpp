#include "Array.h"

#include <iostream>

RawArray::RawArray(int in_Size)
{
	Size = in_Size;
	// estoy pidiendo
	InitialElement = new int[Size];

	// Internamente "new int[Size]" haría:
	// InitialElement = new int;
	// int* auxPosition = InitialElement;
	// for (int i = 0; i < Size; i++)
	// {
	// 	 auxPosition++;
	// 	 auxPosition = new int;
	// }
}

void RawArray::Init(int InitialValue = 0)
{
	int* auxPosition = InitialElement;
	for (int i = 0; i < Size; i++)
	{
		 *auxPosition = InitialValue;
		 auxPosition++;
	}
}

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

