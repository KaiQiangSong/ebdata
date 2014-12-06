#ifndef STATISTICS
#define STATISTICS

#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>

#ifndef EPS
#define EPS 1e-8
#endif

extern std::vector<func_v2d> func_statistics;

double get_max(vec V)
{
	if (V.size()) return *std::max_element(V.begin(), V.end());
	return 0;
}

double get_min(vec V)
{
	if (V.size()) return *std::min_element(V.begin(), V.end());
	return 0;
}

double get_range(vec V)
{
	return get_max(V) - get_min(V);
}

double get_avg(vec V)
{
	size_t len = V.size();
	double sum = 0;
	for (auto it : V)
		sum += it;
	return (sum / len);
}

double get_median(vec V)
{
	size_t len = V.size();
	if (len) return V[len / 2];
	return 0;
}

double get_center_moment(vec V,double k)
{
	size_t len = V.size();
	double avg = get_avg(V);
	double sum = 0;
	for (auto it : V)
		sum += pow(it - avg, k) / len;
	return (sum / len);
}

double get_StandardDeviation(vec V)
{
	size_t len = V.size();
	if (len > 1 && fabs(get_center_moment(V,2)) > EPS)
		return sqrt(get_center_moment(V, 2) * len / (len - 1));
	return 1;
}

double get_Skewness(vec V)
{
	return get_center_moment(V, 3) / pow(get_StandardDeviation(V), 3);
}

double get_Kurtosis(vec V)
{
	return get_center_moment(V, 4) / pow(get_StandardDeviation(V), 4);
}

void make_statistics_func_list()
{
	func_statistics.push_back(get_max);
	func_statistics.push_back(get_min);
	func_statistics.push_back(get_range);
	func_statistics.push_back(get_avg);
	func_statistics.push_back(get_median);
	func_statistics.push_back(get_StandardDeviation);
	func_statistics.push_back(get_Skewness);
	func_statistics.push_back(get_Kurtosis);
}

feature get_statistics_feature(vec V)
{
	feature feat;
	for (auto fun : func_statistics)
		feat.push_back(fun(V));
	for (int k = 2; k < 5; ++k)
		feat.push_back(get_center_moment(V, k));
	return feat;
}

#endif