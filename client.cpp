#include "client.h"
#include <algorithm>

Client::Client() {
	this->id = 0;
	this->name = nullptr;
	this->hasBorrowed = false;
}

Client::Client(int id, char* name, bool hasBorrowed, const vector<int>& borrowedIDs) {
	this->id = id;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	this->hasBorrowed = hasBorrowed;
	if(borrowedIDs.begin() != borrowedIDs.end())
		copy(borrowedIDs.begin(), borrowedIDs.end(), back_inserter(this->borrowedIDs));

}

Client::Client(const Client& c) {
	this->id = c.id;
	this->name = new char[strlen(c.name) + 1];
	strcpy_s(this->name, strlen(c.name) + 1, c.name);
	this->hasBorrowed = c.hasBorrowed;
	if (c.borrowedIDs.size()) {
		this->borrowedIDs.resize(c.borrowedIDs.size());
		copy(c.borrowedIDs.begin(), c.borrowedIDs.end(), back_inserter(this->borrowedIDs));
	}
}

Client::~Client() {
	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->borrowedIDs.clear();
}

void Client::setName(char* name) {
	if (this->name)
	{
		delete[] this->name;
		this->name = nullptr;
	}
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Client::changeBorrow() {
	if (this->hasBorrowed)
		this->borrowedIDs.clear(), this->hasBorrowed = !(this->hasBorrowed);
	else
		this->hasBorrowed = !(this->hasBorrowed);
}

void Client::removeBorrow(int id) {
	if (!this->borrowedIDs.empty())
		this->borrowedIDs.erase(std::remove(this->borrowedIDs.begin(), this->borrowedIDs.end(), id), this->borrowedIDs.end());
}
int Client::getID() {
	return this->id;
}

void Client::addBorrow(int idBook) {
	this->borrowedIDs.emplace_back(idBook);
}

void Client::setVector(const vector<int>& vect) {
	this->borrowedIDs.clear();
	copy(vect.begin(), vect.end(), back_inserter(this->borrowedIDs));
}

char* Client::getClientName() {
	return this->name;
}

bool Client::getClientBorrowState() {
	return this->hasBorrowed;
}

vector<int> Client::getClientBorrowedIDs() {
	return this->borrowedIDs;
}

Client& Client::operator=(const Client& c) {
	this->id = c.id;
	this->setName(c.name);
	this->hasBorrowed = c.hasBorrowed;
	this->setVector(c.borrowedIDs);
	return *this;
}

bool Client::operator==(const Client& c) const {
	return this->id == c.id && strcmp(this->name, c.name) == 0 && this->hasBorrowed == c.hasBorrowed && this->borrowedIDs == c.borrowedIDs;
}

ostream& operator<<(ostream& os, const Client& c) {
	if (c.hasBorrowed) {
		os << c.id << " " << c.name << " " << " 1 " << c.borrowedIDs.size() << " ";
		for (auto& elem : c.borrowedIDs)
			os << elem << " ";
	}
	else
		os << c.id << " " << c.name << " " << " 0";
	return os;
}

istream& operator>>(istream& is, Client& c) {
	char name[20];
	int borrow = 0;
	is >> c.id >> name >> borrow;
	c.setName(name);
	if (borrow) {
		c.hasBorrowed = true;
		int size = 0;
		vector<int> vect;
		is >> size;
		for (int i = 0; i < size; i++) {
			int x;
			is >> x;
			vect.emplace_back(x);
		}
		c.setVector(vect);
	}
	else
		c.hasBorrowed = false;
	return is;
}

bool Client::operator<(const Client& c) const {
	return this->id < c.id;
}

bool Client::operator>(const Client& c) const {
	return this->id > c.id;
}