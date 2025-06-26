#include <iostream>
#include "sqlite3.h"
#include <string>
#include <stdio.h>

using namespace std;

//int main(){
//
//	cout << "Welcome to LeopardWeb!" << endl;
//	cout << "---------- Login ---------- " << endl;
//	string pass, email, role;
//	cout << "Email: ";
//	cin >> email;
//	// Place login function here from user class
//	cout << "Password: ";
//	cin >> pass;
//	cout << "Hello " << role << endl;
//
//
//	return 0;
//}

static int callback(void* data, int argc, char** argv, char** azcolname)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s = %s\n", azcolname[i], argv[i] ? argv[i] : "null");
	}

	printf("\n");

	return 0;
}


int main(int argc, char** argv)
{
	sqlite3* db;

	string table = "CREATE TABLE LOGIN("
		"EMAIL TEXT PRIMARY KEY, "
		"ROLE TEXT NOT NULL, "
		"PASSWORD TEXT NOT NULL); ";

	int exit = 0;

	exit = sqlite3_open("assignment3.db", &db);			//open the database

	char* messageerror;

	exit = sqlite3_exec(db, table.c_str(), NULL, 0, &messageerror);

	if (exit != SQLITE_OK)
	{
		std::cerr << "error create table" << std::endl;
		sqlite3_free(messageerror);
	}
	else
		cout << "table created successfully" << std::endl;


	/*******************************************************************
	 inserting values into a table.
	 create a string then pass the string into the sqlite3_exec function
	********************************************************************/
	// hard-code (push) a few values into the database - note you can create a single string with multiple insert commands
	string sql("INSERT INTO LOGIN VALUES('newtoni', 'Student', 'Qr4L#8Bk');"
		"INSERT INTO LOGIN VALUES('curiem', 'Student', 'Uz7V^5Mw');"
		"INSERT INTO LOGIN VALUES('telsan', 'Student', 'Km1T!9Xs');"
		"INSERT INTO LOGIN VALUES('notcool', 'Student', 'Nj5R@3Pc');"
		"INSERT INTO LOGIN VALUES('vonneumannj', 'Student', 'Px8L$6Vb');"
		"INSERT INTO LOGIN VALUES('hopperg', 'Student', 'Ys4W#2Kq');"
		"INSERT INTO LOGIN VALUES('jemisonm', 'Student', 'Gm7N^9Xv');"
		"INSERT INTO LOGIN VALUES('deanm', 'Student', 'Hr1P!5Lb');"
		"INSERT INTO LOGIN VALUES('faradaym', 'Student', 'Bq9T@3Nz');"
		"INSERT INTO LOGIN VALUES('lovelacea', 'Student', 'Lz6V$4Mk');"
		"INSERT INTO LOGIN VALUES('jonesj1', 'Student', 'Fn3Y#8Ps');"
		"INSERT INTO LOGIN VALUES('fostera', 'Student', 'Hp5R^2Xb');"
		"INSERT INTO LOGIN VALUES('turnere', 'Student', 'Tx9L!7Wq');"
		"INSERT INTO LOGIN VALUES('johnsonm1', 'Student', 'Sm2K@4Nz');"
		"INSERT INTO LOGIN VALUES('bennetts', 'Student', 'Yp8V$5Lb');"
		"INSERT INTO LOGIN VALUES('collinsd', 'Student', 'Jq4T#9Mc');"
		"INSERT INTO LOGIN VALUES('davisl3', 'Student', 'Wm7N^3Xv');"
		"INSERT INTO LOGIN VALUES('mitchellb', 'Student', 'Fp1R!6Lb');"
		"INSERT INTO LOGIN VALUES('harriso', 'Student', 'Gq9L@2Nz');"
		"INSERT INTO LOGIN VALUES('smiths5', 'Student', 'Km5Y$8Wc');"
		"INSERT INTO LOGIN VALUES('hamiltonm', 'Admin', 'Nr3T#7Xb');"
		"INSERT INTO LOGIN VALUES('rubinv', 'Admin', 'Uz6V^4Mp');"
		"INSERT INTO LOGIN VALUES('whited3', 'Admin', 'Tp8P!9Ls');"
		"INSERT INTO LOGIN VALUES('brooksm', 'Instructor', 'qW9t@3zL');"
		"INSERT INTO LOGIN VALUES('fourierj', 'Instructor', 'bK2n!7Pm');"
		"INSERT INTO LOGIN VALUES('galileig', 'Instructor', 'xT8v$5Qr');"
		"INSERT INTO LOGIN VALUES('turinga', 'Instructor', 'Lm4Y@9cX');"
		"INSERT INTO LOGIN VALUES('bernoullid', 'Instructor', 'Tz7b^2Nk');"
		"INSERT INTO LOGIN VALUES('reynoldsd', 'Instructor', 'Hq1Z@4Ls');"
		"INSERT INTO LOGIN VALUES('morganp', 'Instructor', 'Jp9f!3Kr');"
		"INSERT INTO LOGIN VALUES('phillipss', 'Instructor', 'Zm8R$5Bd');"
		"INSERT INTO LOGIN VALUES('walkerj', 'Instructor', 'Yl5W@7Xs');"
		"INSERT INTO LOGIN VALUES('hayest', 'Instructor', 'Dx3P#2Mv');"
		"INSERT INTO LOGIN VALUES('sandersk', 'Instructor', 'Cn6V^9Lk');"
		"INSERT INTO LOGIN VALUES('fosterr', 'Instructor', 'Fq7T!5Xb');"
		"INSERT INTO LOGIN VALUES('rossa1', 'Instructor', 'Sm2K@4Nz');"
		"INSERT INTO LOGIN VALUES('petersonc', 'Instructor', 'Wp9Y$3Lc');"
		"INSERT INTO LOGIN VALUES('boumank', 'Instructor', 'Vp3r#6Wq');"
	);

	////string sql("INSERT INTO COURSE VALUES(30003, 'Dana', 'White', 'Registrar', 'Ira Allen 208', 'whited3');"
	////);

	// execute the command
	exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messageerror);

	if (exit != SQLITE_OK)
	{
		std::cerr << "error insert" << std::endl;
		sqlite3_free(messageerror);
	}
	else
		std::cout << "records created successfully!" << std::endl;



	/***********************************************
	 print all data in the table with select * from
	 create string with query then execute
	 **********************************************/

	//string query = "select instructor.name, instructor.dept, course.title from instructor, course where instructor.dept = course.department;";

	//cout << endl << query << endl << "lllllll" << endl;		//print the string to screen

	//// you need the callback function this time since there could be multiple rows in the table
	//sqlite3_exec(db, query.c_str(), callback, NULL, NULL);

	// command to delete the instructor of choice, in this case the huss instructor is getting removed because they do not align with the courses that were created
	//string delete_sql = "DELETE FROM LOGIN WHERE ROLE = 'Instructor';";

	//exit = sqlite3_exec(db, delete_sql.c_str(), NULL, 0, &messageerror);

	//if (exit != SQLITE_OK)
	//{
	//	std::cerr << "error delete" << std::endl;
	//	sqlite3_free(messageerror);
	//}
	//else
	//	std::cout << "record deleted successfully!" << std::endl;

	//string drop_table = "DROP TABLE IF EXISTS login;";
	//exit = sqlite3_exec(db, drop_table.c_str(), NULL, 0, &messageerror);

	//if (exit != SQLITE_OK)
	//{
	//	std::cerr << "error dropping table: " << messageerror << std::endl;
	//	sqlite3_free(messageerror);
	//}
	//else
	//	std::cout << "login table dropped successfully!" << std::endl;

		// update the admin in the database changing vera rubens title to vice-pres from registrar
	//string update = "update admin set title = 'vice-president' where name = 'vera';";

	//exit = sqlite3_exec(db, update.c_str(), NULL, 0, &messageerror);

	//if (exit != SQLITE_OK)
	//{
	//	std::cerr << "error updating admin" << std::endl;
	//	sqlite3_free(messageerror);
	//}
	//else
	//	std::cout << "admin updated successfully" << std::endl;

	sqlite3_close(db);
	return 0;
}