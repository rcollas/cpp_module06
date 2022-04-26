#include "converter.hpp"

class InvalidTypeException : std::exception {
	public:
		virtual const char * what () const throw() {
			return "Cannot convert: invalid type";
		};
};

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

int getType(std::string const &str) {

	if (isInteger(str)) {
		return INT;
	} else if (isFloat(str)) {
		return FLOAT;
	} else if (isDouble(str)) {
		return DOUBLE;
	} else if (isChar(str)) {
		return CHAR;
	} else {
		throw InvalidTypeException();
	}
}
