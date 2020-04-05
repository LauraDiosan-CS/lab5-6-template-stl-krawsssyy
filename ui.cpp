#include "ui.h"
#include<iostream>
#include <stack>
using namespace std;


void UI::handleAdd() {
	int id;
	char* author;
	char* title;
	unsigned int year;
	char a[20];
	char t[30];
	cout << "Introduceti id = "; cin >> id; cout << endl;
	cout << "Introduceti autorul cartii = "; cin >> a; cout << endl;
	cout << "Introduceti titlul cartii = "; cin >> t; cout << endl;
	cout << "Introduceti anul aparitiei = "; cin >> year; cout << endl;
	author = new char[strlen(a) + 1];
	strcpy_s(author, strlen(a) + 1, a);
	title = new char[strlen(t) + 1];
	strcpy_s(title, strlen(t) + 1, t);
	this->s.addBook(id, author, title, year);
	delete[] author;
	author = nullptr;
	delete[] title;
	title = nullptr;
}


void UI::handleShowID() {
	int id;
	cout << "Introduceti id = "; cin >> id; cout << endl;
	Book* result = this->s.readBook(id);
	if (result != nullptr)
		cout << *result << endl;
	else
		cout << "Nu exista jucatorul cu acel id!" << endl;
}


void UI::handleShowAll() {
	priority_queue<Book> books = this->s.getAll();
	stack<Book> show;
	while (!books.empty()) {
		show.push(books.top());
		books.pop();
	}
	while (!show.empty()) {
		cout << show.top() << endl;
		show.pop();
	}
	cout << endl;
}


void UI::handleUpdate() {
	int idOrig;
	cout << "Introduceti id-ul = "; cin >> idOrig; cout << endl;
	int id;
	char* author;
	char* title;
	unsigned int year;
	char a[20];
	char t[30];
	cout << "Introduceti id = "; cin >> id; cout << endl;
	cout << "Introduceti autorul cartii = "; cin >> a; cout << endl;
	cout << "Introduceti titlul cartii = "; cin >> t; cout << endl;
	cout << "Introduceti anul aparitiei = "; cin >> year; cout << endl;
	author = new char[strlen(a) + 1];
	strcpy_s(author, strlen(a) + 1, a);
	title = new char[strlen(t) + 1];
	strcpy_s(title, strlen(t) + 1, t);
	this->s.updateBook(idOrig, id, author, title, year);
	delete[] author;
	author = nullptr;
	delete[] title;
	title = nullptr;
}


void UI::handleDelete() {
	int id;
	cout << "Introduceti id-ul = "; cin >> id; cout << endl;
	this->s.deleteBook(id);
}

void UI::showMenu() {
	cout << "1. Adaugare carte" << endl;
	cout << "2. Afisare carte dupa id" << endl;
	cout << "3. Afisare toate cartile" << endl;
	cout << "4. Modificati o carte" << endl;
	cout << "5. Stergeti o carte" << endl;
	cout << "6. Iesire" << endl;
}

void UI::runConsole() {
	char option = '0';
	while (option != '6')
	{
		this->showMenu();
		cout << endl;
		cin >> option;
		cout << endl;
		switch (option)
		{
		case '1':
			this->handleAdd();
			break;
		case '2':
			this->handleShowID();
			break;
		case '3':
			this->handleShowAll();
			break;
		case '4':
			this->handleUpdate();
			break;
		case '5':
			this->handleDelete();
			break;
		case '6':
			break;
		default:
			cout << "Optiune invalida" << endl;
			break;
		}
	}
}