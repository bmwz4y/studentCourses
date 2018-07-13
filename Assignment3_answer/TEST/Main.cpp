//Assignment #3
//Yahya Mubaideen	#20102171058
#include "course.h"

void course_students_list_editing_function(course &C); //this is the function prototype for a function i wrote to...read the function comments

void main()
{
	int input_max_size; //this is the integer to control the max size for students list of the course
	cout<<"Enter the maximum size of the Class"<<endl<<"(if you enter a negative number then i'll make it 10): "; //to inform the user what he should do next
	cin>>input_max_size; 
	cout<<endl;
	course C1("CS 101", "Ms. Malak", input_max_size);	//declare a course object C1
	course C2(C1);//declare a course object C2 by using copy constructor
	C1.set_title("CS 112");				//set the values of C1 by using set Functions

	C2.set_teacher("Dr. Emad");			//Make some changes to C2
	C2.set_title("Math 203");			//Make some changes to C2

	//start of (Let the user add as much students as he want to C1 or C2)
	int input_int_loop; //an integer to control the do wihile loop

	do
	{
		cout<<endl<<"Do you want to edit the first course or the second (enter 1 or 2)?"<<endl; //to inform the user what he should do next
		cout<<" 0 to see the info (any other number to exit the loop):"; //to inform the user what he should do next
		cin>>input_int_loop;
		cout<<endl;
		if(input_int_loop==1){course_students_list_editing_function(C1);} //selection statement for which class and calling the function
		if(input_int_loop==2){course_students_list_editing_function(C2);} //selection statement for which class and calling the function
		if(input_int_loop==0) //selection statement for showing the information for both titles
		{
			C1.print();							//print C1 and C2
			C2.print();							//print C1 and C2
		}
	}while(input_int_loop==1 || input_int_loop==2 || input_int_loop==0);
	//end of (Let the user add as much students as he want to C1 or C2)
}

void course_students_list_editing_function(course &C) //i wrote this function to make main function clearer
{	
	student input_student; //a student temporary variable to hold the input data inside
	int input_number_of_students; //to see how many students he wants to add
	string input_string; //a temporary variable to hold the name
	int input_int; //a temporary variable to hold the age

	cout<<"How many students do you want to add to Course "<<C.get_title()<<"? "; //just to inform
	cin>>input_number_of_students;
	cout<<endl;
	for(int p=1; p<(input_number_of_students+1); p++) //loop for entering the info for all students
	{
		cout<<"Enter the data for student #"<<p<<":"<<endl;//just to inform
		cout<<"Name: ";
		cin>>input_string;
		input_student.set_name(input_string); //sending the temporary string to the temporary student name member
		cout<<input_string<<"'s age: ";
		cin>>input_int;
		cout<<endl;
		input_student.set_age(input_int); //sending the temporary int to the temporary student age member
		if(C.insert_student(input_student)==false){cout<<"out of bound for student's list."<<endl; return;} //to exit the loop if there is no more capacity
	}	
}