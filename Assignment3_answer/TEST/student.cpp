#include "student.h"

void student::set_name(string input_string)
{
	name=input_string;
}

void student::set_age(int input_int)
{
	age=input_int;
}

string student::get_name()
{
	return name;
}

int student::get_age()
{
	return age;
}

student::student(string input_name, int input_age)
{
	name=input_name;
	age=input_age;
}