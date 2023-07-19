#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student() {
}

Student::Student(string ID, string first, string last, string email, int age, int* days) {
	studentID    = ID;
	firstName    = first;
	lastName     = last;
	emailAddress = email;
	studentAge   = age;
	numDays[0]   = days[0];
	numDays[1]   = days[1];
	numDays[2]   = days[2];
}

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return studentAge;
}

int* Student::getNumDays() {
	return numDays;
}

Degree Student::getDegree() {
	return Degree::SOFTWARE;
}

void Student::setStudentID(string ID) {
	studentID = ID;
}

void Student::setFirstName(string first) {
	firstName = first;
}

void Student::setLastName(string last) {
	lastName = last;
}

void Student::setEmailAddress(string email) {
	emailAddress = email;
}

void Student::setAge(int age) {
	studentAge = age;
}

void Student::setNumDays(int days0, int days1, int days2) {
	Student::numDays[0] = days0;
	Student::numDays[1] = days1;
	Student::numDays[2] = days2;
}

void Student::setDegree(string degree)
{
	degree = degree;
}

void Student::print() {
}

//default deconstructor
Student::~Student() {
}

