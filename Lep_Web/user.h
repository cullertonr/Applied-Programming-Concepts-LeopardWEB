#pragma once
#include <string>
using std::string;

class user
{
protected:
	// attributes
	string first_name;
	string last_name;
	string id;

public:

	// constructor
	user();
	user(string in_first_name, string in_last_name, string in_id);

	// method
	virtual string show_first_name();	// returns first name
	virtual string show_last_name();	// returns last name
	virtual string show_id();			// returns id number
	virtual void show_all();			// prints all attributes

	// destructor
	~user();
};

