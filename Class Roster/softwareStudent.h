#pragma once
#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include "student.h"
using namespace std;

class SoftwareStudent :	public Student {
public:
	SoftwareStudent(); //default

	SoftwareStudent(string studID, string fiName, string laName, string emAddr, int a, int* nmDays, Degree deg);

	Degree getDegree() override;

	void print() override;

private:
	Degree degree;
};

#endif SOFTWARESTUDENT_H
