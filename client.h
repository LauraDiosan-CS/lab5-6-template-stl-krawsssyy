#pragma once
#include <vector>
#include <ostream>
#include <istream>
using namespace std;

class Client{
public:
	int id;
	char* name;
	bool hasBorrowed;
	vector<int> borrowedIDs;
public:
	Client();
	Client(int id, char* name, bool hasBorrowed = false, const vector<int>& borrowedIDs = vector<int>());
	Client(const Client& c);
	~Client();
	void setName(char* name);
	void changeBorrow();
	void addBorrow(int idBook);
	void removeBorrow(int id);
	void setVector(const vector<int>& vect);
	int getID();
	char* getClientName();
	bool getClientBorrowState();
	vector<int> getClientBorrowedIDs();
	Client& operator=(const Client& c);
	bool operator==(const Client& c) const;
	friend ostream& operator<<(ostream& os, const Client& c);
	friend istream& operator>>(istream& is, Client& c);
	bool operator<(const Client& c) const;
	bool operator>(const Client& c) const;

};

