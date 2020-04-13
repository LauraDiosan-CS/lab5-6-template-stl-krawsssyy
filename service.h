#pragma once
#include "repoFile.h"
#include "book.h"
#include <stack>
#include "client.h"


class Service {
private:
	repoFile<Book>& r;
	repoFile<Client>& rClient;
public:
	Service(repoFile<Book>& repoBook, repoFile<Client>& repoClient);
	~Service() {
	};
	void addBook(int id, char* author, char* title, unsigned int year);
	void addClient(int id, char* name);
	priority_queue<Book> getAll();
	priority_queue<Client> getClients();
	Book* readBook(int id);
	Client* readClient(int id);
	void updateBook(int idOrig, int id, char* author, char* title, unsigned int year, bool isBorrowed);
	void updateClient(int idOrig, int id, char* name, bool hasBorrowed, vector<int> borrowed);
	void deleteBook(int id);
	void deleteClient(int id);
	size_t getSize();
	size_t getClientsSize();
	bool borrowBook(int idReader, int idBook);
	stack<Book> getShowStack();
	stack<Client> getClientsStack();
	bool returnBook(int idBook, int idReader);
	void saveToFile();

};

