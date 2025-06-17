#include "user.h"
#include <iostream>
#include <string>

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
	cout << "first name: " << first_name << endl;
	cout << "last name: " << last_name << endl;
	cout << "id number: " << id << endl;
}

// deconstructor
user::~user() {

}
