#pragma once

#include <iostream>

template <typename T>
class ListNode
{
public:
	// Constructor
	ListNode(T in_data): data(in_data)
	{
		next = nullptr;
	}

	~ListNode()
	{
		// No necesita hacer nada expl�citamente, pero lo pongo para dejar explicar que no necesita hacer nada.
	}

	T data;// Los datos
	ListNode<T>* next;// una referencia al nodo sigue de este nodo, dentro de la lista.
};



// List va a ser lista simplemente ligada
template <typename T>
class List
{
private:
	ListNode<T>* firstNode;  // checar si mejor usamos smart pointers de una vez.
	int size; // es opcional

	// Si el next de currentNode es == nullptr, quiere decir que currentNode es el �ltimo elemento de la lista.
public:
	List()
	{
		firstNode = nullptr;
		size = 0;
	}

	/*List(T dataArray[], int dataSize)
	{
	
	}*/

	~List()
	{
		// La lista es due�a de todos sus nodos, los nodos no son due�os de nadie.
		// por lo tanto, aqu� s� tendr�amos que borrar los nodos.
		// primero necesitamos los m�todos de iteraci�n para luego ahora s� poder borrar los nodos.
	}

	void PushBack(T element)
	{

		// aumentamos el size en 1
		size++;

		if (firstNode == nullptr)
		{
			firstNode = new ListNode<T>(element);  // usamos el constructor que recibe un valor T.
			return;
		}

		// a�ade element hasta el final de la lista.
		ListNode<T>* currentNode = firstNode;
		// Iteramos hasta encontrar el �ltimo de la lista
		while (currentNode->next != nullptr)
			currentNode = currentNode->next;

		// Falta decirle a currentNode que su next es ahora un nuevo nodo que va a guardar a element.
		ListNode<T>* newNode = new ListNode<T>(element);  // usamos el constructor que recibe un valor T.

		// Ya que tenemos nuestro nuevo nodo, falta actualizar el next de currentNode, para que 
		// sepa que ya no es el �ltimo nodo de la lista.
		currentNode->next = newNode;

	}

	void PushBack(ListNode<T>* in_node)
	{
		// a�ade element hasta el final de la lista.
		ListNode<T>* currentNode = firstNode;
		// Iteramos hasta encontrar el �ltimo de la lista
		while (currentNode->next != nullptr)
			currentNode = currentNode->next;

		// Aqu�, por seguridad, es necesario
		in_node->next = nullptr;

		currentNode->next = in_node;
	}

	// Quita al primer elemento de la lista.
	void PopFront()
	{
		// Siempre checar que haya elementos antes de quitar elementos.
		if (firstNode == nullptr)
		{
			// entonces la lista est� vac�a.
			std::cout << "error, tratando de quitar elementos de una lista vac�a" << '\n';
			return;  // nos salimos de la funci�n.
		}

		// Hay que quitar a firstNode.
		// Primero hay que checar si hay otros nodos en la lista.
		if (firstNode->next != nullptr)
		{
			// Primero guardamos una referencia a qui�n sigue de firstNode
			ListNode<T>* auxNode = firstNode->next;
			// Despu�s, borramos la memoria de first node.
			delete firstNode;
			// ajustamos qui�n es el nuevo firstNode.
			firstNode = auxNode;
		}
		else // si es el �nico elemento de la lista.
		{
			delete firstNode;
			firstNode = nullptr;
		}
		size--;
	}

	// Funci�n de b�squeda por valor T
	ListNode<T>* GetByValue(T value)
	{
		if (firstNode == nullptr)
		{
			std::cout << "error, la lista est� vac�a: " << '\n';
			return nullptr; // �ndice no v�lido, regresa nullptr por defecto.
		}

		// INCOMPLETA.

		std::cout << "error, no se encontr� ning�n nodo con value = " << value << '\n';
		return nullptr; // No encontrado, regresa nullptr por defecto.
	}


	// Funci�n de "b�squeda" por �ndice i
	ListNode<T>* GetByIndex(int index)
	{
		if (firstNode == nullptr)  // checar que la lista no est� vac�a
		{
			std::cout << "error, la lista est� vac�a: " << index << " pero size = " << size << '\n';
			return nullptr; // �ndice no v�lido, regresa nullptr por defecto.
		}
		if (index >= size)  // checar que el index sea v�lido
		{
			std::cout << "error, tratando de acceder a indice: " << index << " pero size = " << size << '\n';
			return nullptr; // �ndice no v�lido, regresa nullptr por defecto.
		}
		// no necesitamos 'else' porque el return de arriba los sacar�a de la funci�n.

		ListNode<T>* currentNode = firstNode;
		for (int i = 0; i < index; i++)
			currentNode = currentNode->next;

		return currentNode;
	}



	ListNode<T>* Successor(ListNode<T>* x)
	{
		return x.next;  // como X ya sabe qu� nodo sigue de �l, entonces lo regresamos.
	}

	ListNode<T>* Predecessor(ListNode<T>* x)
	{
		// tenemos que iterar desde el inicio de la lista, hasta encontrar un nodo 'y', cuyo next sea = x.
		ListNode<T>* currentNode = firstNode;
		// La primera parte del while es: si todav�a no encontramos al predecesor
		// la segunda parte edl while es: si todav�a hay elementos por checar en la lista.
		while(currentNode->next != nullptr)
		{
			if (currentNode->next == x)
			{
				return currentNode; 		// si s� encontramos al predecesor, pues lo regresamos
			}
			// si no se ha cumplido, este nodo no es el predecesor y nos tenemos que ir al siguiente.
			currentNode = currentNode->next;
		}
		return nullptr;
	}





};

