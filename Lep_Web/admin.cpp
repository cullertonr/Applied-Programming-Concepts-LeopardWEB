#include "admin.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

admin::admin() {

}
admin::admin(string in_first_name, string in_last_name, string in_id) : user(in_first_name, in_last_name, in_id) {
	first_name = in_first_name;
	last_name = in_last_name;
	id = in_id;
}

string admin::show_first_name() {
	return first_name;
}
string admin::show_last_name() {
	return last_name;
}
string admin::show_id() {
	return id;
}
void admin::show_all() {
	cout << "Admin's first name: " << first_name << endl;
	cout << "Admin's last name: " << last_name << endl;
	cout << "Admin's id is: " << id << endl;
}
void admin::add_courses() {
	cout << "Adding Courses:" << endl;
}
void admin::remove_courses() {
	cout << "Remove Courses:" << endl;
}
void admin::add_users() {
	cout << "Adding users:" << endl;
}
void admin::remove_users() {
	cout << "Removing user:" << endl;
}
void admin::remove_student_course() {
	cout << "Removing Student Course:" << endl;
}
void admin::add_student_course() {
	cout << "Adding Student Course:" << endl;
}
void admin::search_print_roster() {
	cout << "Searching for Roster:" << endl;
	cout << "Printing Roser:" << endl;
}
admin::~admin() {

}
