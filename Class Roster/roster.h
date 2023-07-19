#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include "student.h"
#include <array>
using namespace std;

class Roster {
public:
	Roster();
	virtual ~Roster();
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
	void remove(string studentID);
	void printAll();
	void printDaysInCourse(string);
	void PrintInvalidEmails();
	void printByDegreeProgram(string degree);
	int addIndex = 0;
private:
	Student* classRosterArray[5];
};

#endif ROSTER_H
