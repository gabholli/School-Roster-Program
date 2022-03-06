#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

//Empty constructor used for Roster class
Roster::Roster() {

}

//Roster class parsing function
void Roster::parse(string data) {
	size_t rhs = data.find(",");
	string studentID = data.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string firstName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string lastName = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string email = data.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int age = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse1 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse2 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	int daysInCourse3 = stoi(data.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = data.find(",", lhs);
	string degreeStr = data.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::SECURITY;

	if (degreeStr == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	if (degreeStr == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}
	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

//Roster class function for adding objects
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[arrayIndex] = new Student(studentID, firstName, lastName, email, age, daysArray, degreeProgram);
	arrayIndex++;
}

//Roster class function to remove objects when required
void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			classRosterArray[i] = classRosterArray[numStudents - 1];
			found = true;
			numStudents--;
		}
	}
	if (found) {
		cout << endl;
		cout << "Removing " << studentID << ":" << endl << endl;
	}
	else {
		cout << endl;
		cout << "Removing " << studentID << " again" << endl << endl;
		cout << "The student with the ID: " << studentID << " was not found." << endl;
		cout << "DONE." << endl;
	}
}

//Roster class function for printing output
void Roster::printAll() const {
	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i]->print();
	}
}

//Roster class function to retrieve average days in course for each student
void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			int days1 = classRosterArray[i]->getDaysToComplete(0);
			int days2 = classRosterArray[i]->getDaysToComplete(1);
			int days3 = classRosterArray[i]->getDaysToComplete(2);
			cout << "Student ID: " << studentID << ", average days in course is: " << (days1 + days2 + days3) / 3 << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Student was not found." << endl;
	}
}

//Roster class function for invalid emails
void Roster::printInvalidEmails() {
	cout << endl;
	cout << "Displaying invalid emails:" << endl;
	cout << endl;
	for (int i = 0; i < numStudents; i++) {
		string email = classRosterArray[i]->getEmail();
		if (email.find(" ") != string::npos || email.find("@") == string::npos || email.find(".") == string::npos) {
			cout << email << endl;
		}
	}
	cout << endl;
}

//Roster class functon for printing by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	cout << endl;
	cout << "Showing students in degree program: SOFTWARE" << endl << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}

//Roster class destructor function
Roster::~Roster() {
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
	}
}