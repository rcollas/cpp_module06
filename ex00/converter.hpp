#ifndef CPP_MODULE06_CONVERTER_HPP
#define CPP_MODULE06_CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <cmath>

enum {
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3,
	PSEUDO_LITTERAL = 4
};

bool isInteger(std::string const &str);
bool isFloat(std::string const &str);
bool isDouble(std::string const &str);
bool isChar(std::string const &str);
int getType(std::string const &str);
void printOutput(int intVal, float floatVal, double doubleVal, char charVal);
void handleChar(std::string input);
void handleDouble(std::string input);
void handleFloat(std::string input);
void handleInt(std::string input);

#endif
