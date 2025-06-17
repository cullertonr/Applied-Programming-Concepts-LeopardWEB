#pragma once
#include "user.h"
class admin:
    public user
{


public:

    // constructor
    admin();
    admin(string in_first_name, string in_last_name, string in_id);

    // methods
    virtual string show_first_name();	// returns first name
    virtual string show_last_name();	// returns last name
    virtual string show_id();			// returns id number
    virtual void show_all();			// prints all attributes
    void add_courses();
    void remove_courses();
    void add_users();
    void remove_users();
    void remove_student_course();
    void add_student_course();
    void search_print_roster();

    // destructor
    ~admin();
};

