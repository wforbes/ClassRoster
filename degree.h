#pragma once
#include <string>
using namespace std;

enum class DegreeProgram { SECURITY, NETWORK, SOFTWARE };
//C.Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE.

inline const char* degreeToString(DegreeProgram degreeprogram) {
	switch (degreeprogram) {
	case DegreeProgram::SECURITY:
		return "SECURITY";
	case DegreeProgram::NETWORK:
		return "NETWORK";
	case DegreeProgram::SOFTWARE:
		return "SOFTWARE";
	default:
		return "";
	}
}

inline DegreeProgram stringToDegree(string str) {
	if (str == "SECURITY") return DegreeProgram::SECURITY;
	else if (str == "NETWORK") return DegreeProgram::NETWORK;
	else if (str == "SOFTWARE") return DegreeProgram::SOFTWARE;
}