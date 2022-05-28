#ifndef DB_MANAGER_H
#define DB_MANAGER_H
#include <sqlite3.h>

#include <string>

class DBManager {
   public:
    DBManager(std::string db_name = "");
    ~DBManager();

    bool OpenDB(std::string db_name);
    bool CreateTables();
    bool CreateBooksTable();
    bool CreateAuthorsTable();
    bool CreateAuthorsBooksTable();

    bool InsertAuthor(std::string first_name, std::string last_name);
    bool InsertBook(std::string title);

    bool LinkAuthorBook(std::string first_name, std::string last_name, std::string book);

   private:
    sqlite3 *db_instance;
    std::string m_db_name;
};
#endif
