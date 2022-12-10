#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void push_back(T data); // вставить в конец списка
	int GetSize() { return Size };
	T& operator[](const int index); //возвращать ссылку на тип Т, пергрузка оператора, принимаемый параметр - индекс

	void pop_front();
	void clear();

	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();


private:

	template<typename T> //шаблонный класс (есть видео)
	class Node // класс элемента, вложенный в класс List, в привате, т.к. этот элемент не должен быть напрямую доступен без класса list
	{
	public: // т.к. класс Node будет доступен только внутри private секции List, то можно реализовать все поля в public секции
		Node* pNext;  // указатель типа Node - указатель на следующий элемент
		// T - поле обобщенного типа. в момент создания класса List мы получаем его тип данных
		T data;
		Node(T data = T(), Node* pNext = nullptr) // полю data по умолчанию передаётся значение по умолчанию примитивного типа данных
		{
			this->data = data; // присваивание входящих данных соответсвующим полям, описанных в public секции класса Node
			this->pNext = pNext;


		}
	};

	int Size; //кол-во элементов в списке
	Node<T>* head; // все элементы односвязного списка будут выделяться в динамической памяти
};

template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
T& List<T>::operator[](const int index)
{
	// логика: итерация по списку, нахождение нужного индекса и возвращение значения по этому индексу

	int counter = 0; // в каком элементе мы находимся
	Node<t>* current = this->Head; //в каком элементе мы сейчас находимся, чтобы проверить адресс следующего элемента
	while (current != nullptr)
	{
		if (counter == in)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;

	head = head->pNext;

	delete *temp;

	Size--;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		previous->pNext = new Node<T>(data, previous->pNext);

		Size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;
	}


}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size-1)
}



int main()
{

	//selocale(LC_ALL, "ru");

	List<int> lst;
	lst.push_back(5);
	lst.push_back(10);
	lst.push_back(22);

	cout << lst.GetSize() << endl;


	return 0;
 }