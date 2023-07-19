#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>
using namespace std;

class Student {
public:
	//constructors
	Student();

	Student(string ID, string first, string last, string email, int age, int* numDays);

	//ACCESSOR FOR EACH INSTANCE VARIABLE
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int    getAge();
	int*   getNumDays();

	//MUTATOR FOR EACH INSTANCE VARIABLE
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int studentAge);
	void setNumDays(int days0, int days1, int days2);
	void setDegree(string degree);

	virtual void print();
	virtual Degree getDegree();

	//destructor
	~Student();
	   	 
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int    studentAge;
	int    numDays[3];
};

#endif //STUDENT_H
