#include "student.h"
#include <iostream>
#include <string>

using std::cout;
using std::string;
using std::endl;


student::student() {

}
student::student(string in_first_name, string in_last_name, string in_id) : user(in_first_name,  in_last_name, in_id) {
	first_name = in_first_name;
	last_name = in_last_name;
	id = in_id;
}

string student::show_first_name() {
	return first_name;
}
string student::show_last_name() {
	return last_name;
}
string student::show_id() {
	return id;
}
void student::show_all() {
	cout << "Student's first name is: " << first_name << endl;
	cout << "Student's last name is: " << last_name << endl;
	cout << "Student's id is: " << id << endl;
}
void student::print_schedule() {
	cout << "Printing " << first_name << " " << last_name << "'s schedule." << endl;
}
void student::search_course() {
	cout << "Searching for Courses: " << endl;
}
void student::add_course() {
	cout << "Add Course:" << endl;
}
void student::drop_course() {
	cout << "Drop Course:" << endl;
}
student::~student() {

}
