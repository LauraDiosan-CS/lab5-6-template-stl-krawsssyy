#include "service.h"


Service::Service(repoFile<Book>& repoBook, repoFile<Client>& repoClient) : r(repoBook), rClient(repoClient) {
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


void Service::updateBook(int idOrig, int id, char* author, char* title, unsigned int year, bool isBorrowed) {
	Book b(id, author, title, year, isBorrowed);
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
	Client* resultClient = this->readClient(idReader);
	if (result && resultClient) {
		if (resultClient->getClientBorrowState() ==  false)
			resultClient->changeBorrow();
		resultClient->addBorrow(result->getID());
		this->rClient.updateEntity(resultClient->getID(), *resultClient);
		result->changeBorrowState();
		this->r.updateEntity(result->getID(), *result);
		return true;
	}
	return false;
}



stack<Book> Service::getShowStack() {
	priority_queue<Book> books = this->getAll();
	stack<Book> showStack;
	while (!books.empty()) {
		showStack.push(books.top());
		books.pop();
	}
	return showStack;
}

bool Service::returnBook(int idBook, int idReader) {
	Book* result = this->readBook(idBook);
	Client* resultClient = this->readClient(idReader);
	if (result && resultClient) {
		result->changeBorrowState();
		this->r.updateEntity(result->getID(), *result);
		if (resultClient->getClientBorrowedIDs().size())
			resultClient->removeBorrow(idBook);
		if (resultClient->getClientBorrowedIDs().size() == 0)
			resultClient->changeBorrow();
		this->rClient.updateEntity(resultClient->getID(), *resultClient);
		return true;
	}
	return false;
}

void Service::saveToFile() {
	this->r.saveToFile();
	this->rClient.saveToFile();
}

void Service::addClient(int id, char* name) {
	Client c(id, name);
	this->rClient.addElement(c);
}

priority_queue<Client> Service::getClients() {
	return this->rClient.getAll();
}

Client* Service::readClient(int id) {
	return this->rClient.readEntity(id);
}

void Service::updateClient(int idOrig, int id, char* name, bool hasBorrowed, vector<int> borrowed) {
	Client c(id, name, hasBorrowed, borrowed);
	this->rClient.updateEntity(idOrig, c);
}

void Service::deleteClient(int id) {
	this->rClient.deleteEntity(id);
}

size_t Service::getClientsSize() {
	return this->rClient.getSize();
}

stack<Client> Service::getClientsStack() {
	priority_queue<Client> clients = this->rClient.getAll();
	stack<Client> showStack;
	while (!clients.empty()) {
		showStack.push(clients.top());
		clients.pop();
	}
	return showStack;
}