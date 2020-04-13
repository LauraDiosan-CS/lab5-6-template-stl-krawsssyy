#pragma once
#include "repo.h"
#include <fstream>
#include <stack>

template<class T>class repoFile : public Repo<T> {
private:
	char* FILE_NAME;
public:
	repoFile() : Repo() {
		this->FILE_NAME = nullptr;
	}

	repoFile(const char* FILE_NAME) {
		this->FILE_NAME = new char[strlen(FILE_NAME) + 1];
		strcpy_s(this->FILE_NAME, strlen(FILE_NAME) + 1, FILE_NAME);
		this->loadFromFile();
	}

	~repoFile() {
		if (this->FILE_NAME)
		{
			delete this->FILE_NAME;
			this->FILE_NAME = nullptr;
		}
	}

	void loadFromFile() {
		if (this->FILE_NAME) {
			ifstream is(FILE_NAME);
			T elem;
			while (is >> elem) {
				this->addElement(elem);
			}
			is.close();
		}
	}

	void saveToFile() {
		if (this->FILE_NAME)
		{
			ofstream os(this->FILE_NAME);
			stack<T> rez;
			priority_queue<T> entits = this->entities;
			while (!entits.empty()) {
				rez.push(entits.top());
				entits.pop();
			}
			while (!rez.empty()) {
				os << rez.top() << endl;
				rez.pop();
			}
			os.close();
		}
	}
};