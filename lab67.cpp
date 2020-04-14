#include "tests.h"
#include "ui.h"
#include "repoFile.h"
#include <iostream>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    testBooks();
    testClients();
    testRepo();
    testRepoFile();
    testService();
    repoFile<Book> repoBook("Books.txt");
    repoFile<Client> repoClient("Clients.txt");
    Service s(repoBook, repoClient); 
    UI ui(s);
    ui.runConsole();
    return 0;
}



