#ifndef CPP_MODULE06_DATA_HPP
#define CPP_MODULE06_DATA_HPP

#include <iostream>

class Data {

	public:
		Data();
		Data(Data const &src);
		~Data();

		Data &operator=(Data const &rhs);
		int getNb();
		std::string getStr();
		double getDouble();
		void *getPtr();

	private:
		int m_nb;
		std::string m_str;
		double m_doubleNb;
		int *m_nbPtr;

};

std::ostream &operator<<(std::ostream &out, Data &rhs);

#endif
