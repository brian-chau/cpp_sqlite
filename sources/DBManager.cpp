#include "DBManager.h"
#define FMT_HEADER_ONLY
#include <fmt/core.h>

#include <iostream>
DBManager::DBManager(std::string db_name)
    : db_instance(NULL), m_db_name(db_name) {
}

DBManager::~DBManager() {
    if (NULL != db_instance) {
        sqlite3_close(db_instance);
    }
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    return 0;
}

bool DBManager::OpenDB(std::string db_name) {
    m_db_name = db_name;
    int rc = sqlite3_open(m_db_name.c_str(), &db_instance);
    if (rc) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db_instance) << std::endl;
        return false;
    } else {
        std::cout << "Opened database successfully" << std::endl;
        return true;
    }
}

bool DBManager::CreateTables() {
    return CreateBooksTable() && CreateAuthorsTable();
}

bool DBManager::CreateBooksTable() {
    // BJC TODO: Create ISBN field and make it unique
    std::string sql =
        "CREATE TABLE Books ("
        "BOOK_ID  INTEGER  PRIMARY KEY  UNIQUE,"
        "TITLE    TEXT                  NOT NULL);";

    return (sqlite3_exec(db_instance, sql.c_str(), callback, 0, NULL) == 0);
}

bool DBManager::CreateAuthorsTable() {
    std::string sql =
        "CREATE TABLE Authors ("
        "AUTHOR_ID   INTEGER  PRIMARY KEY  UNIQUE,"
        "FIRST_NAME  TEXT                  NOT NULL,"
        "LAST_NAME   TEXT                  NOT NULL);";

    return (sqlite3_exec(db_instance, sql.c_str(), callback, 0, NULL) == 0);
}

bool DBManager::CreateAuthorsBooksTable() {
    std::string sql =
        "CREATE TABLE author_books("
        "AUTHOR_ID INTEGER,"
        "BOOK_ID INTEGER,"
        "PRIMARY KEY (AUTHOR_ID,BOOK_ID)"
        "   FOREIGN KEY (BOOK_ID)"
        "      REFERENCES Books (BOOK_ID)"
        "         ON DELETE CASCADE"
        "         ON UPDATE NO ACTION,"
        "   FOREIGN KEY (AUTHOR_ID)"
        "       REFERENCES Authors (AUTHOR_ID)"
        "          ON DELETE CASCADE"
        "          ON UPDATE NO ACTION);";

    return (sqlite3_exec(db_instance, sql.c_str(), callback, 0, NULL) == 0);
}

bool DBManager::InsertAuthor(std::string first_name, std::string last_name) {
    // BJC TODO: Sanitize inputs!!!!
    std::string sql = fmt::format(
        "INSERT INTO Authors (FIRST_NAME,LAST_NAME) "
        "VALUES ( '{0}','{1}' );",
        first_name, last_name);
    return (sqlite3_exec(db_instance, sql.c_str(), callback, 0, NULL) == 0);
}

bool DBManager::InsertBook(std::string title) {
    // BJC TODO: Sanitize inputs!!!!
    std::string sql = fmt::format("INSERT INTO Books (TITLE) VALUES({0});", title);

    return sqlite3_exec(db_instance, sql.c_str(), callback, 0, NULL);
}

bool DBManager::LinkAuthorBook(std::string first_name, std::string last_name, std::string book) {
    // BJC TODO: Associate Author with Book
    return true;
}
