#include "service.h"


Service::Service(repoFile<Book>& repo,const char* borrowFile) : r(repo) {
	this->borrowFile = new char[strlen(borrowFile) + 1];
	strcpy_s(this->borrowFile, strlen(borrowFile) + 1, borrowFile);
	this->loadBorrowStack();
}


void Service::addBook(int id, char* author, char* title, unsigned int year) {
	Book b(id, author, title, year);
	this->r.addElement(b);
}


priority_queue<Book> Service::getAll() {
	return this->r.getAll();
}


Book* Service::readBook(int id) {
	return this->r.readEntity(id);
}


void Service::updateBook(int idOrig, int id, char* author, char* title, unsigned int year) {
	Book b(id, author, title, year);
	this->r.updateEntity(idOrig, b);
}


void Service::deleteBook(int id) {
	this->r.deleteEntity(id);
}


size_t Service::getSize() {
	return this->r.getSize();
}


bool Service::borrowBook(int idReader, int idBook) {
	Book* result = this->readBook(idBook);
	if (result) {
		this->borrowStack.push(std::make_pair(*result, idReader));
		return true;
	}
	return false;
}


stack< pair<Book, int> > Service::getBorrowStack() {
	return this->borrowStack;
}


stack< pair<Book, int> > Service::getShowStack() {
	priority_queue<Book> books = this->getAll();
	stack< pair<Book, int> > borrowStack = this->getBorrowStack();
	priority_queue< pair<Book, int> > auxQueue;
	while (!borrowStack.empty()) {
		auxQueue.push(borrowStack.top());
		borrowStack.pop();
	}
	while (!books.empty()) {
		auxQueue.push(std::make_pair(books.top(), 0));
		books.pop();
	}
	stack< pair<Book, int> > showStack;
	while (!auxQueue.empty()) {
		showStack.push(auxQueue.top());
		auxQueue.pop();
	}
	return showStack;
}

bool Service::returnBook(int idBook, int idReader) {
	stack< pair<Book, int> > borrowStackz = this->getBorrowStack();
	int ok = 0;
	while (!borrowStackz.empty()) {
		pair<Book, int> t = borrowStackz.top();
		if (t.first.getID() == idBook and t.second == idReader)
			ok = 1;
		borrowStackz.pop();
	}
	if (ok == 0)
		return false;
	else {
		stack< pair<Book, int> > rest;
		while (!this->borrowStack.empty()) {
			pair<Book, int> t = borrowStack.top();
			if (t.first.getID() != idBook)
				rest.push(t);
			else
				this->r.addElement(t.first);
			borrowStack.pop();
		}

		while (!rest.empty()) {
			borrowStack.push(rest.top());
			rest.pop();
		}
		return true;
	}

}

void Service::saveToFile() {
	this->r.saveToFile();
	if (this->borrowFile)
	{
		ofstream os(this->borrowFile);
		stack< pair<Book, int> > rez = this->borrowStack;

		while (!rez.empty()) {
			os << rez.top().first << " " << rez.top().second << endl;
			rez.pop();
		}
		os.close();
	}
}

void Service::loadBorrowStack() {
	while (!this->borrowStack.empty())
		borrowStack.pop();
	if (this->borrowFile) {
		ifstream is(borrowFile);
		Book elem;
		int id;
		while (!is.eof()) {
			is >> elem >> id;
			this->borrowStack.push(std::make_pair(elem, id));
		}
		is.close();
	}
}
