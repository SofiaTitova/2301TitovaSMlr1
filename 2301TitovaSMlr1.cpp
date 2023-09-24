#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#define language 1251
#include <time.h>
#include <iomanip>


using namespace std;
struct Node // ��������� ��� �������� ������ � �����������
{
	int info;
	struct Node* next;
};

void ListPrinting(Node* start, int length) {
	cout << "��� ������: " << endl;
	Node* add = start->next;
	for (int i = 0; i < length; i++) {
		cout << add->info << endl;
		add = add->next;
	}
}

void push_back(Node* tmp, Node* head, Node* tail, int& length, int num) {
	Node* cur = head->next;
	for (int i = 1; i < length; i++) {
		cur = cur->next;
	}
	tmp = new Node;
	tmp->info = num;
	tmp->next = tail;
	cur->next = tmp;
	length++;
	ListPrinting(head, length);
}
void push_front(Node* tmp, Node* head, Node* tail, int& length, int num) {
	tmp = new Node;
	tmp->info = num;
	tmp->next = head->next;
	head->next = tmp;
	length++;
	ListPrinting(head, length);
}
void pop_back(Node* tmp, Node* head, Node* tail, int& length) {
	Node* cur = head->next;
	for (int i = 1; i < length - 1; i++) { 
		cur = cur->next;
	}
	tmp = new Node;
	tmp = cur->next;
	cur->next = tail;
	delete tmp;
	length--;
	ListPrinting(head, length);
}
void pop_front(Node* tmp, Node* head, Node* tail, int& length) {
	tmp = new Node;
	tmp = head->next;
	head->next = tmp->next;
	delete tmp;
	length--;
	ListPrinting(head, length);
}
void indexAdd(Node* tmp, Node* head, Node* tail, int& length, int indx, int num) {
	if (indx == 1) {
		push_front(tmp, head, tail, length, num);
	}
	if (indx == length + 1) {
		push_back(tmp, head, tail, length, num);
	}
	else if ((indx != 1) and (indx != length + 1) ){
		if ((indx <= length) and (indx >= 0)) {
			Node* cur = head->next;
			for (int i = 1; i < indx - 1; i++) {
				cur = cur->next;
			}
			tmp = new Node;
			tmp->info = num;
			tmp->next = cur->next;
			cur->next = tmp;
			length++;
			ListPrinting(head, length);
		}
		else { cout << "����� �� ������� ������, ������� � ����� �������� �����������" << endl; }
	}
}
Node* findInList(Node* head, int& length, int indx) {

	if ((indx <= length) and (indx >= 0)) {
		Node* tmp = head->next;
		for (int i = 1; i < indx; i++) {
			tmp = tmp->next;
		}
		return tmp;
	}
	else { cout << "����� �� ������� ������, ������� � ����� �������� �����������" << endl; }

}
void indexDel(Node* tmp, Node* head, Node* tail, int& length, int indx) {
	if ((indx <= length) and (indx >= 0)) {
		Node* cur = head->next;
		if (indx == 1) {
			pop_front(tmp, head, tail, length);
		}
		else {
			for (int i = 1; i < indx - 1; i++) {
				cur = cur->next;
			}
			tmp = new Node;
			tmp = cur->next;
			cur->next = tmp->next;
			delete tmp;
			length--;
			ListPrinting(head, length);
		}
	}
	else { cout << "����� �� ������� ������, ������� � ����� �������� �����������" << endl; }
}

void listClear(Node* tmp, Node* head, Node* tail, int& length, int indx) {
	tmp = new Node;
	while (length != 0) {
		pop_front(tmp, head, tail, length);
	}
	ListPrinting(head, length);
}

void indReplace(Node* head, Node* tail, int& length, int indx, int num) {
	if ((indx <= length) and (indx >= 0)) {
		Node* cur = head->next;
		for (int i = 0; i < indx - 1; i++) {
			cur = cur->next;
		}
		cur->info = num;
		ListPrinting(head, length);
	}
	else { cout << "����� �� ������� ������, ������� � ����� �������� �����������" << endl; }
}

void emptyCheck(int& length) {
	if (length == 0) {
		cout << "������ ������" << endl;
	}
	else cout << "������ �� ������" << endl;
}

void newToEnd(Node* head, Node* tail, int& length, bool& insert, Node* start, Node* end, int& lengthSec) {
	Node* cur = head->next;
	Node* cur2 = start->next;
	for (int i = 1; i < length; i++) {
		cur = cur->next;
	}
	cur->next = start->next;
	for (int i = 1; i < lengthSec; i++) {
		cur2 = cur2->next;
	}
	cur2->next = tail;
	length += lengthSec;
	insert = true;
	ListPrinting(head, length);
}

void newToStart(Node* head, Node* tail, int& length, bool& insert, Node* start, Node* end, int& lengthSec) {
	Node* cur2 = start->next;
	for (int i = 1; i < lengthSec; i++) {
		cur2 = cur2->next;
	}
	cur2->next = head->next;
	head->next = start->next;
	length += lengthSec;
	insert = true;
	ListPrinting(head, length);
}

void insertance(bool insert) {
	if (insert) {
		cout << "������ ��� �������� � ������" << endl;
	}
	else {
		cout << "������� ������ � ������ �� ����" << endl;
	}
}

void entFirst(Node* head, Node* tail, Node* start, Node* end, bool& insert, int& length) {
	Node* add = head;
	int index = 1;
	while (!(add->next == start->next)) {
		index += 1;
		add = add->next;
	}
	insert = true;
	cout << "������ ��������� ������ � ������ (������): " << index << endl;
}

void entLast(Node* head, Node* tail, Node* start, Node* end, bool& insert, int& length, int lengthSec) {
	Node* add = head;
	int index = 0;
	while (!(add->next == start->next)) {
		index += 1;
		add = add->next;
	}
	insert = true;
	cout << "��������� ��������� ������ � ������ (������): " << index + lengthSec << endl;
}

void entIndex(Node* head, Node* tail, int& length, bool& insert, Node* start, Node* end, int& lengthSec, int indx) {
	if (indx == 1) {
		newToStart(head, tail, length, insert, start, end, lengthSec);

	}
	if (indx == length + 1) {
		newToEnd(head, tail, length, insert, start, end, lengthSec);
	}
	else if (indx != 1) {
		if ((indx <= length) and (indx >= 0)) {
			Node* cur = head->next;
			for (int i = 1; i < indx - 1; i++) {
				cur = cur->next;
			}
			Node* cur2 = cur->next;
			cur->next = start->next;
			Node* cur3 = start->next;
			for (int i = 1; i < lengthSec; i++) {
				cur3 = cur3->next;
			}
			cur3->next = cur2;
			length += lengthSec;
			insert = true;
			ListPrinting(head, length);
		}
		else { cout << "����� �� ������� ������, ������� � ����� �������� �����������" << endl; }
	}
}

void swap(Node* head, Node* tail, int& length, int num1, int num2) {
	int temp;
	Node* add1 = findInList(head, length, num1);
	Node* add2 = findInList(head, length, num2);
	temp = add1->info;
	add1->info = add2->info;
	add2->info = temp;
}

void reversList(Node*& head, Node*& tail, int& length) {
	Node* cur = head->next;
	int fir = 1;
	int sec = length;
	while (fir <= ceil(length / 2)) {
		swap(head, tail, length, fir, sec);
		fir++;
		sec--;
	}
	ListPrinting(head, length);
}
int menu()
{
	int m;
	cout << " --------------------------------" << endl;
	cout << " �������� ����� : \n\n";
	cout << " 1 - ���������� � ����� ������\n";
	cout << " 2 - ���������� � ������ ������\n";
	cout << " 3 - �������� ���������� ��������\n";
	cout << " 4 - �������� ������� ��������\n";
	cout << " 5 - ���������� �������� �� �������\n";
	cout << " 6 - ��������� �������� �� �������\n";
	cout << " 7 - �������� �������� �� �������\n";
	cout << " 8 - ��������� ������� ������\n";
	cout << " 9 - �������� ���� ��������� ������\n";
	cout << " 10 - ������ �������� �� ������� �� ������������ �������\n";
	cout << " 11 - �������� �� ������� ������\n";
	cout << " 12 - ������ ������� ��������� � ������ �� ��������\n";//
	cout << " 13 - ������� ������� ������ � ������, ������� � �������\n";
	cout << " 14 - ������� ������� ������ � �����\n";
	cout << " 15 - ������� ������� ������ � ������\n";
	cout << " 16 - �������� �� ���������� ������� ������ � ������\n";
	cout << " 17 - ����� ������� ��������� ������� ������ � ������\n";
	cout << " 18 - ����� ���������� ��������� ������� ������ � ������\n";
	cout << " 19 - ����� ���� ��������� ������ �� ��������\n";
	cout << " 0 - �����\n";
	cout << " --------------------------------" << endl << endl;
	cin >> m;
	return m;
}
int menuSec() {
	int m;
	cout << " --------------------------------" << endl;
	cout << " �������� ����� : \n\n";
	cout << " 1 - ���������� ��������\n";
	cout << " 0 - ��������� �����\n";
	cout << " --------------------------------" << endl;
	cin >> m;
	return m;
}
int main() {

	SetConsoleCP(language); // ��������� ������� ����� � ������ �����
	SetConsoleOutputCP(language); // ��������� ������� ����� � ������ ������
	Node* headFir = new Node;
	Node* headSec = new Node;
	Node* tailFir = new Node;
	Node* tailSec = new Node;
	int lengthFir = 0;
	int lengthSec = 0;
	Node* temp = NULL;
	int ElFirst;
	int ElSecond;
	int choice = 0;
	int helper = 0;
	int choiceAdd = 0;
	int element = 0;
	bool insert = false;

	bool addList = true;
	cout << "�������� �������������� ������, �c�� ����������" << endl;
	cout << "������� ���������� ������: " << endl;
	cin >> ElSecond;
	temp = new Node;
	temp->info = ElSecond;
	temp->next = tailSec;
	headSec->next = temp;
	lengthSec++;
	ListPrinting(headSec, lengthSec);

	while (addList)
	{
		switch (menuSec())
		{
		case 1:
			cout << "������� �����, ������� ������ ��������" << endl;
			cin >> element;
			push_back(temp, headSec, tailSec, lengthSec, element);
			break;
		case 0: addList = false;
			break;
		default: cout << "�������� �����!" << endl;
			break;
		}
	}

	cout << "������� ���������� �������� ������: " << endl;
	cin >> ElFirst;
	temp = new Node;
	temp->info = ElFirst;
	temp->next = tailFir;
	headFir->next = temp;
	lengthFir++;
	ListPrinting(headFir, lengthFir);
	double time_taken = 0;
	bool ex = true;
	while (ex)
	{
		switch (menu())
		{
		case 1:
			cout << "������� �����, ������� ������ ��������" << endl;
			cin >> choice;
			push_back(temp, headFir, tailFir, lengthFir, choice);
			break;
		case 2:
			cout << "������� �����, ������� ������ ��������" << endl;
			cin >> choice;
			push_front(temp, headFir, tailFir, lengthFir, choice);
			break;
		case 3:
			cout << "������ ��������� ������� ������" << endl;
			pop_back(temp, headFir, tailFir, lengthFir);
			break;
		case 4:
			cout << "������ ������ ������� ������" << endl;
			pop_front(temp, headFir, tailFir, lengthFir);
			break;
		case 5:
			cout << "������� ������, �� �������� �� ������ �������� �������" << endl;
			cin >> choice;
			cout << "������� �����, ������� ������ ��������" << endl;
			cin >> helper;
			indexAdd(temp, headFir, tailFir, lengthFir, choice, helper);
			break;
		case 6:
			cout << "������� ������ ��������, ����� �������� �������" << endl;
			cin >> choice;
			cout << "�������� �������� �� ������� �������: ";
			temp = findInList(headFir, lengthFir, choice);
			cout << temp->info << endl;
			break;
		case 7:
			cout << "������� ������, �� �������� �� ������ ������� �������" << endl;
			cin >> choice;
			indexDel(temp, headFir, tailFir, lengthFir, choice);
			break;
		case 8:
			cout << "������ ������ ������: " << lengthFir << endl;
			break;
		case 9:
			listClear(temp, headFir, tailFir, lengthFir, choice);
			cout << "�������� �������! ��� ������ ����." << endl;
			break;
		case 10:
			cout << "������� ������ ��������, ������� ������ ��������" << endl;
			cin >> choice;
			cout << "�� ��� ������ ��������" << endl;
			cin >> helper;
			indReplace(headFir, tailFir, lengthFir, choice, helper);
			break;
		case 11:
			emptyCheck(lengthFir);
			break;
		case 12:
			cout << "������ � ��������� �������" << endl;
			reversList(headFir, tailFir, lengthFir);
			break;
		case 13:
			cout << "������� ������, � �������� �� ������ �������� ������ ������" << endl;
			cin >> choice;
			entIndex(headFir, tailFir, lengthFir, insert, headSec, tailSec, lengthSec, choice);
			break;
		case 14:
			newToEnd(headFir, tailFir, lengthFir, insert, headSec, tailSec, lengthSec);
			break;
		case 15:
			newToStart(headFir, tailFir, lengthFir, insert, headSec, tailSec, lengthSec);
			break;
		case 16:
			insertance(insert);
			break;
		case 17:
			if (insert) {
				entFirst(headFir, tailFir, headSec, tailSec, insert, lengthFir);
			}
			else {
				cout << "��������� � ������ ���" << endl;
			}
			break;
		case 18:
			if (insert) {
				entLast(headFir, tailFir, headSec, tailSec, insert, lengthFir, lengthSec);
			}
			else {
				cout << "��������� � ������ ���" << endl;
			}
			break;
		case 19:
			cout << "������� ������ ������� ��������" << endl;
			cin >> choice;
			cout << "������� ������ ������� ��������" << endl;
			cin >> helper;
			swap(headFir, tailFir, lengthFir, choice, helper);
			ListPrinting(headFir, lengthFir);
			break;
		case 0: ex = false;
			break;
		default: cout << "�������� �����!" << endl;
			break;
		}
	}
	return 0;
}
  