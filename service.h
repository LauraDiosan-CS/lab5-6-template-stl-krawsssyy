#pragma once
#include "repoFile.h"
#include "book.h"
#include <stack>


class Service {
private:
	repoFile<Book>& r;
	stack< pair<Book, int> > borrowStack;
	char* borrowFile;
public:
	Service(repoFile<Book>& repo,const char* borrowFile);
	~Service() {
	};
	void addBook(int id, char* author, char* title, unsigned int year);
	priority_queue<Book> getAll();
	Book* readBook(int id);
	void updateBook(int idOrig, int id, char* author, char* title, unsigned int year);
	void deleteBook(int id);
	size_t getSize();
	bool borrowBook(int idReader, int idBook);
	stack< pair<Book, int> > getBorrowStack();
	stack< pair<Book, int> > getShowStack();
	bool returnBook(int idBook, int idReader);
	void saveToFile();
	void loadBorrowStack();

};

