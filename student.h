#include <string>
using namespace std;

#include "degree.h"

#ifndef STUDENT_H
#define STUDENT_H

//Requirements D1 and D2
class Student {
public:
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int* completionDays, const DegreeProgram degreeProgram);
	void print();
	static const string EMPTYID;
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	static const int NUMDAYS = 3;
	int* getCompletionDays();
	DegreeProgram getDegreeProgram();
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setCompletionDays(int* completionDays);
	void setDegreeProgram(DegreeProgram degreeProgram);
	static string formatDegreeString(string str);
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int completionDays[NUMDAYS]{};
	DegreeProgram degreeProgram;
	string getCompletionDaysString();
};
#endif