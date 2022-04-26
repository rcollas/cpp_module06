#include "converter.hpp"

bool isInteger(std::string const &str) {

	if (str.empty()) {
		return false;
	}

	char *ptr;
	strtol(str.c_str(), &ptr, 10);
	return (*ptr) == '\0';
}

bool isFloat(std::string const &str) {

	if (str.empty()) {
		return false;
	}

	char *ptr;
	strtof(str.c_str(), &ptr);
	return (*ptr) == 'f' && str.find('f') + 1 == str.length();
}

bool isDouble(std::string const &str) {

	if (str.empty()) {
		return false;
	}

	char *ptr;
	strtod(str.c_str(), &ptr);
	return (*ptr) == '\0' && (str.find('.') != std::string::npos);
}

bool isChar(std::string const &str) {

	return str.length() == 1;
}

bool isPseudoLitteral(std::string const &str) {

	std::string litteral[6] = {"-inff","+inff","nanf",
							   "-inf", "+inf", "nan"};
	for (int i = 0; i < 6; i++) {
		if (str == litteral[i]) {
			return true;
		}
	}
	return false;
}

int getType(std::string const &str) {

	if (isInteger(str)) {
		return INT;
	} else if (isFloat(str)) {
		return FLOAT;
	} else if (isDouble(str)) {
		return DOUBLE;
	} else if (isChar(str)) {
		return CHAR;
	} else if (isPseudoLitteral(str)) {
		return PSEUDO_LITTERAL;
	} else {
		throw std::invalid_argument("Invalid type");
	}
}
