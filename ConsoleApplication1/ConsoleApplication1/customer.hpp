#ifndef CUSTOMER
#define CUSTOMER

#include "utility.hpp"

class customer
{
public:
	int id;
	date_v birth;
	char gender;
	address addr;
	std::string type;

public:
	void load(std::istream& ifs);
	void print(std::ostream& ofs);
};


#endif