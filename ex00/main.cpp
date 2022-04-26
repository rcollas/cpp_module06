#include "converter.hpp"

int main(int argc, char **argv) {

	(void)argc;


	int type;
	try {
		type = getType(argv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		type = -1;
	}

	switch (type) {
		case CHAR:
			std::cout << "Is a char" << std::endl;
			break;
		case INT:
			std::cout << "Is an integer" << std::endl;
			break;
		case FLOAT:
			std::cout << "Is a float" << std::endl;
			break;
		case DOUBLE:
			std::cout << "Is a double" << std::endl;
			break;
	}

	return 0;
}