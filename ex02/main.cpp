#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate() {

	srand(time(0));

	int randNb = rand() % 3;
	switch (randNb) {
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
	}
	return 0;
}

void identify(Base *p) {

	A* a = dynamic_cast<A *>(p);
	if (a != 0) {
		std::cout << "Pointer to type A" << std::endl;
	}

	B* b = dynamic_cast<B *>(p);
	if (b != 0) {
		std::cout << "Pointer to type B" << std::endl;
	}

	C* c = dynamic_cast<C *>(p);
	if (c != 0) {
		std::cout << "Pointer to type C" << std::endl;
	}
}

void identify(Base &p) {

	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "Pointer to type A" << std::endl;
	} catch (std::exception &exception) {}

	try {
		B b = dynamic_cast<B &>(p);
		std::cout << "Pointer to type B" << std::endl;
	} catch (std::exception &exception) {}

	try {
		C c = dynamic_cast<C &>(p);
		std::cout << "Pointer to type C" << std::endl;
	} catch (std::exception &exception) {}
}

int main() {

	Base *foo = generate();
	Base *bar = 0;

	identify(foo);
	identify(*foo);

	identify(bar);
	identify(*bar);

	delete foo;

	return 0;
}