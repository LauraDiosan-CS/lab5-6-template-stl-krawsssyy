#include "service.h"


Service::Service(Repo<Book>& repo) : r(repo) {
	;
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
