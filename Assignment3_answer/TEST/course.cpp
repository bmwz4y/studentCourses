#include "course.h"

void course::set_teacher(string input_teacher)
{
	teacher=input_teacher;
}

void course::set_title(string input_title)
{
	title=input_title;
}

string course::get_title()
{
	return title;
}

string course::get_teacher()
{
	return teacher;
}

bool course::insert_student(student input_student)
{
	if(count<max_size)
	{
		students_list[count]=input_student;
		count++;
		if(count==max_size){return false;} 
		return true;
	}

	return false;
}

void course::print() //some decorations and all the info output using cout
{
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"				"<<title<<endl
		<<"Teacher: "<<teacher<<endl<<"Capacity of students: "<<max_size<<endl;
	cout<<"Number of enrolled students: "<<count<<endl<<"Enrolled students:"<<endl;
	for(int p=0; p<count; p++)
	{
		cout<<p+1<<") "<<students_list[p].get_name()<<"		"<<students_list[p].get_age()<<" years old"<<endl;
	}
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl<<endl<<endl;
}
	
course::course(string input_title,string input_teacher, int input_max_size)
{
	title=input_title;
	teacher=input_teacher;
	if(input_max_size<0)
	{
		max_size=10;
	}
	else
	{
		max_size=input_max_size;
	}

	count=0;
	students_list=new student[max_size];
}

course::course(course& old_course) //deep copy constructor
{
	title=old_course.title;
	teacher=old_course.teacher;
	max_size=old_course.max_size;
	count=old_course.count;
	students_list=new student[max_size];
	for(int p=0; p<count; p++)
	{
		students_list[p].set_name(old_course.students_list[p].get_name());
		students_list[p].set_age(old_course.students_list[p].get_age());
	}
}

course::~course()
{
	delete [] students_list; //to delete the dynamic array
}