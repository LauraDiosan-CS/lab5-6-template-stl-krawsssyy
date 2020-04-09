#include "tests.h"
#include <assert.h>

void testBooks() {
	char* author1 = new char[20];
	char* author2 = new char[20];
	char* author3 = new char[20];
	char* title1 = new char[30];
	char* title2 = new char[30];
	char* title3 = new char[30];
	strcpy_s(author1, sizeof("Andrei"), "Andrei");
	strcpy_s(author2, sizeof("Alex"), "Alex");
	strcpy_s(author3, sizeof("Gabriel"), "Gabriel");
	strcpy_s(title1, sizeof("Masina timpului"), "Masina timpului");
	strcpy_s(title1, sizeof("Vrajitorul din Oz"), "Vrajitorul din Oz");
	strcpy_s(title1, sizeof("Luceafarul"), "Luceafarul");
	Book b1(1, author1, title1, 1992);
	Book b2(2, author2, title2, 2001);
	Book b3(3, author3, title3, 2012);
	assert(b1.getID() == 1);
	assert(!strcmp(b1.getAuthor(), author1));
	assert(!strcmp(b1.getTitle(), title1));
	assert(b1.getYear() == 1992);
	assert(b2.getID() == 2);
	assert(!strcmp(b2.getAuthor(), author2));
	assert(!strcmp(b2.getTitle(), title2));
	assert(b2.getYear() == 2001);
	assert(b3.getID() == 3);
	assert(!strcmp(b3.getAuthor(), author3));
	assert(!strcmp(b3.getTitle(), title3));
	assert(b3.getYear() == 2012);
	b1.setYear(2002);
	char* newAuthor = new char[20];
	strcpy_s(newAuthor, sizeof("Marcu"), "Marcu");
	b2.setAuthor(newAuthor);
	char* newTitle = new char[30];
	strcpy_s(newTitle, sizeof("Baieti de oras"), "Baieti de oras");
	b3.setTitle(newTitle);
	assert(b1.getYear() == 2002);
	assert(!strcmp(b2.getAuthor(), newAuthor));
	assert(!strcmp(b3.getTitle(), newTitle));
	delete[] newTitle;
	newTitle = nullptr;
	delete[] newAuthor;
	newAuthor = nullptr;
	delete[] title3;
	title3 = nullptr;
	delete[] title2;
	title2 = nullptr;
	delete[] title1;
	title1 = nullptr;
	delete[] author3;
	author3 = nullptr;
	delete[] author2;
	author2 = nullptr;
	delete[] author1;
	author1 = nullptr;
}


void testRepo() {
	char* author1 = new char[20];
	char* author2 = new char[20];
	char* author3 = new char[20];
	char* title1 = new char[30];
	char* title2 = new char[30];
	char* title3 = new char[30];
	strcpy_s(author1, sizeof("Andrei"), "Andrei");
	strcpy_s(author2, sizeof("Alex"), "Alex");
	strcpy_s(author3, sizeof("Gabriel"), "Gabriel");
	strcpy_s(title1, sizeof("Masina timpului"), "Masina timpului");
	strcpy_s(title1, sizeof("Vrajitorul din Oz"), "Vrajitorul din Oz");
	strcpy_s(title1, sizeof("Luceafarul"), "Luceafarul");
	Book b1(1, author1, title1, 1992);
	Book b2(2, author2, title2, 2001);
	Book b3(3, author3, title3, 2012);
	Repo<Book> repo;
	repo.addElement(b1);
	assert(repo.getSize() == 1);
	repo.addElement(b2);
	assert(repo.getSize() == 2);
	repo.addElement(b3);
	assert(repo.getSize() == 3);
	assert(*repo.readEntity(3) == b3);
	assert(*repo.readEntity(2) == b2);
	assert(*repo.readEntity(1) == b1);
	assert(repo.readEntity(4) == nullptr);
	priority_queue<Book> result;
	result = repo.getAll();
	assert(result.top() == b3);
	result.pop();
	assert(result.top() == b2);
	result.pop();
	assert(result.top() == b1);
	result.pop();
	assert(result.empty());
	repo.deleteEntity(2);
	assert(repo.getSize() == 2);
	repo.deleteEntity(4);
	assert(repo.getSize() == 2);
	Book b4(4, author1, title2, 2014);
	repo.updateEntity(1, b4);
	result = repo.getAll();
	assert(result.top() == b4);
	delete[] title3;
	title3 = nullptr;
	delete[] title2;
	title2 = nullptr;
	delete[] title1;
	title1 = nullptr;
	delete[] author3;
	author3 = nullptr;
	delete[] author2;
	author2 = nullptr;
	delete[] author1;
	author1 = nullptr;
}


//void testService() {
//	char* author1 = new char[20];
//	char* author2 = new char[20];
//	char* author3 = new char[20];
//	char* title1 = new char[30];
//	char* title2 = new char[30];
//	char* title3 = new char[30];
//	strcpy_s(author1, sizeof("Andrei"), "Andrei");
//	strcpy_s(author2, sizeof("Alex"), "Alex");
//	strcpy_s(author3, sizeof("Gabriel"), "Gabriel");
//	strcpy_s(title1, sizeof("Masina timpului"), "Masina timpului");
//	strcpy_s(title1, sizeof("Vrajitorul din Oz"), "Vrajitorul din Oz");
//	strcpy_s(title1, sizeof("Luceafarul"), "Luceafarul");
//	Book b1(1, author1, title1, 1992);
//	Book b2(2, author2, title2, 2001);
//	Book b3(3, author3, title3, 2012);
//	Repo<Book> repo;
//	Service s(repo);
//	s.addBook(1, author1, title1, 1992);
//	assert(s.getSize() == 1);
//	s.addBook(2, author2, title2, 2001);
//	assert(repo.getSize() == 2);
//	s.addBook(3, author3, title3, 2012);
//	assert(s.getSize() == 3);
//	assert(*s.readBook(3) == b3);
//	assert(*s.readBook(2) == b2);
//	assert(*s.readBook(1) == b1);
//	assert(s.readBook(4) == nullptr);
//	priority_queue<Book> result;
//	result = s.getAll();
//	assert(result.top() == b3);
//	result.pop();
//	assert(result.top() == b2);
//	result.pop();
//	assert(result.top() == b1);
//	result.pop();
//	assert(result.empty());
//	s.deleteBook(2);
//	assert(s.getSize() == 2);
//	s.deleteBook(4);
//	assert(s.getSize() == 2);
//	Book b4(4, author1, title2, 2014);
//	s.updateBook(1, 4, author1, title2, 2014);
//	result = s.getAll();
//	assert(result.top() == b4);
//	delete[] title3;
//	title3 = nullptr;
//	delete[] title2;
//	title2 = nullptr;
//	delete[] title1;
//	title1 = nullptr;
//	delete[] author3;
//	author3 = nullptr;
//	delete[] author2;
//	author2 = nullptr;
//	delete[] author1;
//	author1 = nullptr;
//}