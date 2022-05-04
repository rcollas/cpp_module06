#include "Data.hpp"
#include <stdint.h>

uintptr_t serialize(Data* ptr) {

	return reinterpret_cast<uintptr_t>(ptr);
}

Data *deserialize(uintptr_t raw) {

	return reinterpret_cast<Data *>(raw);
}

int main() {

	Data *data = new Data;
	uintptr_t ptr = serialize(data);

	Data *deData = deserialize(ptr);

	std::cout << *data << std::endl;
	std::cout << std::endl;
	std::cout << *deData << std::endl;

	return 0;
}
