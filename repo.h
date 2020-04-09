#pragma once
#include <queue>
using namespace std;

template <class T> class Repo {
protected:
	priority_queue<T> entities;
public:
	Repo() { 
		;
	}

	~Repo() {
		;
	}

	void addElement(T& s) {
		this->entities.push(s);
	}

	priority_queue<T> getAll() {
		return this->entities;
	}

	size_t getSize() {
		return this->entities.size();
	}

	void updateEntity(int id, const T& p) {
		priority_queue<T> aux;
		while (!this->entities.empty()) {
			T ax = this->entities.top();
			if (ax.getID() == id)
			{
				this->entities.pop();
				this->entities.push(p);
				break;
			}
			aux.push(this->entities.top());
			this->entities.pop();
		}
		while (!aux.empty()) {
			this->entities.push(aux.top());
			aux.pop();
		}
	}

	void deleteEntity(int id) {
		priority_queue<T> aux;
		while (!this->entities.empty()) {
			T ax = this->entities.top();
			if (ax.getID() == id)
			{
				this->entities.pop();
				break;
			}
			aux.push(this->entities.top());
			this->entities.pop();
		}
		while (!aux.empty()){
			this->entities.push(aux.top());
			aux.pop();
		}
	}

	T* readEntity(int id) {
		priority_queue<T> aux = this->entities;
		while (!aux.empty()) {
			T ax = aux.top();
			if (ax.getID() == id)
			{
				T* t = new T(ax);
				return t;
			}
			aux.pop();
		}
		return nullptr;
	}

	void setQueue(priority_queue<T> t) {
		swap(this->entities, t);
	}
};

