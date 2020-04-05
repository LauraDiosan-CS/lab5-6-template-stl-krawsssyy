#include "tests.h"
#include "ui.h"

int main() {
    testBooks();
    testRepo();
    testService();
    Repo<Book> r;
    Service s(r);
    UI ui(s);
    ui.runConsole();
    return 0;
}



