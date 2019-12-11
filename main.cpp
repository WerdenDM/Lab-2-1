#include <iostream>
#include <cmath>
using namespace std;
template < typename T >
struct  node
{
	T Е;
	node* next;
};
template < typename T >
class Linked
{
private:
	node* head;
	node* tail;
	int size;

public:
	Linked();
	~Linked();
	//добавление связи
	void Add(T);
	//удаление связи
	void Del();
	//удаление всех связей
	void DelAll();
	//вывод
	void Print();
	//поиск и удаление
	void SearchValue(T a);
	void SearchIndex(int a);
};
template < typename T >
Linked::Linked()
{
	//начало
	head = nullptr;
	//хвост
	tail = nullptr;
	//размер
	size = 0;
};
template < typename T >
Linked::~Linked()
{
	DelAll();
};
template < typename T >
void Linked::Add(T x)
{
	//выделяем память
	node* temp = new node;
	temp->x = x;
	temp->next = nullptr;
	if (head != nullptr)
	{
		tail->next = temp;
		tail = temp;
	}
	else
	{
		head = temp;
		tail = temp;
	}
}
template < typename T >
void Linked::Del()
{
	node* temp = head;
	if (head != NULL && temp != NULL)
	{
		head = head->next;
		delete temp;
	}
}
template < typename T >
void Linked::DelAll()
{
	while (head != 0)
		Del();
}
template < typename T >
void Linked::Print()
{
	node* temp = head;
	while (temp != 0)
	{
		cout << temp->x << endl;
		temp = temp->next;
	}
	cout << endl;
}
template < typename T >
void Linked::SearchValue(T a)
{
	node* temp = head;
	do
	{
		if (head->x == a)
		{
			cout << "Элемент со значением " << a " удален" << endl;
			break;
		}

		head = head->next;
	} while (head != temp);
}
template < typename T >
void Linked::SearchIndex(int a)
{
	int b = 0;
	node* tmp = head;
	if (a == 0) {
		cout << head->x;
	}
	else
	{
		tmp = head->next;
		b++;
		while (tmp != head)
		{
			if (a == b)
			{
				cout << head->x;
				break;
			}
		}
	}
	
}

int main()
{
	setlocale(0, "");
	Linked method;
	template < typename T >
	T x, y;
	for (int i = 0; i < 5; i++)
	{
		cout << "Введите x-> ";
		cin >> x;
		method.Add(x);
	}
	cout << endl;
	method.Print();
	method.Search(20);
	method.Search(20);
	method.Print(); cout << endl;
	method.Del();
	method.Del();
	method.Print();
	system("pause>>0");
	return 0;
}
