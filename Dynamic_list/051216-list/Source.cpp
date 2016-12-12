#include <iostream>
using namespace std;

struct coord
{
	int x;
	int y;
};

struct Node       //Структура являющаяся звеном списка
{
	struct coord a;     //Значение x будет передаваться в список
	Node *next, *prev; //Указатели на адреса следующего и предыдущего элементов списка
};

struct List   //Создаем тип данных Список
{
	Node *head;
	Node *tail;  //Указатели на адреса начала списка и его конца

	int searchf(int x1, int y1)
	{
		int s = 1;
		Node * temp = this->head;  // Временно указываем на адрес первого элемента
		while (temp->next != NULL && (temp->a.x != x1 && temp->a.y != y1))      // Пока не встретим пустое значение
		{
			temp = temp->next;     //Смена адреса на адрес следующего элемента
			s++;
		}
		cout << "s=" << s<<"\n";
		if (temp->a.x == x1 && temp->a.y == y1)
		{
			return s;
		}
		else
			return 0;
	}

	int searchl(int x1, int y1)
	{
		int s = 1;
		Node * temp = this->tail;  // Временно указываем на адрес первого элемента
		while (temp->prev != NULL && (temp->a.x != x1 && temp->a.y != y1))      // Пока не встретим пустое значение
		{
			temp = temp->prev;     //Смена адреса на адрес следующего элемента
			s++;
		}
		cout << "s=" << s << "\n";
		if (temp->a.x == x1 && temp->a.y == y1)
		{
			return s;
		}
		else
			return 0;
	}

	void del(int pos)
	{
		int s = 0;
		Node * temp = this->head;
		while (temp->next != NULL)
		{
			temp = temp->next;     //Смена адреса на адрес следующего элемента
			s++;
		}
		//s-длинна списка
		if (pos <= s)
		{
			Node * temp = this->head;
			for (int i = 0; i < pos; i++)
			{
				temp = temp->next;
			}
			temp->next = temp->next->next;
			temp->next->prev = temp;
		}
		else
			cout << "Error, list is too short";
	}

	void insert(int pos, int x1, int y1)
	{
		int s = 0;
		Node * temp = this->head;
		while (temp->next != NULL)
		{
			temp = temp->next;     //Смена адреса на адрес следующего элемента
			s++;
		}
		//s-длинна списка
		if (pos <= s)
		{
			Node * temp = this->head;
			for (int i = 0; i < pos; i++)
			{
				temp = temp->next;
			}
			Node* t = new Node();
			t->a.x = x1; t->a.y = y1;
			t->next = temp->next;
			temp->next = t;
		}
		else
			cout << "Error, list is too short";
	}

};

void add(List *list, int x1, int y1)
{
	Node *temp = new Node(); // Выделение памяти под новый элемент структуры
	temp->next = NULL;       // Указываем, что изначально по следующему адресу пусто
	temp->a.x = x1;             // Записываем значение в структуру
	temp->a.y = y1;

	if (list->head != NULL) // Если список не пуст
	{
		temp->prev = list->tail; // Указываем адрес на предыдущий элемент в соотв. поле
		list->tail->next = temp; // Указываем адрес следующего за хвостом элемента
		list->tail = temp;       //Меняем адрес хвоста
	}
	else //Если список пустой
	{
		temp->prev = NULL; // Предыдущий элемент указывает в пустоту
		list->head = list->tail = temp;    // Голова=Хвост=тот элемент, что сейчас добавили
	}
}

void print(List * list)
{
	Node * temp = list->head;  // Временно указываем на адрес первого элемента
	while (temp != NULL)      // Пока не встретим пустое значение
	{
		cout << "x="<<temp->a.x << " ,y="<<temp->a.y<<"\n"; //Выводим значение на экран
		temp = temp->next;     //Смена адреса на адрес следующего элемента
	}
	cout << "\n";
}



int main() {
	List list;
	list.head = list.tail = NULL;
	for (int i = 0; i < 20; i++)
		add(&list, i, i + 1);
	int uu = list.searchf(3, 4);
	//list.insert(5, 0, 1);
	//print(&list);
	list.del(6);
	print(&list);
	system("pause");
	return 0;
}