#ifndef TRADE
#define TRADE

#include "utility.hpp"

class trade
{
public:
	int id;
	location addr;
	date timeStamp;
	int type;
public:
	trade()
	{
		memset(this, 0, sizeof(trade));
	}
	void load(std::istream& ifs);
	void print(std::ostream &ofs);
	bool operator == (trade x) const
	{
		if (id != x.id) return false;
		if (addr.latitude != x.addr.latitude) return false;
		if (addr.logitude != x.addr.logitude) return false;
		if (timeStamp != x.timeStamp) return false;
		if (type != x.type) return false;
		return true;
	}
};

#endif