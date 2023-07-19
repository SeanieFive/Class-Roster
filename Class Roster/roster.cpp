#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include "student.h"
#include "degree.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "roster.h"
using namespace std;

int main() {
	//F1 - Print my information
	cout << "Course: Scripting and Programming - Applications C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID#: 001041212" << endl;
	cout << "Student Name: Sean Kenney" << endl;
	cout << endl;

	//F2 - Create Instance of the Roster class called classRoster
	Roster classRoster;
	Degree degree;

	//F3 - Add each student to classRoster
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Sean,Kenney,skenn82@wgu.edu,20,30,35,40,SOFTWARE"
	};

	int i = 0;
	for (i = 0; i < 5; i++) {
		stringstream data(studentData[i]);
		vector<string> output;
		while (data.good()) {
			string substr;
			getline(data, substr, ',');
			output.push_back(substr);
		}
		if (output[8] == "SECURITY") {
			degree = Degree::SECURITY;
		}
		if (output[8] == "SOFTWARE") {
			degree = Degree::SOFTWARE;
		}
		if (output[8] == "NETWORK") {
			degree = Degree::NETWORKING;
		}
		classRoster.add(output[0], output[1], output[2], output[3], stoi(output[4]), stoi(output[5]), stoi(output[6]), stoi(output[7]), degree);
	}

	//F4 - Covert to pseudo code
	classRoster.printAll();
	classRoster.PrintInvalidEmails();
	classRoster.printDaysInCourse("A1");
	classRoster.printByDegreeProgram("SOFTWARE");
	classRoster.remove("A3");
	classRoster.remove("A3");
}

//F5 - Destructor to release Roster memory
Roster::~Roster() {
	cout << "Roster memory released" << endl;
}

Roster::Roster() {
}

//E3.a - sets the instance variables from part D1 and updates the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {

	int numDaysInCourse[] = { daysInCourse1, daysInCourse2, daysInCourse3};
	if(degree == Degree::NETWORKING) {

		classRosterArray[addIndex++] = new NetworkStudent(studentID, firstName, lastName, emailAddress, age, numDaysInCourse, degree);
	}
	if (degree == Degree::SECURITY) {
		classRosterArray[addIndex++] = new SecurityStudent(studentID, firstName, lastName, emailAddress, age, numDaysInCourse, degree);
	}
	if (degree == Degree::SOFTWARE) {
		classRosterArray[addIndex++] = new SoftwareStudent(studentID, firstName, lastName, emailAddress, age, numDaysInCourse, degree);
	}
}

//E3.b - removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
void Roster::remove(string studentID) {
	bool studentRemoved = false;
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (classRosterArray[i] != NULL) {
			if (studentID == classRosterArray[i]->getStudentID()) {
				classRosterArray[i] = nullptr;
				studentRemoved = true;
				cout << "Student ID: " << studentID << " has been removed.";
			}
		}
	}
	if (!studentRemoved) {
		cout << "Student ID: " << studentID << " was not found." << endl;
	}
	cout << endl;
}

//E3.c - prints a complete tab-separated list of student data using accessor functions with the provided format
void Roster :: printAll() {
	int i = 0;
	cout << "Roster:" << endl;
	cout << endl;
	for (i = 0; i < 5; i++) {
		(*classRosterArray[i]).print();
		}
	cout << endl;
}

//E3.d - prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
void Roster :: printDaysInCourse(string studentID) {
	int i = 0;
	cout << "Average days in courses:" << endl;
	cout << endl;
	for (i = 0; i < 5; i++) {
		if ((*classRosterArray[i]).getStudentID() == studentID) {
			int average = 0;
			average = ((*classRosterArray[i]).getNumDays()[0] + (*classRosterArray[i]).getNumDays()[1]
				+ (*classRosterArray[i]).getNumDays()[2]) / 3;
			cout << "\t" << "Student ID: " << studentID << " has an average of " << average << " days." << endl;
		}
	}
	cout << endl;
}

//E3.e - verifies student email addresses and displays all invalid email addresses to the user
void Roster::PrintInvalidEmails() {
	int i = 0;
	cout << "Invalid Email Address(es):" << endl;
	cout << endl;
	for (i = 0; i < 5; i++) {
		bool atSign = false;
		bool period = false;
		bool space = false;
		string emailAddress = "";
		emailAddress = (*classRosterArray[i]).getEmailAddress();
		for (char& character : emailAddress) {
			if (character == '@') {
				atSign = true;
			}
			if (character == '.') {
				period = true;
			}
			if (character == ' ') {
				space = true;
			}
		}
		if (atSign == false || period == false || space == true) {
			cout << "\t" << "Student ID: " << (*classRosterArray[i]).getStudentID() << "\t" << (*classRosterArray[i]).getEmailAddress() << endl;
		}
	}
	cout << endl;
}

//E3.f - prints out student information for a degree program specified by an enumerated type
void Roster :: printByDegreeProgram(string degree) {
	Degree degreeCheck = Degree::SOFTWARE;
	if (degree == "SECURITY") {
		degreeCheck = Degree::SECURITY;
		cout << "Students in Security degree: " << endl;
	}
	if (degree == "NETWORKING") {
		degreeCheck = Degree::NETWORKING;
		cout << "Students in Networking degree: " << endl;
	}
	if (degree == "SOFTWARE") {
		degreeCheck = Degree::SOFTWARE;
		cout << "Students in Software degree: " << endl;
	}
	cout << endl;
	int i = 0;
	for (i = 0; i < 5; i++) {
		if (degreeCheck == (*classRosterArray[i]).getDegree()) {
			(*classRosterArray[i]).print();
		}
	}
	cout << endl;
}