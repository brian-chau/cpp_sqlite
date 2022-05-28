#include <iostream>

#include "DBManager.h"
int main(int argc, char** argv) {
    DBManager* db = new DBManager();
    db->OpenDB("library.db");
    std::cout << "Creating tables..." << std::endl;
    if (db->CreateTables()) {
        if (db->InsertAuthor("Brian", "Chau")) {
            std::cout << "Successfully created author!" << std::endl;
        } else {
            std::cout << "Could not create author!" << std::endl;
        }
    } else {
        std::cout << "Could not create table!" << std::endl;
    }

    return 0;
}
