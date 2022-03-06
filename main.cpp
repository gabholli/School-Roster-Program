#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {

	//Declaration of Roster object to use to call different functions below in main
	Roster classRoster;

	//Array of string data declared in main function
	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Gabe,Hollifield,gabholli@wgu.edu,39,25,30,35,SOFTWARE"
	};

	//Title output required
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 000167734" << endl;
	cout << "Name: Gabe Hollifield" << endl;
	cout << endl;

	cout << "Displaying all students:" << endl;

	//For loop used to iterate through parse function from Roster class
	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	//Function called to print initial roster of students
	classRoster.printAll();

	//Function called for printing emails with pertinent errors
	classRoster.printInvalidEmails();

	//Functions called to measure the average days in courses taken by the students in question b,y student ID number
	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");

	//Function to print students out by degree program
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	//Function used to remove the record attached to student ID "A3" from the class list
	classRoster.remove("A3");

	//Function used a second time to reattempt to print all students
	classRoster.printAll();

	//Function used to attempt a second time to remove "A3" record from class list
	classRoster.remove("A3");

	return 0;

}
