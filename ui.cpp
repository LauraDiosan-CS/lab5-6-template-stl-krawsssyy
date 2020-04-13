#include "ui.h"
#include <iostream>
#include <stack>
using namespace std;


void UI::handleAdd() {
	int id;
	char* author;
	char* title;
	unsigned int year;
	char a[20];
	char t[30];
	cout << "Introduceti id = "; cin >> id; cout << "\n";
	cout << "Introduceti autorul cartii = "; cin >> a; cout << "\n";
	cout << "Introduceti titlul cartii = "; cin >> t; cout << "\n";
	cout << "Introduceti anul aparitiei = "; cin >> year; cout << "\n";
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
	cout << "Introduceti id = "; cin >> id; cout << "\n";
	Book* result = this->s.readBook(id);
	if (result != nullptr)
		cout << *result << "\n";
	else
		cout << "Nu exista cartea cu acel id!" << "\n";
}


void UI::handleShowAll() {
	stack<Book> showStack = this->s.getShowStack();
	while (!showStack.empty()) {
		if (showStack.top().getBorrowState())
			cout << showStack.top() << " - IMPRUMUTATA" << "\n";
		else
			cout << showStack.top() << "\n";
		showStack.pop();
	}
	cout << '\n';
}


void UI::handleUpdate() {
	int idOrig;
	cout << "Introduceti id-ul = "; cin >> idOrig; cout << "\n";
	int id;
	char* author;
	char* title;
	unsigned int year;
	char a[20];
	char t[30];
	cout << "Introduceti id = "; cin >> id; cout << "\n";
	cout << "Introduceti autorul cartii = "; cin >> a; cout << "\n";
	cout << "Introduceti titlul cartii = "; cin >> t; cout << "\n";
	cout << "Introduceti anul aparitiei = "; cin >> year; cout << "\n";
	int borrow = 0;
	cout << "Introduceti 1 daca cartea este imprumutata, 0 altfel"; cin >> borrow;cout << "\n";
	author = new char[strlen(a) + 1];
	strcpy_s(author, strlen(a) + 1, a);
	title = new char[strlen(t) + 1];
	strcpy_s(title, strlen(t) + 1, t);
	if (borrow)
		this->s.updateBook(idOrig, id, author, title, year, true);
	else
		this->s.updateBook(idOrig, id, author, title, year, false);
	delete[] author;
	author = nullptr;
	delete[] title;
	title = nullptr;
}


void UI::handleDelete() {
	int id;
	cout << "Introduceti id-ul = "; cin >> id; cout << "\n";
	this->s.deleteBook(id);
}


void UI::handleBorrow() {
	int idReader = 0;
	cout << "Introduceti id-ul legitimatiei dvs = " << "\n";
	cin >> idReader;
	int idBook = 0;
	cout << "Introduceti id-ul cartii = " << "\n";
	cin >> idBook;
	bool result = this->s.borrowBook(idReader, idBook);
	if (!result)
		cout << "Cartea nu se poate imprumuta" << "\n";

}


void UI::handleReturn() {
	int idReader = 0;
	cout << "Introduceti id-ul legitimatiei dvs = " << "\n";
	cin >> idReader;
	int idBook = 0;
	cout << "Introduceti id-ul cartii = " << "\n";
	cin >> idBook;
	bool result = this->s.returnBook(idBook, idReader);
	if (!result)
		cout << "Cartea nu s-a putut inapoia!" << "\n";
}

void UI::handleSave() {
	this->s.saveToFile();
}


void UI::showMenu() {
	cout << "1. Adaugare carte" << "\n";
	cout << "2. Adaugare client" << "\n";
	cout << "3. Afisare carte dupa id" << "\n";
	cout << "4. Afisare client dupa id" << "\n";
	cout << "5. Afisare toate cartile" << "\n";
	cout << "6. Afisare toti clientii" << "\n";
	cout << "7. Modificati o carte" << "\n";
	cout << "8. Modificati un client" << "\n";
	cout << "9. Stergeti o carte" << "\n";
	cout << "10. Stergeti un client" << "\n";
	cout << "11. Imprumutati o carte" << "\n";
	cout << "12. Returnati o carte" << "\n";
	cout << "13. Salvati modificarile" << "\n";
	cout << "x. Iesire" << "\n";
}

void UI::runConsole() {
	string option = "0";
	while (option != "x")
	{
		this->showMenu();
		cout << "\n";
		cin >> option;
		cout << "\n";
		if(option == "1")
			this->handleAdd();
		if (option == "2")
			this->handleAddClient();
		if (option == "3")
			this->handleShowID();
		if (option == "4")
			this->handleShowClientID();
		if (option == "5")
			this->handleShowAll();
		if (option == "6")
			this->handleShowAllClients();
		if (option == "7")
			this->handleUpdate();
		if (option == "8")
			this->handleUpdateClient();
		if (option == "9")
			this->handleDelete();
		if (option == "10")
			this->handleDeleteClient();
		if (option == "11")
			this->handleBorrow();
		if (option == "12")
			this->handleReturn();
		if (option == "13")
			this->handleSave();
		if (option == "x")
			break;
	}
}

void UI::handleAddClient() {
	int id;
	cout << "Introduceti id-ul = "; cin >> id; cout << "\n";
	char name[20];
	cout << "Introduceti numele = "; cin >> name; cout << "\n";
	char* real = new char[strlen(name) + 1];
	strcpy_s(real, strlen(name) + 1, name);
	this->s.addClient(id, real);
	delete[] real;
	real = nullptr;
}

void UI::handleShowClientID() {
	int id;
	cout << "Introduceti id-ul = "; cin >> id; cout << "\n";
	Client* result = this->s.readClient(id);
	if (result)
		cout << result << "\n";
	else
		cout << "Clientul cu id-ul respectiv nu exista" << "\n";
}

void UI::handleShowAllClients() {
	stack<Client> show = this->s.getClientsStack();
	while (!show.empty()) {
		cout << show.top() << "\n";
		show.pop();
	}
}

void UI::handleUpdateClient() {
	int idOrig;
	cout << "Introduceti id-ul original = "; cin >> idOrig; cout << "\n";
	int id;
	cout << "Introduceti id-ul = "; cin >> id; cout << "\n";
	char name[20];
	cout << "Introduceti numele = "; cin >> name; cout << "\n";
	int borrow = 0;
	cout << "Introduceti 1 daca a imprumutat carti si 0 daca nu = "; cin >> borrow; cout << "\n";
	if (borrow) {
		cout << "Introduceti numarul de carti imprumutate = ";
		int size;
		cin >> size;
		cout << "\n";
		cout << " Introduceti id-urile cartilor imprumutate = ";
		vector<int> vect;
		for (int i = 0; i < size; i++)
		{
			int x;
			cin >> x;
			cout << "\n";
			vect.emplace_back(x);
		}
		this->s.updateClient(idOrig, id, name, true, vect);
	}
	else
		this->s.updateClient(idOrig, id, name, false, vector<int>());
}

void UI::handleDeleteClient() {
	int id;
	cout << "Introduceti id-ul = "; cin >> id; cout << "\n";
	this->s.deleteClient(id);
}