#include "converter.hpp"

void handleInt(std::string input) {

	int intVal = std::atoi(input.c_str());
	float floatVal = static_cast<float>(intVal);
	double doubleVal = static_cast<double>(intVal);
	char charVal = static_cast<char>(intVal);

	printOutput(intVal, floatVal, doubleVal, charVal);
}

void handleFloat(std::string input) {

	float floatVal = static_cast<float>(std::atof(input.c_str()));
	int intVal = static_cast<int>(floatVal);
	double doubleVal = static_cast<double>(floatVal);
	char charVal = static_cast<char>(floatVal);

	printOutput(intVal, floatVal, doubleVal, charVal);
}

void handleDouble(std::string input) {

	double doubleVal = std::atof(input.c_str());
	int intVal = static_cast<int>(doubleVal);
	float floatVal = static_cast<float>(doubleVal);
	char charVal = static_cast<char>(doubleVal);

	printOutput(intVal, floatVal, doubleVal, charVal);
}

void handleChar(std::string input) {

	char charVal = input[0];
	int intVal = static_cast<int>(charVal);
	float floatVal = static_cast<float>(charVal);
	double doubleVal = static_cast<double>(charVal);

	printOutput(intVal, floatVal, doubleVal, charVal);
}
