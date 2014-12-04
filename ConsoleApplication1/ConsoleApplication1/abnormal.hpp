#ifndef ABNORMAL
#define ABNORMAL

#include "utility.hpp"

class abnormal
{
public:
	int id;
	date_v check_date;
	int label;
public:
	void load(std::istream &ifs);
	void print(std::ostream &ofs);
};


#endif