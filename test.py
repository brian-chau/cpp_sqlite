import sqlite3

con = sqlite3.connect('library.db')
cursor = con.cursor()
cursor.execute( "CREATE TABLE Books ("
                "BOOK_ID  INTEGER  PRIMARY KEY  UNIQUE,"
                "TITLE    TEXT                  NOT NULL);");

cursor.execute( "CREATE TABLE Authors ("
                "AUTHOR_ID   INTEGER  PRIMARY KEY  UNIQUE,"
                "FIRST_NAME  TEXT                  NOT NULL,"
                "LAST_NAME   TEXT                  NOT NULL);");
cursor.execute("INSERT INTO Authors (FIRST_NAME,LAST_NAME) VALUES ( 'Brian','Chau' );");
cursor.execute("SELECT * FROM Authors;");
print(cursor.fetchall())
