#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "degree.h"
#include "student.h"
#include "roster.h"

void printAssessmentInfo() {
	cout << "--------------------------------------------------------------" << endl;
	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "WGU Student ID: XXXXXXXXX" << endl;
	cout << "Student Name: William Forbes" << endl;
	cout << "--------------------------------------------------------------" << endl;
}

int main()
{
	// F1. Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	printAssessmentInfo();

	//A.  Modify the “studentData Table” to include your personal information as the last item.
	const string studentData[] =
	{
		"A1,Jim,Smith,Jim2000@gm ail.com,21,30,35,40,NETWORK",
		"A2,Susan,Susana,Susana_2001@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Kent,The_lawyer01yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Eric,White,Eric.white@comcast.net,22,50,58,40,SECURITY",
		"A5,William,Forbes,wforbes87@gmail.com,33,28,51,125,SOFTWARE"
	};

	// array size is the difference in pointer value between next memory block and this one
	int arrSize = *(&studentData + 1) - studentData;

	Roster classRoster = Roster(); // F2. Create an instance of the Roster class called classRoster.

	classRoster.addStudentData(studentData, arrSize);


	classRoster.printAll();
	classRoster.printInvalidEmails();

	for (int i = 0; i < arrSize; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i].getStudentID());
	}

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");

	//Further demonstration
	cout << "classRoster.add() dynamically expands classRosterArray" << endl;
	cout << "Adding 9 more students" << endl;
	classRoster.add("J23", "Jim", "Wagermanjensen", "jimmy@jmail.jom", 54, 32, 503, 140, DegreeProgram::NETWORK);
	classRoster.add("A6", "Graham", "Stephan", "graham@gmail.com", 42, 7, 2, 5, DegreeProgram::SECURITY);
	classRoster.add("A7", "Bob", "Lazar", "aliens@ufo.com", 55, 42, 42, 42, DegreeProgram::SOFTWARE);
	classRoster.add("A8", "Stephen", "King", "horror@scary.com", 72, 42, 42, 42, DegreeProgram::NETWORK);
	classRoster.add("A9", "Evelyn", "Etsy", "jewels@shiny.com", 23, 42, 42, 42, DegreeProgram::SECURITY);
	classRoster.add("A10", "Oscar", "Meyer", "ilikefood@dog.com", 9, 42, 42, 42, DegreeProgram::SOFTWARE);
	classRoster.add("A11", "Crookshanks", "Forbes", "taxes@irs.com", 3, 42, 42, 42, DegreeProgram::SECURITY);
	classRoster.add("A12", "Joe", "Jackson", "joe@farm.com", 35, 42, 42, 42, DegreeProgram::NETWORK);
	classRoster.add("A13", "Oscar", "Gomez", "ogomez@gmail.com", 9, 42, 42, 42, DegreeProgram::SOFTWARE);
	classRoster.printAll();
	cout << "Roster size: " << classRoster.getNumStudents() << endl << endl;

	cout << "classRoster.remove() dynamically shrinks classRosterArray" << endl;
	cout << "Removing 5 students randomly throughout" << endl;
	classRoster.remove("A8");
	classRoster.remove("A11");
	classRoster.remove("A13");
	classRoster.remove("A6");
	classRoster.remove("A2");
	classRoster.printAll();
	cout << "Roster Size: " << classRoster.getNumStudents() << endl << endl;

	//Experiments with operator overloading
	cout << "Roster\'s [] operator is overloaded to access students in classRosterArray directly" << endl;
	cout << "Printing student at indices 3, 7 and 1 with [] operator (classRoster[3].print();)" << endl;
	classRoster[3].print();
	classRoster[7].print();
	classRoster[1].print();
	cout << endl << endl;

	cout << "Accessing index out of array bounds using [] operator " << endl;
	cout << "  expands classRosterArray up to the specified index" << endl;
	cout << "Demonstrating: classRoster[35].setFirstName(\"Amanda\");" << endl;
	classRoster[25].setFirstName("Amanda");
	classRoster.printAll();
	cout << "Roster Size: " << classRoster.getNumStudents() << endl << endl;

	return 0;
}