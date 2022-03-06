#include <iostream>
#include "student.h"

using namespace std;

class Roster {
private:
    //Roster class variable declarations
	Student* classRosterArray[5];
	int numStudents = 5;
	int arrayIndex = 0;

public:
	//Roster class function declarations
	Roster();
	void parse(string Studentdata);
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll() const;
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeprogram);

	//Class destructor declaration
	~Roster();
};