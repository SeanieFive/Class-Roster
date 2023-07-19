#pragma once
#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include "student.h"
using namespace std;

class SecurityStudent :	public Student {
public:
	SecurityStudent();

	SecurityStudent(string ID, string first, string last, string email, int age, int* days, Degree deg);

	Degree getDegree() override;

	void print() override;

private:
	Degree degree;
};

#endif //SECURITYSTUDENT_H