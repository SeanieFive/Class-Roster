#include "softwareStudent.h"
#include <iostream>

SoftwareStudent::SoftwareStudent() {
}

SoftwareStudent::SoftwareStudent(string ID, string first, string last, string email, int age, int* days, Degree deg) : Student(ID, first, last, email, age, days) {
	degree = deg;
}

Degree SoftwareStudent::getDegree() {
	return degree;
}
 
void SoftwareStudent::print() {
	cout << "\t" << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge() << "\t" << "daysInCourse: {"; cout << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "}";
	cout << " Degree Program: Software" << endl;
}