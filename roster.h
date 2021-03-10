#include <string>
using namespace std;

#include "student.h"

#ifndef ROSTER_H
#define ROSTER_H

class Roster {
public:
	Roster();
	Roster(int numStudents);
	~Roster();
	Student& operator[](int index);
	Student* classRosterArray;
	void addStudentData(const string* studentData, int arrSize);
	void parseStudentStr(string studentStr, string* strArr, char delim = strDelim);
	bool validateStudentStr(string studentStr);
	int countStringDelimiters(string str, char delim = strDelim);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void printByDegreeProgram(DegreeProgram degreeprogram);
	int getNumStudents();
	static const int reqNumFields = 9;
private:
	int numStudents;
	int nextIndex;
	static const char strDelim = ',';
};
#endif