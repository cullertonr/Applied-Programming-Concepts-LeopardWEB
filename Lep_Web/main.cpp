#include <iostream> 
#include "sqlite3.h" 
#include <string> 
#include <stdio.h>

using namespace std;

// Call back function (can be modified)
static int callback(void* data, int argc, char** argv, char** azColName)
{
    int i;

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");

    return 0;
}

int main(int argc, char** argv) {

    sqlite3* DB;

    string table = "CREATE TABLE COURSE("
        "CRN INTEGER PRIMARY KEY, "
        "TITLE TEXT NOT NULL, "
        "DEPARTMENT TEXT NOT NULL, "
        "TIME TEXT NOT NULL);"
        "DAYSOFTHEWEEK TEXT NOT NULL"
        "SEMESTER TEXT NOT NULL"
        "YEAR INTEGER NOT NULL"
        "CREDITS INTEGER NOT NULL";

    int exit = 0;

    exit = sqlite3_open("assignment3.db", &DB);

    char* messageError;

    exit = sqlite3_exec(DB, table.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Create Table" << std::endl;
        sqlite3_free(messageError);
    }
    else
        cout << "Table created Successfully" << std::endl;


    // hard-code (push) a few values into the database - NOTE you can create a single string with multiple INSERT commands
    string insert("INSERT INTO COURSE VALUES(3100, 'THERMODYNAMICS', 'BSME', '8:00-9:50', 'T,TH,F', 'FALL', 2025, 4);"
        "INSERT INTO COURSE VALUES(2500, 'COMPUTER SCIENCE 1', 'BCOS', '9:30-10:45', 'M,W', 'FALL', 2025, 4);"
        "INSERT INTO COURSE VALUES(3200, 'ADVANCED DIGITAL CIRCUIT DESIGN', 'BSCO', '12:30-1:45', 'M,W', 'SUMMER', 2026, 4);"
        "INSERT INTO COURSE VALUES(2500, 'NETWORK THEORY 1', 'BSEE', '3:00-4:15', 'T,TH', 'SPRING', 2026, 3);"
        "INSERT INTO COURSE VALUES(1800, 'ORGANIC CHEMISTRY 2', 'BSAS', '10:00-11:15', 'M,W,F', 'FALL', 2025, 4);"
        "INSERT INTO STUDENT VALUES('James', 'Martin', 3, 'BSCO', 'martinj');"
        "INSERT INTO STUDENT VALUES('Amanda', 'Dulac', 4, 'BSAS', 'dulaca');"
    );

    // Inserting values to the database
    exit = sqlite3_exec(DB, insert.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Inserting Values" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Inserted Successfully" << std::endl;



    // removing the instructor from the datbase

    string remove = "DELETE FROM INSTRUCTOR WHERE DEPT = 'HUSS';";

    exit = sqlite3_exec(DB, remove.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Removing Instructor" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Records Inserted Successfully!" << std::endl;



    // update the admin in the database
    string update = "UPDATE ADMIN SET TITLE = 'Vice-President' WHERE NAME = 'Vera' and SURNAME = 'Ruben';";

    exit = sqlite3_exec(DB, update.c_str(), NULL, 0, &messageError);

    if (exit != SQLITE_OK)
    {
        std::cerr << "Error Updating Admin" << std::endl;
        sqlite3_free(messageError);
    }
    else
        std::cout << "Admin Updated Successfully" << std::endl;


    // Start of the query's for each

    sqlite3_close(DB);
    return 0;
}