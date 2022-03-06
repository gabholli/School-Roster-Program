#include <iostream>
#include "student.h"

using namespace std;

//Full constructor implementation
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysToComplete[3], DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) this->daysToComplete[i] = daysToComplete[i];
	this->degreeProgram = degreeProgram;
}

//Student print function implementation for Student class

void Student::print() {
	string degreeString;
	if (degreeProgram == DegreeProgram::SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	cout << studentID << "\t" << firstName << "\t" << lastName << "\t" << age << "\t" << "{" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}" << "\t" << degreeString << endl;
}

//Getter implementations for Student class

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return email;
}

int Student::getAge() {
	return age;
}

int Student::getDaysToComplete(int index) {
	return daysToComplete[index];
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

//Setter implementations for Student class

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToComplete(int daysToComplete[3]) {
	this->daysToComplete[3] = daysToComplete[3];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

//Deconstructor implementation for Student class
Student::~Student() {

}