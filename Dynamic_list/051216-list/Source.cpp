#include <iostream>
using namespace std;

struct coord
{
	int x;
	int y;
};

struct Node       //��������� ���������� ������ ������
{
	struct coord a;     //�������� x ����� ������������ � ������
	Node *next, *prev; //��������� �� ������ ���������� � ����������� ��������� ������
};

struct List   //������� ��� ������ ������
{
	Node *head;
	Node *tail;  //��������� �� ������ ������ ������ � ��� �����

	int searchf(int x1, int y1)
	{
		int s = 1;
		Node * temp = this->head;  // �������� ��������� �� ����� ������� ��������
		while (temp->next != NULL && (temp->a.x != x1 && temp->a.y != y1))      // ���� �� �������� ������ ��������
		{
			temp = temp->next;     //����� ������ �� ����� ���������� ��������
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
		Node * temp = this->tail;  // �������� ��������� �� ����� ������� ��������
		while (temp->prev != NULL && (temp->a.x != x1 && temp->a.y != y1))      // ���� �� �������� ������ ��������
		{
			temp = temp->prev;     //����� ������ �� ����� ���������� ��������
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
			temp = temp->next;     //����� ������ �� ����� ���������� ��������
			s++;
		}
		//s-������ ������
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
			temp = temp->next;     //����� ������ �� ����� ���������� ��������
			s++;
		}
		//s-������ ������
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
	Node *temp = new Node(); // ��������� ������ ��� ����� ������� ���������
	temp->next = NULL;       // ���������, ��� ���������� �� ���������� ������ �����
	temp->a.x = x1;             // ���������� �������� � ���������
	temp->a.y = y1;

	if (list->head != NULL) // ���� ������ �� ����
	{
		temp->prev = list->tail; // ��������� ����� �� ���������� ������� � �����. ����
		list->tail->next = temp; // ��������� ����� ���������� �� ������� ��������
		list->tail = temp;       //������ ����� ������
	}
	else //���� ������ ������
	{
		temp->prev = NULL; // ���������� ������� ��������� � �������
		list->head = list->tail = temp;    // ������=�����=��� �������, ��� ������ ��������
	}
}

void print(List * list)
{
	Node * temp = list->head;  // �������� ��������� �� ����� ������� ��������
	while (temp != NULL)      // ���� �� �������� ������ ��������
	{
		cout << "x="<<temp->a.x << " ,y="<<temp->a.y<<"\n"; //������� �������� �� �����
		temp = temp->next;     //����� ������ �� ����� ���������� ��������
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