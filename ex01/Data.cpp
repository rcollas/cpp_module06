#include "Data.hpp"

Data::Data()
	:	m_nb(10),
		m_str("default"),
		m_doubleNb(10.543),
		m_nbPtr(&m_nb) {}

Data::~Data() {}

Data::Data(Data const &src) {

	*this = src;
}

Data &Data::operator=(const Data &rhs) {

	this->m_nb = rhs.m_nb;
	this->m_str = rhs.m_str;
	this->m_doubleNb = rhs.m_doubleNb;
	this->m_nbPtr = rhs.m_nbPtr;
	return *this;
}

int Data::getNb() {

	return this->m_nb;
}

std::string Data::getStr() {

	return this->m_str;
}

double Data::getDouble() {

	return this->m_doubleNb;
}

void *Data::getPtr() {

	return this->m_nbPtr;
}

std::ostream &operator<<(std::ostream &out, Data &rhs) {

	out << "number: " << rhs.getNb() << std::endl;
	out << "string: " << rhs.getStr() << std::endl;
	out << "double: " << rhs.getDouble() << std::endl;
	out << "pointer: " << rhs.getPtr();
	return out;
}
