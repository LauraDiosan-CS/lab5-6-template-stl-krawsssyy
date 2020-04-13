#pragma once
#include "service.h"


class UI {
private:
	Service& s;
	void handleAdd();
	void handleAddClient();
	void handleShowID();
	void handleShowClientID();
	void handleShowAll();
	void handleShowAllClients();
	void handleUpdate();
	void handleUpdateClient();
	void handleDelete();
	void handleDeleteClient();
	void handleBorrow();
	void handleReturn();
	void handleSave();
	void showMenu();
public:
	UI(Service& serv) : s(serv) {};
	~UI() { ; }
	void runConsole();
};


