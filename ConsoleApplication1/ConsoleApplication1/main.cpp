#include <cstdlib>

#include <fstream>
#include <map>
#include <algorithm>


//-----------------------------Primary Classes------------------------------//
#include "customer.hpp"
#include "trade.hpp"
#include "abnormal.hpp"


//-----------------------------Load and Print part-----------------------------//
//std::vector<customer> T_customer;
std::map<int, customer> T_customer;
std::vector<trade> T_trade;
std::map<int, int> Label;
#include "data_load.hpp"


//-----------------------------Build Hash List-----------------------------//
typedef std::vector<trade> vec_t;
std::map < int, vec_t >  Hash;
std::map<location, int> location2id;
std::vector<location> id2location;
#include "build_hash_list.hpp"


//-----------------------------Feature Extractiong----------------------------//
typedef std::vector<double> feature;
#include <functional>
typedef std::function<feature(vec_t)> func;
typedef std::vector<double> vec;
typedef std::function<double(vec)> func_v2d;

std::map<int, std::vector<feature>> feat;
std::vector<func> func_vec;
std::vector<func_v2d> func_statistics;

#include "feature.hpp"



int main(int argv, char *argc[])
{
	load_all();
	std::cout << "Load Done" << std::endl;
	build_hash();
	std::cout << "Build Hash List Done" << std::endl;
	make_statistics_func_list();
	make_feature_list();
	extract_feature();
	std::cout << "Extract Feature Done" << std::endl;
	display_feature();
	std::cout << "Display Done" << std::endl;
	return 0;
}
