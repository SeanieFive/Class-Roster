#include "securityStudent.h"
#include <iostream>

SecurityStudent::SecurityStudent() {
}

SecurityStudent::SecurityStudent(string ID, string first, string last, string email, int age, int* days, Degree deg) : Student(ID, first, last, email, age, days) {
	degree = deg;
}

Degree SecurityStudent::getDegree() {
	return degree;
}

void SecurityStudent::print() {
	cout << "\t" << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge()
		<< "\t" << "daysInCourse: {"; cout << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "}";
	cout << " Degree Program: Security" << '\n';
}