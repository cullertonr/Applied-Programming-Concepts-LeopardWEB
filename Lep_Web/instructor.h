#pragma once
#include "user.h"
class instructor :
    public user
{

public:

    // constructor
    instructor();
    instructor(string in_first_name, string in_last_name, string in_id);

    // methods
    virtual string show_first_name();	// returns first name
    virtual string show_last_name();	// returns last name
    virtual string show_id();			// returns id number
    virtual void show_all();			// prints all attributes
    void print_schedule();
    void print_class_list();
    void search_courses();

    // destructor
    ~instructor();
};

