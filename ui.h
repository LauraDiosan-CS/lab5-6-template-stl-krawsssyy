#pragma once
#include "service.h"


class UI {
private:
	Service& s;
	void handleAdd();
	void handleShowID();
	void handleShowAll();
	void handleUpdate();
	void handleDelete();
	void handleBorrow();
	void handleReturn();
	void handleSave();
	void showMenu();
public:
	UI(Service& serv) : s(serv) {};
	~UI() { ; }
	void runConsole();
};


