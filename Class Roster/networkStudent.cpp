#include "student.h"
#include "networkStudent.h"
#include "degree.h"
#include <iostream>
using namespace std;

NetworkStudent::NetworkStudent() {
}

NetworkStudent::NetworkStudent(string ID, string first, string last, string email, int age, int* days, Degree deg) : Student(ID, first, last, email, age, days) {
	degree = deg;
}

Degree NetworkStudent::getDegree() {
	return degree;
}

void NetworkStudent::print() {
	cout << "\t" << "First Name: " << getFirstName() << "\t" << "Last Name: " << getLastName() << "\t" << "Age: " << getAge()
		<< "\t" << "daysInCourse: {"; cout << getNumDays()[0] << ", " << getNumDays()[1] << ", " << getNumDays()[2] << "}";
	cout << " Degree Program: Networking" << '\n';
}