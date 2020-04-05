#pragma once
#include "repo.h"
#include "book.h"


class Service {
private:
	Repo<Book>& r;
public:
	Service(Repo<Book>& repo);
	~Service() {};
	void addBook(int id, char* author, char* title, unsigned int year);
	priority_queue<Book> getAll();
	Book* readBook(int id);
	void updateBook(int idOrig, int id, char* author, char* title, unsigned int year);
	void deleteBook(int id);
	size_t getSize();

};

