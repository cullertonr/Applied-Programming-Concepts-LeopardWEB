#include "user.h"
#include <iostream>
#include <string>
#include "Myfunc.h"

using std::cout;
using std::endl;
// This is the base CPP Class for assignment 1

// constructor
user::user() {
	
}
user::user(string in_first_name, string in_last_name, string in_id) {
	first_name = in_first_name;
	last_name = in_last_name;
	id = in_id;
}

// set functions
void user::setFirst_Name(string in_first_name) {
	first_name = in_first_name;
}
void user::setLast_Name(string in_last_name) {
	last_name = in_last_name;
}
void user::setID(string in_id) {
	id = in_id;
}

// methods
string user::show_first_name() {
	return first_name;
}
string user::show_last_name() {
	return last_name;
}
string user::show_id() {
	return id;
}
void user::show_all() {
	cout << "First Name: " << first_name << endl;
	cout << "Last Name: " << last_name << endl;
	cout << "ID Number: " << id << endl;
}
void user::login(string email, string pass) {
	sqlite3* DB;
	cout << "Enter Email: ";
	cin >> email;
	cout << "Enter Password: "
	string email_query = "SELECT LOGIN.EMAIL WHERE LOGIN.EMAIL = ?;";
	sqlite3_exec(db, email_query.c_str(), callback, null, null);
	while (email_query != email){
		cout << "Incorrect Email Inserted. Please Try again." << endl;
		cout << "Enter Email: ";
		cin >> email;
		string email_query = "SELECT LOGIN.EMAIL WHERE LOGIN.EMAIL = ?;";
		sqlite3_exec(db, email_query.c_str(), callback, null, null);
	}
	sqlite3_close(DB);
}

// deconstructor
user::~user() {

}
