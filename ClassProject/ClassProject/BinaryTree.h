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
	public: // por defecto en una struct, todo es público, pero lo pongo por claridad.
		Node(U in_data, Node<U>* in_parent, Node<U>* in_left=nullptr, Node<U>* in_right=nullptr):
			data(in_data), parent(in_parent), left(in_left), right(in_right)
		{
		}

		~Node() 
		{
		}

		U data; // datos que va a guardar este nodo.
		Node<U>* parent; // referencia al nodo padre de este nodo dentro del árbol.
		Node<U>* left; // Hijo izquierdo
		Node<U>* right; // Hijo derecho.
	};

	Node<T>* root; // Nodo raíz del árbol.

public:
	BinaryTree(): root(nullptr)
	{
	}

	~BinaryTree()
	{
		// Aquí es donde sí tenemos que destruir los nodos restantes
		// PENDIENTE.
	}

	Node<T>* GetRoot()
	{
		return root;
	}

	// regresa el mínimo de un Subárbol a partir del nodo raíz de dicho subárbol.
	Node<T>* MinimumFromNode(Node<T>* in_root)
	{
		Node<T>* temp = in_root;
		while (temp->left != nullptr)
		{
			temp = temp->left;
		}
		return temp;
	}

	// regresa el mínimo desde la raíz del árbol
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

	// Máximo de un subárbol con raíz en in_root
	Node<T>* MaximumFromNode(Node<T>* in_root)
	{
		Node<T>* temp = in_root;
		while (temp->right != nullptr)
		{
			temp = temp->right;
		}
		return temp;
	}

	// Máximo de todo el árbol.
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
				// Los valores repetidos, se añadirán como nodos en el subárbol derecho
				// porque así lo establece el pseudocódigo del libro.
				// Pero hay otras variantes que lo pueden manejar de otra manera,para obtener ciertos beneficios.
				temp = temp->right;
			}
		}
		// temp puede ser nullptr si no se encontró un nodo con data==value; si sí se encontró, pues temp es 
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
				// Los valores repetidos, se añadirán como nodos en el subárbol derecho
				// porque así lo establece el pseudocódigo del libro.
				// Pero hay otras variantes que lo pueden manejar de otra manera,para obtener ciertos beneficios.
				temp_parent = temp;
				temp = temp->right;
			}
		}

		// Cuando se salga de este while, ya estamos donde deberíamos de insertar Value
		// Necesitamos decirle a este nodo nuevo, quién es su nodo padre.		
		Node<T>* newNode = new Node<T>(value, temp_parent);
		// Ahora hacemos la conexión de padre a hijo, dependiendo de si es hijo izquierdo o derecho.
		if (temp_parent == nullptr)
		{
			// entonces el árbol estaba vacío.
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
			// entonces sí tiene un subárbol derecho. Necesitamos el nodo más chico de dicho subárbol derecho
			return MinimumFromNode(in_x->right);
		}
		else
		{
			// empezamos con el padre del nodo al cual queremos encontrar su sucesor.
			Node<T>* current = in_x;  // current es 9
			Node<T>* temp_parent = in_x->parent; // temp parent es 8
			while (temp_parent != nullptr && temp_parent->right == current)
			{
				// Si seguimos siendo el hijo derecho de nuestro padre, todavía no vamos a romper este while.
				current = current->parent; // ahora current es 5
				temp_parent = current->parent; // ahora el padre de current es nullptr
			}
			return temp_parent; // se regresa el nodo nullptr
		}
	}

	// Aquí iría la función Predecessor()
	// Node<T>* Predecessor(Node<T>* in_x)
	//{}


	/*
	*	In Order
		Viaja al sub-árbol izquierdo de este nodo, recursivamente.
		Visita el nodo actual.
		Viaja al sub-árbol derecho de este nodo, recursivamente.
	*/
	void InOrder(Node<T>* in_x)
	{
		if (in_x != nullptr)
		{
			InOrder(in_x->left);
			std::cout << in_x->data <<", ";
			InOrder(in_x->right);
		}
		// Si no, no se hace nada, y solo se sale de la función.
	}

	/*
	*	Pre-Order
	Visita el nodo actual.
	Viaja al sub-árbol izquierdo de este nodo, recursivamente.
	Viaja al sub-árbol derecho de este nodo, recursivamente.
	*/
	void PreOrder(Node<T>* in_x)
	{
		if (in_x != nullptr)
		{
			std::cout << in_x->data << ", ";
			PreOrder(in_x->left);
			PreOrder(in_x->right);
		}
		// Si no, no se hace nada, y solo se sale de la función.
	}

	/*
	*	Post-Order
	Viaja al sub-árbol izquierdo de este nodo, recursivamente.
	Viaja al sub-árbol derecho de este nodo, recursivamente.
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
		// Si no, no se hace nada, y solo se sale de la función.
	}
};