#include "tests.h"
#include "ui.h"
#include "repoFile.h"

int main() {
    testBooks();
    testRepo();
    //testService();
    repoFile<Book> r("Books.txt");
    Service s(r, "Borrow.txt");
    UI ui(s);
    ui.runConsole();
    return 0;
}


/* Client : id, nume */
