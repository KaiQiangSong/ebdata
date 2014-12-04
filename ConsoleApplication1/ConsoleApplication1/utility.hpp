#ifndef UTILITY_SKQ
#define UTILITY_SKQ

#include <iostream>
#include <string>
#include <vector>

#include "date.hpp"
#include "location.hpp"

struct address
{
	std::string whole;
	bool vailed;
};

std::string getline(std::istream& ifs);
std::string formu(std::string s);

#endif