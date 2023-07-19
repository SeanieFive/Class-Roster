#pragma once
#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include "student.h"
#include "degree.h"
using namespace std;

class NetworkStudent : public Student {
public:
	NetworkStudent();

	NetworkStudent(string ID, string first, string last, string email, int age, int* days, Degree);

	Degree getDegree() override;

	void print() override;

private:
	Degree degree;
};

#endif NETWORKSTUDENT_H
