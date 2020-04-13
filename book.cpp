#include "book.h"

Book::Book() {
	this->id = 0;
	this->author = nullptr;
	this->title = nullptr;
	this->year = 0;
	this->isBorrowed = false;
}

Book::Book(int id, char* author, char* title, unsigned int year, bool isBorrowed) {
	this->id = id;
	this->author = new char[strlen(author) + 1];
	strcpy_s(this->author, strlen(author) + 1, author);
	this->title = new char[strlen(title) + 1];
	strcpy_s(this->title, strlen(title) + 1, title);
	this->year = year;
	this->isBorrowed = isBorrowed;
}

Book::Book(const Book& b) {
	this->id = b.id;
	this->author = new char[strlen(b.author) + 1];
	strcpy_s(this->author, strlen(b.author) + 1, b.author);
	this->title = new char[strlen(b.title) + 1];
	strcpy_s(this->title, strlen(b.title) + 1, b.title);
	this->year = b.year;
	this->isBorrowed = b.isBorrowed;
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

void Book::changeBorrowState() {
	this->isBorrowed = !(this->isBorrowed);
}

bool Book::getBorrowState() {
	return this->isBorrowed;
}

Book& Book::operator=(const Book& b) {
	this->setID(b.id);
	this->setAuthor(b.author);
	this->setTitle(b.title);
	this->setYear(b.year);
	this->isBorrowed = b.isBorrowed;
	return *this;
}

bool Book::operator==(const Book& b) const {
	return this->id == b.id && strcmp(this->author, b.author) == 0 && strcmp(this->title, b.title) == 0 && this->year == b.year && this->isBorrowed == b.isBorrowed;
}

ostream& operator<<(ostream& os, const Book& b) {
	if (b.isBorrowed)
		os << b.id << " " << b.author << " " << b.title << " " << b.year << " 1";
	else
		os << b.id << " " << b.author << " " << b.title << " " << b.year << " 0";
	return os;
}

istream& operator>>(istream& is, Book& b) {
	char auth[20], title[30];
	int borrow = 0;
	is >> b.id >> auth >> title >> b.year >> borrow;
	b.setAuthor(auth);
	b.setTitle(title);
	if (borrow)
		b.isBorrowed = true;
	else
		b.isBorrowed = false;
	return is;
}


bool Book::operator<(const Book& b) const {
	return this->id < b.id;
}


bool Book::operator>(const Book& b) const {
	return this->id > b.id;
}