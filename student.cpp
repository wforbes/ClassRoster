#include <iostream>
using namespace std;

#include "student.h"
#include "degree.h"

const string Student::EMPTYID = "--";

//Name: Constructor (no params)
//Desc: Initializes an empty Student object where only the
//	degreeProgram member is left uninitialized 
//	(degree.h handles stringifying uninitialized degrees as empty string)
Student::Student() {
	this->studentID = Student::EMPTYID;
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < NUMDAYS; i++) {
		this->completionDays[i] = 0;
	}
}

//D2d.  constructor using all of the input parameters provided in the table
Student::Student(string studentID, string firstName, string lastName, string email, int age, int* completionDays, const DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < NUMDAYS; i++) {
		this->completionDays[i] = completionDays[i];
	}
	this->degreeProgram = degreeProgram;
}

//D2a.  an accessor (i.e., getter) for each instance variable from part D1
string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmail() {
	return this->email;
}
int Student::getAge() {
	return this->age;
}
int* Student::getCompletionDays() {
	return this->completionDays;
}
//Name: getCompletionDaysString <print() helper>
//Desc: creates a string of Student's completionDays 
//	formatted to E3c requirement
string Student::getCompletionDaysString() {
	string daysString = "{ ";
	for (int i = 0; i < NUMDAYS; i++) {
		daysString += to_string(completionDays[i]);
		if (i != NUMDAYS - 1) {
			daysString += ", ";
		}
	}
	daysString += " }";
	return daysString;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

//D2b.  a mutator (i.e., setter) for each instance variable from part D1
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setCompletionDays(int* completionDays) {
	for (int i = 0; i < NUMDAYS; i++) {
		this->completionDays[i] = completionDays[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

//D2e.  print() to print specific student data
void Student::print() {
	cout << this->getStudentID() << " \t "
		<< "First Name: " << this->getFirstName() << " \t "
		<< "Last Name: " << this->getLastName() << " \t "
		<< "Age: " << this->getAge() << " \t"
		<< "daysInCourse: " << this->getCompletionDaysString() << " "
		<< "Degree Program: " << this->formatDegreeString(degreeToString(this->degreeProgram)) << " "
		<< endl;
}
//Name: formatDegreeString
//Desc: given a degree program name string like "SECURITY", 
//	formats string to "Security" with first char uppercase
//	and following chars to lower case 
string Student::formatDegreeString(string str) {
	str[0] = toupper(str[0]);
	for (int i = 1; i < str.size(); i++) {
		str[i] = tolower(str[i]);
	}
	return str;
}