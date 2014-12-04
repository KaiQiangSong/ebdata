#include "customer.hpp"

void customer::load(std::istream& ifs)
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

	if (buffer[1] != "")
	{
		birth.setVailed(true);
		len = buffer[1].size();
		int year, month, day;
		year = month = day = 0;
		int i = 0;
		for (; i < len; ++i)
			if (buffer[1][i] != '-')
				year = year * 10 + buffer[1][i] - '0';
			else
				break;
		++i;
		for (; i < len; ++i)
			if (buffer[1][i] != '-')
				month = month * 10 + buffer[1][i] - '0';
			else break;
		++i;
		for (; i < len; ++i)
			day = day * 10 + buffer[1][i] - '0';
		birth.set_date(year, month, day);
	}
	else
		birth.setVailed(false);
	//get customer's birthday

	if (buffer[2] == "ÄÐÐÔ")
		gender = 'm';
	else
		if (buffer[2] == "Å®ÐÔ")
			gender = 'f';
		else
			gender = 'x';
	//get customer's gender

	if (buffer[3] != "")
	{
		addr.whole = buffer[3];
		addr.vailed = true;
	}
	else
		addr.vailed = false;
	//get customer's address
	
	type = buffer[4];
	//get customer's type
}

void customer::print(std::ostream& ofs)
{
	int year, month, day;
	birth.get_date(year, month, day);
	ofs << id << " " << year << "-" << month << "-" << day << " " << gender << " " << addr.whole << " " << type;
	ofs << std::endl;
}