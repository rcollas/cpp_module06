#include "converter.hpp"

void printOutput(int intVal, float floatVal, double doubleVal, char charVal) {

	if (!std::isfinite(doubleVal)) {
		std::cout << "char: impossible" << std::endl;
	} else if (!isprint(charVal)) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: " << charVal << std::endl;
	}
	if (!std::isfinite(doubleVal)) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << intVal << std::endl;
	}
	std::cout << std::setprecision(6) << std::fixed;
	std::cout << "float: " << floatVal << "f" << std::endl;
	std::cout << std::setprecision(10) << std::fixed;
	std::cout << "double: " << doubleVal << std::endl;
}

int main(int argc, char **argv) {

	(void)argc;


	int type;
	try {
		type = getType(argv[1]);
	} catch (std::invalid_argument const &e) {
		std::cerr << e.what() << std::endl;
		type = -1;
	}

	switch (type) {
		case CHAR:
			handleChar(argv[1]);
			break;
		case INT:
			handleInt(argv[1]);
			break;
		case FLOAT:
			handleFloat(argv[1]);
			break;
		case DOUBLE:
			handleDouble(argv[1]);
			break;
		case PSEUDO_LITTERAL:
			handleDouble(argv[1]);
			break;
	}

	return 0;
}