//#define DEBUG_LOAD

#include <iostream>
#include <fstream>
#include <map>


#include "data_load.hpp"
#include "trade.hpp"
#include "customer.hpp"
#include "abnormal.hpp"


//extern std::vector<customer> T_customer;
extern std::map<int, customer> T_customer;
extern std::vector<trade> T_trade;
extern std::map<int, int> Label;
extern std::map<int, date_v> Verify;

void load_customer()
{
#ifdef TRAIN
	std::ifstream ifs("train_customer.csv");
#endif
#ifdef TEST
	std::ifstream ifs("test_customer.csv");
#endif
	std::string s;
	getline(ifs, s);
	int cnt = 0;
	while (!ifs.eof())
	{
		customer x;
		x.load(ifs);
		if (x.id == 0) continue;
		T_customer[x.id] = x;
#ifdef DEBUG_LOAD
		++cnt;
		if ((cnt % 1000) == 0) std::cout << cnt << std::endl;
#endif
	}
	ifs.close();
}

void load_trade()
{
#ifdef TRAIN
	std::ifstream ifs("train_trade.csv");
#endif
#ifdef TEST
	std::ifstream ifs("test_trade.csv");
#endif
	std::string s;
	getline(ifs, s);
	int cnt = 0;
	while (!ifs.eof())
	{
		trade x;
		x.load(ifs);
		if (x.id == 0) continue;
		T_trade.push_back(x);
		//T_trade[x.id] = x;
#ifdef DEBUG_LOAD
		++cnt;
		if ((cnt % 1000) == 0) std::cout << cnt << std::endl;
#endif
	}
	ifs.close();
}

void load_abnormal()
{
	std::ifstream ifs("abnormal.csv");
	std::string s;
	getline(ifs, s);
	int cnt = 0;
	while (!ifs.eof())
	{
		abnormal x;
		x.load(ifs);
		if (x.id == 0) continue;
		Label[x.id] = x.label;
		Verify[x.id] = x.check_date;
		//in order to filter some useless information
#ifdef DEBUG_LOAD
		++cnt;
		if ((cnt % 1000) == 0) std::cout << cnt << std::endl;
#endif
	}
	ifs.close();
}

void load_all()
{
	load_customer();
	load_trade();
	load_abnormal();
#ifdef DEBUG_LOAD
	std::cout << T_customer.size() << std::endl;
	std::cout << T_trade.size() << std::endl;
	std::cout << Label.size() << std::endl;
	system("pause");
#endif
}

void print_all()
{
	std::ofstream ofs("debug_load.txt");
	for (auto it : T_customer)
		it.second.print(ofs);
	for (auto it : T_trade)
		it.print(ofs);
	for (auto it : Label)
		ofs << it.first << " " << it.second << std::endl;
	ofs.close();
}