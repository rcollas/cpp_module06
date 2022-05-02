#include "converter.hpp"

void printChar(char value, double doubleVal) {

	if (!std::isfinite(doubleVal)) {
		std::cout << "char: impossible" << std::endl;
	} else if (!isprint(value)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: " << value << std::endl;
	}
}

void printInt(int value, double doubleVal) {

	if (intOverflow) {
		std::cout << "int: overflow" << std::endl;
	} else if (!std::isfinite(doubleVal)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << value << std::endl;
	}
}

void printFloat(float value) {

	if (floatOverflow) {
		std::cout << "float: overflow" << std::endl;
	} else {
		std::cout << std::setprecision(1) << std::fixed;
		std::cout << "float: " << value << "f" << std::endl;
	}
}

void printDouble(double value) {

	if (doubleOverflow) {
		std::cout << "double: overflow" << std::endl;
	} else {
		std::cout << std::setprecision(1) << std::fixed;
		std::cout << "double: " << value << std::endl;
	}
}

void printOutput(int intVal, float floatVal, double doubleVal, char charVal) {

	printChar(charVal, doubleVal);
	printInt(intVal, doubleVal);
	printFloat(floatVal);
	printDouble(doubleVal);
}
