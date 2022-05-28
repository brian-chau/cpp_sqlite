#include <iostream>

#include "DBManager.h"
int main(int argc, char** argv) {
    DBManager* db = new DBManager();
    db->OpenDB("library.db");
    std::cout << "Creating tables..." << std::endl;
    if (!db->CreateTables()) {
        std::cout << "Could not create table!" << std::endl;
    }

    std::cout << "Inserting author..." << std::endl;
    if (!db->InsertAuthor("Brian", "Chau")) {
        std::cout << "Could not create author!" << std::endl;
    }

    std::cout << "Successfully created table and inserted author!" << std::endl;
    return 0;
}
