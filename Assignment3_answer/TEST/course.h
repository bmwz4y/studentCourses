#ifndef course_header
#define course_header

#include "student.h"

class course
{
	string title;
	string teacher;
	int max_size;
	int count;
	student *students_list;
public:
	void set_teacher(string input_teacher);
	void set_title(string input_title);
	string get_title();
	string get_teacher();
	bool insert_student(student input_student);
	void print();
	
	course(string input_title, string input_teacher, int input_max_size=10);
	course(course& old_course);
	~course();
};
#endif