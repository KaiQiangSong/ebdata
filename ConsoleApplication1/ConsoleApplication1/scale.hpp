#ifndef SCALE
#define SCALE

#include <utility>
#include <fstream>

#ifndef INF
#define INF (99e99)
#endif

extern std::vector<std::pair<double, double>> Scale;

void scale_train(vec_d &v,double &lowest,double &highest)
{
	lowest = +INF;
	highest = -INF;
	size_t len = v.size();
	for (size_t i = 0; i < len; ++i)
	{
		if (v[i] < lowest) lowest = v[i];
		if (v[i] > highest) highest = v[i];
	}
	double region = highest - lowest;
	for (size_t i = 0; i < len; ++i)
		v[i] = (v[i]-lowest) / region;
}

void scale_test(vec_d &v, double lowest, double highest)
{
	size_t len = v.size();
	double region = highest - lowest;
	for (size_t i = 0; i < len; ++i)
		v[i] = (v[i]-lowest) / region;
}

void scale_file_load()
{
	double lowest, highest;
	std::ifstream ifs("scale.txt");
	while (ifs >> lowest >> highest)
		Scale.push_back(std::make_pair(lowest, highest));
	ifs.close();
}

void scale_file_save()
{
	std::ofstream ofs("scale.txt");
	for (auto it : Scale)
		ofs << it.first << " " << it.second << std::endl;
	ofs.close();
}


void do_scale()
{
	size_t dim = featVec.begin()->second.size();
#ifdef TEST
	scale_file_load();
#endif
	for (size_t i = 0; i < dim; ++i)
	{
		vec_d Feat;
		double lowest, highest;
		for (auto it : featVec)
			Feat.push_back(it.second[i]);
#ifdef TRAIN
		scale_train(Feat, lowest, highest);
		Scale.push_back(std::make_pair(lowest, highest));
#endif
#ifdef TEST
		lowest = Scale[i].first;
		highest = Scale[i].second;
		scale_test(Feat, lowest, highest);
#endif
		int cnt = 0;
		for (auto &it : featVec)
			it.second[i] = Feat[cnt++];
	}
#ifdef TRAIN
	scale_file_save();
#endif
}

#endif