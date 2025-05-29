#include <iostream>
#include "sqlite3.h"
#include <string>
#include <stdio.h>

using namespace std;

static int callback(void* data, int argc, char** argv, char** azColName)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}

	printf("\n");

	return 0;
}


int main(int argc, char** argv)
{
	sqlite3* DB;

	string table = "CREATE TABLE COURSE("
		"CRN INTEGER PRIMARY KEY, "
		"TITLE TEXT NOT NULL, "
		"DEPARTMENT TEXT NOT NULL, "
		"TIME TEXT NOT NULL, "
		"DAYSOFTHEWEEK TEXT NOT NULL, "
		"SEMESTER TEXT NOT NULL,"
		"YEAR INTEGER NOT NULL, "
		"CREDITS INTEGER NOT NULL); ";

	int exit = 0;

	exit = sqlite3_open("assignment3.db", &DB);			//open the database

	char* messageError;

	exit = sqlite3_exec(DB, table.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		std::cerr << "Error Create Table" << std::endl;
		sqlite3_free(messageError);
	}
	else
		cout << "Table created Successfully" << std::endl;


	/*******************************************************************
	 Inserting values into a table.
	 Create a string then pass the string into the sqlite3_exec function
	********************************************************************/
	// hard-code (push) a few values into the database - NOTE you can create a single string with multiple INSERT commands
	/*string sql("INSERT INTO COURSE VALUES(30292, 'CALCULUS', 'MATH', '12:00-2:00', 'MWF', 'SPRING', 2025, 4);"
		"INSERT INTO COURSE VALUES(31001, 'THERMODYNAMICS', 'BSME', '8:00-9:50', 'TRF', 'FALL', 2025, 4);"
		"INSERT INTO COURSE VALUES(25002, 'COMPUTER SCIENCE 1', 'BCOS', '9:30-10:45', 'MW', 'FALL', 2025, 4);"
		"INSERT INTO COURSE VALUES(32001, 'ADVANCED DIGITAL CIRCUIT DESIGN', 'BSCO', '12:30-1:45', 'MW', 'SUMMER', 2026, 4);"
		"INSERT INTO COURSE VALUES(25001, 'NETWORK THEORY 1', 'BSEE', '3:00-4:15', 'TR', 'SPRING', 2026, 3);"
		"INSERT INTO COURSE VALUES(18001, 'ORGANIC CHEMISTRY 2', 'BSAS', '10:00-11:15', 'MWF', 'FALL', 2025, 4);"
	);*/

	string sql(
		"INSERT INTO STUDENT VALUES(10012, 'John', 'Jones', 3099, 'BSCO', 'jonesj1');"
	);

	// execute the command
	exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		std::cerr << "Error Insert" << std::endl;
		sqlite3_free(messageError);
	}
	else
		std::cout << "Records created Successfully!" << std::endl;



	/***********************************************
	 print all data in the table with SELECT * FROM
	 create string with query then execute
	 **********************************************/
	string query = "SELECT * FROM COURSE;";

	cout << endl << query << endl;		//print the string to screen

	// you need the callback function this time since there could be multiple rows in the table
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

	// other possible commands from SQL (update, delete, etc.), try those. Same concept, create string then call command
	//string delete_sql = "DELETE FROM COURSES WHERE DEPARTMENT = 'MATH';";

	//exit = sqlite3_exec(DB, delete_sql.c_str(), NULL, 0, &messageError);

	//if (exit != SQLITE_OK)
	//{
	//	std::cerr << "Error Delete" << std::endl;
	//	sqlite3_free(messageError);
	//}
	//else
	//	std::cout << "Record deleted Successfully!" << std::endl;

	/*string drop_table = "DROP TABLE IF EXISTS COURSE;";
	exit = sqlite3_exec(DB, drop_table.c_str(), NULL, 0, &messageError);

	if (exit != SQLITE_OK)
	{
		std::cerr << "Error dropping table: " << messageError << std::endl;
		sqlite3_free(messageError);
	}
	else
		std::cout << "COURSES table dropped successfully!" << std::endl;*/

	sqlite3_close(DB);
	return 0;
}