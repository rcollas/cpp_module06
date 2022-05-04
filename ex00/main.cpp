#include "converter.hpp"

bool intOverflow = false;
bool floatOverflow = false;
bool doubleOverflow = false;



int main(int argc, char **argv) {

	if (argc <= 1) {
		std::cerr << "converter takes one argument" << std::endl;
		return 1;
	}

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