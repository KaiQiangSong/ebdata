#include "abnormal.hpp"

void abnormal::load(std::istream &ifs)
{
	std::string line = getline(ifs);
	int len = line.size();
	std::vector<std::string> buffer(3);
	int num = 0;
	for (int i = 0; i < len; ++i)
	{
		if (line[i] != ',')
			buffer[num] += line[i];
		else ++num;
	}
	//devide whole line into parts;

	for (int i = 0; i < 3; ++i)
		buffer[i] = formu(buffer[i]);
	//remove '"'

	id = atoi(buffer[0].c_str());
	//get customer's id

	if (buffer[1] != "")
	{
		check_date.setVailed(true);
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
			else
				break;
		++i;
		for (; i < len; ++i)
			day = day * 10 + buffer[1][i] - '0';
		check_date.set_date(year, month, day);
	}
	else
		check_date.setVailed(false);
	//get customer's birthday

	if (buffer[2] != "")
		label = atoi(buffer[2].c_str());
	else
		label = 0;
	//get customer's label
}

void abnormal::print(std::ostream &ofs)
{
	int year, month, day;
	check_date.get_date(year, month, day);
	ofs << id << " " << year << "-" << month << "-" << day << " " << label;
	ofs << std::endl;
}