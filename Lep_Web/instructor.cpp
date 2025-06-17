#include "instructor.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

instructor::instructor() {

}
instructor::instructor(string in_first_name, string in_last_name, string in_id) : user(in_first_name, in_last_name, in_id) {
	first_name = in_first_name;
	last_name = in_last_name;
	id = in_id;
}

string instructor::show_first_name() {
	return first_name;
}
string instructor::show_last_name() {
	return last_name;
}
string instructor::show_id() {
	return id;
}
void instructor::show_all() {
	cout << "Instructor's first name is: " << first_name << endl;
	cout << "Instructor's last name is: " << last_name << endl;
	cout << "Instructor's id is: " << id << endl;
}
void instructor::print_schedule() {
	cout << "Printing " << first_name << " " << last_name << "'s schedule:" << endl;
}
void instructor::print_class_list() {
	cout << "Priting the class list:" << endl;
}
void instructor::search_courses() {
	cout << "Searching for courses:" << endl;
}
instructor::~instructor() {

}