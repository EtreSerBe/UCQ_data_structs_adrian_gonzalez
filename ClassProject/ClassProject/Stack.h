#pragma once

#include <iostream>

template <typename T>
class Stack
{
private:
	// Las dejas como privadas para que no sea tan f�cil para usuarios inexpertos modificarlas sin saber.
	T* InitialElement; // Tal cual los datos que estamos guardando en la Stack.
	int _size; // cu�ntos elementos puede tener antes de llenarse (overflow)
	int _top;  // cu�ntos elementos tiene ahorita

public:
	Stack(int size) : _size(size)
	{
		InitialElement = new T[_size];
		_top = 0;
	}

	~Stack()
	{
		std::cout << "entrada destructor de Stack" << '\n';
		delete[] InitialElement;
		std::cout << "salida destructor de Stack" << '\n';
	}


	// Funci�n que a�ade un elemento hasta arriba de la pila
	void Push(T ElementToPush)
	{
		if (_size == _top)
		{
			// esto ser�a un error de Overflow
			std::cout << "Error de Overflow" << '\n';
		}
		else
		{
			// si no, lo metemos hasta el tope de la pila, y lo hacemos el nuevo top
			InitialElement[_top] = ElementToPush;
			_top++; // incrementamos el tope en una unidad (_top++; es lo mismo que _top = _top + 1;)
		}
	}

	// Quita el elemento del tope de la Pila.
	void Pop()
	{
		if (IsEmpty())
		{
			// Error, underflow, que es: quieres quitar elementos donde no hay.
			std::cout << "Error de Underflow" << '\n';
		}
		else
		{
			// Podr�amos poner en 0 este elemento, pero no es necesario, porque el _top nos dice 
			// que ya no lo leamos o tomemos en cuenta, y cuando se a�ada algo nuevo, se sobreescribir�.
			// InitialElement[_top-1] = NULL; 
			_top--;
		}
	}

	bool IsEmpty()
	{
		if (_top == 0)
		{
			return true;
		}
		// Aqu� no puse el "else" porque con el return true; de arriba se saldr�a de la funci�n.
		return false;
	}

	// Funci�n que nos permite leer el elemento al tope de la Pila.
	T Top()
	{
		if (IsEmpty())
			return NULL;

		return InitialElement[_top - 1];
	}

	// Imprimir

	// Funci�n Resize
};

