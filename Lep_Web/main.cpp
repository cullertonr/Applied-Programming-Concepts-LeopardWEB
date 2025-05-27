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

	string table = "CREATE TABLE COURSES("
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
	string sql("INSERT INTO COURSES VALUES(30292, 'CALCULUS', 'MATH', '12:00-2:00', 'MWF', 'SPRING', 2025, 4);"
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
	string query = "SELECT * FROM COURSES;";

	cout << endl << query << endl;		//print the string to screen

	// you need the callback function this time since there could be multiple rows in the table
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

	// other possible commands from SQL (update, delete, etc.), try those. Same concept, create string then call command


	// end me
	cout << "Hello";
	

	sqlite3_close(DB);
	return 0;
}