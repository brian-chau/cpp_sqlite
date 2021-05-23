#include <iostream>
#include "DBManager.h"
int main(int argc, char** argv)
{
    DBManager* db = new DBManager();
    db->OpenDB("library.db");
    db->CreateTables();
    db->InsertAuthor("Brian", "Chau");
    return 0;
}
