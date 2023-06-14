#pragma once

#include <iostream>

template <typename T>
class Queue
{
private:
	// Variables que tiene que tener:
	// Donde vamos a guardar los datos.
	T* InitialElement;
	int _head;
	int _tail;
	int _size; // cuanta memoria está pedida actualmente.

	// bool _isDynamic;

public:
	Queue(int size): _size(size)
	{
		// pedimos _size bloques de memoria, cada uno de tamaño igual al tipo T del template.
		InitialElement = new T[_size];
		// Tenemos que inicializar los valores de _head y _tail, y ambos inician en 0.
		_head = 0;
		_tail = 0;
	}

	~Queue()
	{
		delete[] InitialElement;  // liberamos la memoria pedida para nuestro arreglo de tipo T.
	}

	// Añade el elemento "element" en la posición Tail de la Queue, e incrementa el valor de Tail en 1.
	void Enqueue(T element)
	{
		// Poner element en donde Tail nos diga.
		InitialElement[_tail] = element;
		// Y después aumentamos Tail en 1
		_tail++;
		// Después, checamos si lo tenemos que ciclar, aquí les muestro dos maneras de ciclarlo.
		/*if (_tail == _size)
		{
			_tail = 0;
		}*/
		_tail = _tail % _size;
	}

	// Quita el elemento de la posición Head de la Queue, e incrementa el valor de Head en 1.
	void Dequeue()
	{
		// Antes de quitar elementos, hay que checar que sí hay al menos un elemento por quitar.
		// IMPORTANTE.

		InitialElement[_head] = NULL;  // OPCIONAL
		// Incrementamos Head en 1
		_head++;
		// Ciclamos el valor de head
		_head = _head % _size;
	}

	// Regresa el valor del elemento en el índice Head de la Queue
	T Front()
	{
		return NULL; // Retorna un valor NULL por defecto
	}

	// Regresa el valor del elemento en el índice Tail de la Queue
	T Back()
	{
		return NULL; // Retorna un valor NULL por defecto
	}

	// Imprimir // No es exactamente igual que la de Stack ni la de RawArray.
	//void Print()
	//{
	//	for (int i = 0; i < _size; i++)
	//	{
	//		std::cout << InitialElement[i] << ", ";
	//	}
	//	std::cout << '\n';
	//}


};

