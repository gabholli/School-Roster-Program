#include <iostream>
#include "degree.h"

using namespace std;

class Student {
private:
    //Student class variables declarations
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;

public:
	//Full constructor declaration
	Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[3], DegreeProgram degreeProgram);

	//Getter declarations
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int getDaysToComplete(int index);
	DegreeProgram getDegreeProgram();

	//Setter declarations
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int daysToComplete[3]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	//Print function declaration
	void print();

	//Deconstructor declaration
	~Student();
};