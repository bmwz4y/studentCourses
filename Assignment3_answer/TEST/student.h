#ifndef student_header
#define student_header

#include <iostream>
#include <string>
using namespace std;

class student
{
	string name;
	int age;
public:
	void set_name(string input_string);
	void set_age(int input_int);//there isn't enough info about why in the question she used string type argument, so i used int.
	string get_name();
	int get_age();
	
	student(string input_name="", int input_age=0);
};
#endif