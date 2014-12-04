#include "trade.hpp"

void trade::load(std::istream &ifs)
{
	std::string line = getline(ifs);
	int len = line.size();
	std::vector<std::string> buffer(5);
	int num = 0;
	for (int i = 0; i < len; ++i)
	{
		if (line[i] != ',')
			buffer[num] += line[i];
		else ++num;
	}
	//devide whole line into parts;
	
	for (int i = 0; i < 5; ++i)
		buffer[i] = formu(buffer[i]);
	//remove '"'

	id = atoi(buffer[0].c_str());
	//get customer's id

	double lati = atof(buffer[1].c_str());
	double logi = atof(buffer[2].c_str());
	addr = location(lati, logi);
	//get the seller's location

	len = buffer[3].size();
	int year, month, day;
	year = month = day = 0;
	int i = 0;
	for (; i < len; ++i)
		if (buffer[3][i] != '/')
			year = year * 10 + buffer[3][i] - '0';
		else
			break;
	++i;
	for (; i < len; ++i)
		if (buffer[3][i] != '/')
			month = month * 10 + buffer[3][i] - '0';
		else break;
	++i;
	for (; i < len; ++i)
		day = day * 10 + buffer[3][i] - '0';
	timeStamp.set_date(year, month, day);
	//get the trade's finish time
	
	type = atoi(buffer[4].c_str());
	//get the type of the seller
}

void trade::print(std::ostream &ofs)
{
	int year, month, day;
	timeStamp.get_date(year, month, day);
	ofs << id << " " << addr.latitude << " " << addr.logitude << " " << year << "-" << month << "-" << day << " " << type;
	ofs << std::endl;
}