#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#include "roster.h"
#include "student.h"
#include "degree.h"

//E1.  Create an array of pointers, classRosterArray, to hold the data provided in the �studentData Table.�
Roster::Roster() {
	this->classRosterArray = new Student[5];
	this->numStudents = 5;
	this->nextIndex = 0;
	for (int i = 0; i < 5; i++) {
		classRosterArray[i] = Student();
	}

}

//Name: Constructor (int numStudents)
//Desc: initialzies classRosterArray to a size specified
//	by int parameter numStudents
Roster::Roster(int numStudents) {
	classRosterArray = new Student[numStudents];
	for (int i = 0; i < numStudents; i++) {
		classRosterArray[i] = Student();
	}
	this->numStudents = numStudents;
	this->nextIndex = 0;
}

Roster::~Roster() {
	delete[] classRosterArray;
}

//NAME: operator[] overload
//DESC: Experimental code that will expand classRosterArray up to designated index, 
//	filling intermediary indices with empty Student objects (all member vars set to empty)
Student& Roster::operator[](int index) {
	Student* newArray;
	int oldNextIndex = 0;
	if (index >= numStudents) {
		oldNextIndex = this->nextIndex - 1;
		newArray = new Student[index + 1];

		// copy existing values into new array
		for (int c = 0; c < this->nextIndex; c++) {
			newArray[c] = classRosterArray[c];
		}

		// initialize the new indices
		for (int i = this->nextIndex; i < index + 1; i++) {
			newArray[i] = Student();
		}
		delete[] classRosterArray;
		classRosterArray = newArray;
		numStudents = index + 1;
	}
	if (index > this->nextIndex) {
		this->nextIndex = index + 1;
	}
	return *(classRosterArray + index);
}

int Roster::getNumStudents() {
	return this->numStudents;
}

//Name: addStudentData (string[] studentData, int arrSize)
//Desc: For each string in the provide studentData array,
//	parse the data in the string extracting the data pieces into a string array
//	add the student using the string array per F3 requirement
void Roster::addStudentData(const string* studentData, int arrSize) {
	for (int i = 0; i < arrSize; i++) {

		// array of strings to hold data parsed from one studentData array string
		string strArr[reqNumFields];
		this->parseStudentStr(studentData[i], strArr); // parse data into stringArr

		// F3. Add each student to classRoster
		this->add(strArr[0], strArr[1], strArr[2], strArr[3], stoi(strArr[4]), stoi(strArr[5]), stoi(strArr[6]), stoi(strArr[7]), stringToDegree(strArr[8]));
	}
}

//Name: parseStudentStr
//Desc: validates and parses a given string containing pieces of data seperated by the delimiter
//	and adds each piece of data to the provided string array. The delimiter param
//	defaults to the Roster member strDelim
// E2a. Parse each set of data identified in the �studentData Table.�
void Roster::parseStudentStr(string studentStr, string* strArr, char delim) {
	if (!this->validateStudentStr(studentStr)) {
		return;
	}
	int endIdx = 0; // index to end each parse
	for (int i = 0; i < reqNumFields; i++) {
		endIdx = studentStr.find(delim); // find the next occurance of the delim
		strArr[i] = studentStr.substr(0, endIdx); // store the string value before the delim
		studentStr = studentStr.substr(endIdx + 1); // remove the data and delim from student string
	}
}

//Name: validateStudentStr <helper for Roster::parseStudentStr>
//Desc: returns true if the given studentStr contains the proper number of required fields
bool Roster::validateStudentStr(string studentStr) {
	int numFields = 0; // number of fields found in each studentData array string
	numFields = this->countStringDelimiters(studentStr) + 1; // get count of delimiters, adding 1 to get field count
	if (numFields != reqNumFields) {
		cout << "studentData contains invalid number of data fields" << endl;
		return false;
	}
	return true;
}

//Name: countStringDelimiters <helper for Roster::validateStudentStr>
//Desc: finds the number of delimiters in a given string
//	delimiter param defaults to Roster member strDelim
int Roster::countStringDelimiters(string str, char delim) {
	int delimCount = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == delim) {
			delimCount++;
		}
	}
	return delimCount;
}


//Name: add (student variables)
//Desc: Takes all the data variables required for a student and
//	adds it to the classRosterArray. If the classRosterArray is full
//	this function dynamically expands it to fit the Student to add.
//E2b. Add each student object to classRosterArray.
//E3a. (function) that sets the instance variables from part D1 and updates the roster.
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	Student* newArray;
	if (this->nextIndex == this->numStudents) { //if array is full
		this->numStudents++;
		newArray = new Student[this->numStudents];

		// copy existing values into new array
		for (int c = 0; c < this->nextIndex; c++) {
			newArray[c] = classRosterArray[c];
		}
		delete[] classRosterArray;
		classRosterArray = newArray;
	}
	// initialize the new index
	int completionDays[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[this->nextIndex++] = Student(studentID, firstName, lastName, emailAddress, age, completionDays, degreeprogram);
}

//Name: remove (string studentID)
//Desc: Removes students from classRosterArray by replacing the array with 
//	a new one without the newly removed student. If the student isn't found an
//	error message is printed to the user
//E3b. (function) that removes students from the roster by student ID. 
//	If the student ID does not exist, the function prints an error message 
//	indicating that the student was not found.
void Roster::remove(string studentID) {
	bool found = false;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i].getStudentID() == Student::EMPTYID) continue;
		if (classRosterArray[i].getStudentID() == studentID) {
			found = true;
			Student* newArray;
			newArray = new Student[this->numStudents];

			// copy values until removal index into new array
			for (int c = 0; c < i; c++) {
				newArray[c] = classRosterArray[c];
			}
			// if not removing the last student in roster
			if (i != numStudents - 1) {
				//copy values after removal index into new array
				for (int c2 = i + 1; c2 < numStudents; c2++) {
					newArray[c2 - 1] = classRosterArray[c2];
				}
			}

			this->numStudents--;
			this->nextIndex--;
			delete[] classRosterArray;
			classRosterArray = newArray;
		}
	}
	if (!found) {
		cout << "(Error: Student with ID '" << studentID << "' was not found!)" << endl << endl;
	}
}

//Name: printAll
//Desc:
//E3b.  Prints a complete tab-separated list of student data in the provided format
void Roster::printAll() {
	for (int i = 0; i < this->numStudents; i++) {
		classRosterArray[i].print();
	}
	cout << endl;
}

//Name: printInvalidEmails
//Desc:
//E3d. Verifies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails() {
	string email = "";
	// A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	char atSymbol = '@';
	char period = '.';
	char space = ' ';
	string reasons = "";

	for (int i = 0; i < numStudents; i++) {
		email = classRosterArray[i].getEmail();

		if (email.find(atSymbol) == string::npos) {
			reasons += "[Missing '@']";
		}
		if (email.find(period) == string::npos) {
			reasons += "[Missing '.']";
		}
		if (email.find(space) != string::npos) {
			reasons += "[Contains a space]";
		}
		if (reasons != "") {
			cout << "Invalid email found for ID: " << classRosterArray[i].getStudentID() << " (" << email << ") : " << reasons << endl;
		}
		reasons = "";
	}
	cout << endl;
}

//Name: printAverageDaysInCourse (string studentID)
//Desc:
//E3f. Prints out student information for a degree program specified by an enumerated type.
void Roster::printAverageDaysInCourse(string studentID) {
	int sum = 0;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i].getStudentID() == Student::EMPTYID) continue;
		if (classRosterArray[i].getStudentID() == studentID) {
			int* days = classRosterArray[i].getCompletionDays();
			int numDays = Student::NUMDAYS;
			for (int i = 0; i < numDays; i++) {
				sum += days[i];
			}
			cout << "ID: " << studentID << " Average Days In Course: " << (sum / numDays) << endl;
			return;
		}
	}
	cout << "(Error: Student with ID '" << studentID << "' was not found!)" << endl;
	cout << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeprogram) {
	bool found = false;
	cout << "Students enrolled in " << Student::formatDegreeString(degreeToString(degreeprogram)) << " degree program:" << endl;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i].getStudentID() == Student::EMPTYID) continue;
		if (classRosterArray[i].getDegreeProgram() == degreeprogram) {
			found = true;
			classRosterArray[i].print();
		}
	}
	if (!found) {
		cout << "(Error: No students found!)" << endl;
	}
	cout << endl;
}
