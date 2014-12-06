//#define DEBUG_HASH

#ifndef BUILD_HASH_LIST
#define BUILD_HASH_LIST

#include <algorithm>
#include <vector>
#include <map>

#include "trade.hpp"
#include "location.hpp"


extern std::map<int, vec_t> Hash;
extern std::map<location, int> location2id;
extern std::vector<location> id2location;
extern std::map<std::string, int> type2int;

bool cmp(trade A, trade B)
{
	return (A.timeStamp < B.timeStamp);
}

bool same_pos(trade x, trade y)
{
	return (x.addr.latitude == y.addr.latitude && x.addr.logitude == y.addr.logitude);
}

void build_hash_id2tradelist()
{
	for (auto it : T_trade)
	{
		if (Hash.find(it.id) == Hash.end())
		{
			vec_t x;
			Hash[it.id] = x;
		}
		Hash[it.id].push_back(it);
	}
#ifdef DEBUG_HASH
	for (auto it : Hash)
	{
		std::sort(it.second.begin(), it.second.end(), cmp);
		ofs << it.first << " : " << std::endl;
		for (auto itTrade : it.second)
		{
			itTrade.print(ofs);
		}
		ofs << std::endl;
	}
#endif
}

void build_hash_location2id_id2location()
{
	int cnt = 0;
	for (auto itTrade : T_trade)
	{
		if (location2id.find(itTrade.addr) == location2id.end())
		{
			location2id[itTrade.addr] = cnt++;
			id2location.push_back(itTrade.addr);
		}
	}
#ifdef DEBUG_HASH
	for (auto it : location2id)
	{
		ofs << it.first.logitude << " " << it.first.latitude << " : " << it.second << std::endl;
	}
	for (auto it : id2location)
	{
		ofs << it.logitude << " " << it.latitude << std::endl;
	}
#endif
}

void build_hash_type2int()
{
	type2int["蓝色一类"] = 0;
	type2int["橙色一类"] = 1;
	type2int["橙色二类"] = 2;
	type2int["橙色三类"] = 3;
	type2int["橙色四类"] = 4;
	type2int["橙色五类"] = 5;
	type2int["橙色六类"] = 6;
	type2int["橙色七类"] = 7;
	type2int["红色一类"] = 8;
	type2int["红色二类"] = 9;
	type2int["警综人员"] = 10;
}

void build_hash()
{
#ifdef DEBUG_HASH
	std::ofstream ofs("hash_check.txt");
#endif
	build_hash_id2tradelist();
	build_hash_location2id_id2location();
	build_hash_type2int();
#ifdef DEBUG_HASH
		ofs.close();
#endif
}

#endif