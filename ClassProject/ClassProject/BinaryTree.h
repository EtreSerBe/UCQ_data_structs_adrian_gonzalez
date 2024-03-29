#pragma once

#include <iostream>
// BinaryTree::Node
#include <stack>


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
		while (root != nullptr)
		{
			DeleteNode(root);
		}
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
	Node<T>* Predecessor(Node<T>* in_x)
	{
		if (in_x->left != nullptr)
		{
			// entonces s� tiene un sub�rbol derecho. Necesitamos el nodo m�s chico de dicho sub�rbol derecho
			return MaximumFromNode(in_x->left);
		}
		else
		{
			// empezamos con el padre del nodo al cual queremos encontrar su sucesor.
			Node<T>* current = in_x;  // current es 9
			Node<T>* temp_parent = in_x->parent; // temp parent es 8
			while (temp_parent != nullptr && temp_parent->left == current)
			{
				// Si seguimos siendo el hijo derecho de nuestro padre, todav�a no vamos a romper este while.
				current = current->parent; // ahora current es 5
				temp_parent = current->parent; // ahora el padre de current es nullptr
			}
			return temp_parent; // se regresa el nodo nullptr
		}
	}

	void InOrderInverseIterative()
	{
		Node<T>* max = Maximum();
		while (max != nullptr)
		{
			std::cout << max->data << ", ";
			max = Predecessor(max);
		}
		std::cout << "\n";
	}

	void InOrderIterative()
	{
		Node<T>* min = Minimum();
		while (min != nullptr)
		{
			std::cout << min->data << ", ";
			min = Sucessor(min);
		}
		std::cout << "\n";
	}

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

	void PreOrderIterative()
	{
		// stack donde se van a ir metiendo los elementos.
		std::stack<Node<T>*> tempStack = std::stack<Node<T>*>();

		// inmediatamente metes la root
		tempStack.push(root);

		// mientras haya nodos en la stack (haya nodos por visitar), vas a sacar el del top
		while (tempStack.empty() == false)
		{
			Node<T>* currentNode = tempStack.top();
			tempStack.pop();  // lo sacamos porque ya no lo vamos a necesitar.

			// imprimir
			std::cout << currentNode->data << ", ";


			// OJO: a diferencia del PreOrderRecursivo, aqu� se mete primero el derecho porque estamos usando una pila
			// metes su hijo derecho (si hay)
			if (currentNode->right != nullptr)
			{
				tempStack.push(currentNode->right);
			}

			// metes su hijo izquierdo (si hay)
			if (currentNode->left!= nullptr)
			{
				tempStack.push(currentNode->left);
			}
		}



		
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

	void Transplant(Node<T>* in_u, Node<T>* in_v)
	{
		if (in_u->parent == nullptr)
		{
			// Entonces U es el nodo ra�z. Actualizamos la ra�z del �rbol
			root = in_v;
		}
		else if (in_u == in_u->parent->left)
		{
			// Si U es el hijo izquierdo de su padre, 
			// le dices al padre que ahora su hijo izquierdo 
			// ser� V
			in_u->parent->left = in_v;
		}
		else
		{
			// Si no era el hijo izquierdo, entonces era el derecho
			// y hay que actualizarlo de U a V
			in_u->parent->right = in_v;
		}
		if (in_v != nullptr)
		{
			// Si V s� es un nodo, pone que el padre de V
			// es el mismo que el padre de U
			in_v->parent = in_u->parent;
		}
	}

	void DeleteNode(Node<T>* in_z)
	{

		if (in_z->left == nullptr)
		{
			// Si el hijo izquierdo de Z es nullptr,
			// entonces remplazamos Z por su hijo derecho.
			Transplant(in_z, in_z->right);
		}
		else if (in_z->right == nullptr)
		{
			// Si el hijo derecho de Z es nullptr,
			// entonces remplazamos Z por su hijo izquierdo.
			Transplant(in_z, in_z->left);
		}
		else
		{ 
			// Todo esto es para el caso 3, que es el complicado del Delete
			// Primero, obtenemos el sucesor de Z
			Node<T>* Y = MinimumFromNode(in_z->right);
			// Checamos que Y no sea el sucesor inmediato a la derecha
			if (Y != in_z->right)
			{
				// Entonces este es el caso engorroso.
				Transplant(Y, Y->right);
				// Despu�s, le decimos a Y que su derecha es ahora la 
				// derecha del Nodo Z que estamos quitando.
				Y->right = in_z->right;
				// Y le decimos al hijo derecho de Z que ahora su padre debe ser Y
				Y->right->parent = Y;
			}
			// Mover al sucesor al espacio de Z (al que vamos a quitar)
			Transplant(in_z, Y);
			// Quitarle el sub�rbol izquierdo a Z y d�rselo a Y
			Y->left = in_z->left;
			// Decirle al sub�rbol izquierdo de Y, que ponga a Y como su padre
			Y->left->parent = Y;
		}

		// finalmente, sin importar cu�l caso de Delete se us�, es necesario borrar al nodo Z.
		delete in_z;
	}

};