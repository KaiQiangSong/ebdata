#include "utility.hpp"



std::string getline(std::istream& ifs)
{
	std::string res = "";
	std::getline(ifs, res);
	return res;
}

std::string formu(std::string s)
{
	if (s[0] == '"')
		s = s.substr(1);
	if (s[s.size() - 1] == '"')
		s = s.substr(0, s.size() - 1);
	return s;
}
