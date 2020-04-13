#pragma once
#include <ostream>
#include <istream>
using namespace std;

class Book {
private:
	int id;
	char* author;
	char* title;
	unsigned int year;
	bool isBorrowed = false;
	void setID(int id);
public:
	Book();
	Book(int id, char* author, char* title, unsigned int year, bool isBorrowed = false);
	Book(const Book& b);
	~Book();
	void changeBorrowState();
	bool getBorrowState();
	void setAuthor(char* author);
	void setTitle(char* title);
	void setYear(unsigned int year);
	char* getAuthor();
	char* getTitle();
	int getID();
	int getYear();
	Book& operator=(const Book& b);
	bool operator==(const Book& b) const;
	friend ostream& operator<<(ostream& os,const Book& b);
	friend istream& operator>>(istream& is, Book& b);
	bool operator<(const Book& b) const;
	bool operator>(const Book& b) const;
}; 