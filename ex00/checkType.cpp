#include "converter.hpp"

bool isInteger(std::string const &str) {

	if (str.empty()) {
		return false;
	}

	char *ptr;
	long nb;

	nb = std::strtol(str.c_str(), &ptr, 10);
	if (nb > INT_MAX || nb < INT_MIN) {
		intOverflow = true;
		return false;
	}
	return (*ptr) == '\0' && nb < INT_MAX && nb > INT_MIN;
}

bool isFloat(std::string const &str) {

	if (str.empty()) {
		return false;
	}

	char *ptr;
	float nb;

	nb = std::strtod(str.c_str(), &ptr);
	if (std::isinf(nb)) {
		intOverflow = true;
		floatOverflow = true;
		return false;
	} else if (intOverflow) {
		return true;
	}
	return (*ptr) == 'f' && str.find('f') + 1 == str.length();
}

bool isDouble(std::string const &str) {

	if (str.empty()) {
		return false;
	}

	char *ptr;
	long double nb;

	nb = std::strtod(str.c_str(), &ptr);
	if (nb > DBL_MAX || nb < DBL_MIN) {
		doubleOverflow = true;
		return true;
	} else if (floatOverflow) {
		return true;
	}
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

	if (isPseudoLitteral(str)) {
		return PSEUDO_LITTERAL;
	} else if (isInteger(str)) {
		return INT;
	} else if (isFloat(str)) {
		return FLOAT;
	} else if (isDouble(str)) {
		return DOUBLE;
	} else if (isChar(str)) {
		return CHAR;
	} else {
		throw std::invalid_argument("Invalid type");
	}
}
