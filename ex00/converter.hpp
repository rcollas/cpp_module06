#ifndef CPP_MODULE06_CONVERTER_HPP
#define CPP_MODULE06_CONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <stdexcept>

enum {
	CHAR = 0,
	INT = 1,
	FLOAT = 2,
	DOUBLE = 3
};

bool isInteger(std::string const &str);
bool isFloat(std::string const &str);
bool isDouble(std::string const &str);
bool isChar(std::string const &str);
int getType(std::string const &str);

#endif
