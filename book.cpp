#include "book.h"

Book::Book() {
	this->id = 0;
	this->author = nullptr;
	this->title = nullptr;
	this->year = 0;
}

Book::Book(int id, char* author, char* title, unsigned int year) {
	this->id = id;
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
	this->year = year;
}

Book::Book(const Book& b) {
	this->id = b.id;
	this->author = new char[strlen(b.author) + 1];
	strcpy_s(this->author, strlen(b.author) + 1, b.author);
	this->title = new char[strlen(b.title) + 1];
	strcpy_s(this->title, strlen(b.title) + 1, b.title);
	this->year = b.year;
}

Book::~Book() {
	if (this->author)
		delete[] this->author, this->author = nullptr;
	if (this->title)
		delete[] this->title, this->title = nullptr;
}

void Book::setAuthor(char* author) {
	if (this->author)
		delete[] this->author, this->author = nullptr;
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);
}

void Book::setTitle(char* title) {
	if (this->title)
		delete[] this->title, this->title = nullptr;
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
}
void Book::setYear(unsigned int year) {
	this->year = year;
}

void Book::setID(int id) {
	this->id = id;
}

int Book::getID() {
	return this->id;
}

char* Book::getAuthor() {
	return this->author;
}

char* Book::getTitle() {
	return this->title;
}

int Book::getYear() {
	return this->year;
}

Book& Book::operator=(const Book& b) {
	this->setID(b.id);
	this->setAuthor(b.author);
	this->setTitle(b.title);
	this->setYear(b.year);
	return *this;
}

bool Book::operator==(const Book& b) const {
	return this->id == b.id && strcmp(this->author, b.author) == 0 && strcmp(this->title, b.title) == 0 && this->year == b.year;
}

ostream& operator<<(ostream& os, const Book& b) {
	os << b.id << "/" << b.author << "/" << b.title << "/" << b.year;
	return os;
}

bool Book::operator<(const Book& b) const {
	return this->year < b.year;
}

bool Book::operator>(const Book& b) const {
	return this->year > b.year;
}