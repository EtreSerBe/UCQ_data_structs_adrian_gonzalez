#pragma once

#include <iostream>
// BinaryTree::Node


template<typename T>
class BinaryTree
{
private:
	template <typename U>
	struct Node
	{
	public: // por defecto en una struct, todo es p�blico, pero lo pongo por claridad.
		Node(U in_data, Node<U>* in_parent, Node<U>* in_left=nullptr, Node<U>* in_right=nullptr):
			data(in_data), parent(in_parent), left(in_left), right(in_right)
		{
		}

		~Node() 
		{
		}

		U data; // datos que va a guardar este nodo.
		Node<U>* parent; // referencia al nodo padre de este nodo dentro del �rbol.
		Node<U>* left; // Hijo izquierdo
		Node<U>* right; // Hijo derecho.
	};

	Node<T>* root; // Nodo ra�z del �rbol.

public:
	BinaryTree(): root(nullptr)
	{
	}

	~BinaryTree()
	{
		// Aqu� es donde s� tenemos que destruir los nodos restantes
		// PENDIENTE.
	}

	Node<T>* GetRoot()
	{
		return root;
	}

	// regresa el m�nimo de un Sub�rbol a partir del nodo ra�z de dicho sub�rbol.
	Node<T>* MinimumFromNode(Node<T>* in_root)
	{
		Node<T>* temp = in_root;
		while (temp->left != nullptr)
		{
			temp = temp->left;
		}
		return temp;
	}

	// regresa el m�nimo desde la ra�z del �rbol
	Node<T>* Minimum()
	{
		return MinimumFromNode(root);
	}

	T MinimumValue()
	{
		Node<T>* temp = Minimum();
		if (temp != nullptr)
		{
			return temp->data;
		}
	}

	// M�ximo de un sub�rbol con ra�z en in_root
	Node<T>* MaximumFromNode(Node<T>* in_root)
	{
		Node<T>* temp = in_root;
		while (temp->right != nullptr)
		{
			temp = temp->right;
		}
		return temp;
	}

	// M�ximo de todo el �rbol.
	Node<T>* Maximum()
	{
		return MaximumFromNode(root);
	}

	T MaximumValue()
	{
		Node<T>* temp = Maximum();
		if (temp != nullptr)
		{
			return temp->data;
		}
	}

	Node<T>* Search(T value)
	{
		Node<T>* temp = root;
		while (temp != nullptr && temp->data != value)
		{
			if (value < temp->data)
			{
				temp = temp->left;
			}
			else
			{
				// Los valores repetidos, se a�adir�n como nodos en el sub�rbol derecho
				// porque as� lo establece el pseudoc�digo del libro.
				// Pero hay otras variantes que lo pueden manejar de otra manera,para obtener ciertos beneficios.
				temp = temp->right;
			}
		}
		// temp puede ser nullptr si no se encontr� un nodo con data==value; si s� se encontr�, pues temp es 
		// dicho nodo.
		return temp;
	}

	void Insert(T value)
	{
		Node<T>* temp = root;
		Node<T>* temp_parent = nullptr;
		while (temp != nullptr)
		{
			if (value < temp->data)
			{
				temp_parent = temp;
				temp = temp->left;
			}
			else
			{
				// Los valores repetidos, se a�adir�n como nodos en el sub�rbol derecho
				// porque as� lo establece el pseudoc�digo del libro.
				// Pero hay otras variantes que lo pueden manejar de otra manera,para obtener ciertos beneficios.
				temp_parent = temp;
				temp = temp->right;
			}
		}

		// Cuando se salga de este while, ya estamos donde deber�amos de insertar Value
		// Necesitamos decirle a este nodo nuevo, qui�n es su nodo padre.		
		Node<T>* newNode = new Node<T>(value, temp_parent);
		// Ahora hacemos la conexi�n de padre a hijo, dependiendo de si es hijo izquierdo o derecho.
		if (temp_parent == nullptr)
		{
			// entonces el �rbol estaba vac�o.
			root = newNode;
		}
		else if ( value < temp_parent->data)
		{
			temp_parent->left = newNode;
		}
		else
		{
			temp_parent->right = newNode;
		}
	}

	Node<T>* Sucessor(Node<T>* in_x)
	{
		if (in_x->right != nullptr)
		{
			// entonces s� tiene un sub�rbol derecho. Necesitamos el nodo m�s chico de dicho sub�rbol derecho
			return MinimumFromNode(in_x->right);
		}
		else
		{
			// empezamos con el padre del nodo al cual queremos encontrar su sucesor.
			Node<T>* current = in_x;  // current es 9
			Node<T>* temp_parent = in_x->parent; // temp parent es 8
			while (temp_parent != nullptr && temp_parent->right == current)
			{
				// Si seguimos siendo el hijo derecho de nuestro padre, todav�a no vamos a romper este while.
				current = current->parent; // ahora current es 5
				temp_parent = current->parent; // ahora el padre de current es nullptr
			}
			return temp_parent; // se regresa el nodo nullptr
		}
	}

	// Aqu� ir�a la funci�n Predecessor()
	// Node<T>* Predecessor(Node<T>* in_x)
	//{}


	/*
	*	In Order
		Viaja al sub-�rbol izquierdo de este nodo, recursivamente.
		Visita el nodo actual.
		Viaja al sub-�rbol derecho de este nodo, recursivamente.
	*/
	void InOrder(Node<T>* in_x)
	{
		if (in_x != nullptr)
		{
			InOrder(in_x->left);
			std::cout << in_x->data <<", ";
			InOrder(in_x->right);
		}
		// Si no, no se hace nada, y solo se sale de la funci�n.
	}

	/*
	*	Pre-Order
	Visita el nodo actual.
	Viaja al sub-�rbol izquierdo de este nodo, recursivamente.
	Viaja al sub-�rbol derecho de este nodo, recursivamente.
	*/
	void PreOrder(Node<T>* in_x)
	{
		if (in_x != nullptr)
		{
			std::cout << in_x->data << ", ";
			PreOrder(in_x->left);
			PreOrder(in_x->right);
		}
		// Si no, no se hace nada, y solo se sale de la funci�n.
	}

	/*
	*	Post-Order
	Viaja al sub-�rbol izquierdo de este nodo, recursivamente.
	Viaja al sub-�rbol derecho de este nodo, recursivamente.
	Visita el nodo actual.
	*/
	void PostOrder(Node<T>* in_x)
	{
		if (in_x != nullptr)
		{
			PostOrder(in_x->left);
			PostOrder(in_x->right);
			std::cout << in_x->data << ", ";
		}
		// Si no, no se hace nada, y solo se sale de la funci�n.
	}
};