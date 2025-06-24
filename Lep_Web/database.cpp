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
	int exit = 0;
	char* messageError;
	//string table = "CREATE TABLE LOGIN("
	//	"EMAIL TEXT PRIMARY KEY, "
	//	"ROLE TEXT NOT NULL, "
	//	"PASSWORD TEXT NOT NULL); ";

	

	exit = sqlite3_open("assignment3.db", &DB);			//open the database

	

	//exit = sqlite3_exec(DB, table.c_str(), NULL, 0, &messageError);

	//if (exit != SQLITE_OK)
	//{
	//	std::cerr << "Error Create Table" << std::endl;
	//	sqlite3_free(messageError);
	//}
	//else
	//	cout << "Table created Successfully" << std::endl;


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

	/*string sql(
		
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
	*/


	/***********************************************
	 print all data in the table with SELECT * FROM
	 create string with query then execute
	 **********************************************/
	
	string email, pass;
	cout << "Enter email: ";
	cin >> email;
	cout << "Enter password: ";
	cin >> pass;

	string str_1 = "SELECT ROLE FROM LOGIN WHERE EMAIL = '";
	string str_2 = "' AND PASSWORD = '";
	string query = str_1 + email + str_2 + pass + "'" + ";";
	

	//cout << query;

	//string query = "SELECT ROLE FROM LOGIN WHERE EMAIL = 'whited' AND PASSWORD = 'Yes123';";

	cout << endl << query << endl;		//print the string to screen

	// you need the callback function this time since there could be multiple rows in the table
	sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

	//// command to delete the instructor of choice, in this case the HUSS instructor is getting removed because they do not align with the courses that were created
	//string delete_sql = "DELETE FROM INSTRUCTOR WHERE DEPARTMENT = 'HUSS';";

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

		// update the admin in the database changing vera rubens title to vice-pres from registrar
	//string update = "UPDATE ADMIN SET TITLE = 'Vice-President' WHERE NAME = 'Vera';";

	//exit = sqlite3_exec(DB, update.c_str(), NULL, 0, &messageError);

	//if (exit != SQLITE_OK)
	//{
	//	std::cerr << "Error Updating Admin" << std::endl;
	//	sqlite3_free(messageError);
	//}
	//else
	//	std::cout << "Admin Updated Successfully" << std::endl;

	sqlite3_close(DB);
	return 0;
}