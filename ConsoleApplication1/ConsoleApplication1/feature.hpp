#ifndef FEATURE
#define FEATURE

//#define LOAD_MARK

#ifdef TEST
#ifndef LOAD_MARK
#endif
#endif



#include <vector>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>


extern std::vector<func> func_vec;
//extern std::vector<std::map<int, feature>> feat;
extern std::map<int, std::vector<feature>> feat;
extern std::map<int, vec> featVec;

#include "statistics.hpp"
#include "analysis.hpp"

feature feat_trade_amount(vec_t trade_list)
{
	feature feat;
	feat.push_back(trade_list.size());
	return feat;
}


feature feat_trade_region(vec_t trade_list)
{
	feature feat;
	feat.push_back(trade_list[trade_list.size() - 1].timeStamp - trade_list[0].timeStamp);
	return feat;
}

/*
feature feat_trade_maxGap(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double maxGap = 0;
	for (size_t i = 0; i + 1 < len; ++i)
		if (trade_list[i + 1].timeStamp - trade_list[i].timeStamp > maxGap)
			maxGap = trade_list[i + 1].timeStamp - trade_list[i].timeStamp;
	feat.push_back(maxGap);
	return feat;
}

feature feat_trade_minGap(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double minGap;
	if (len > 1) minGap = trade_list[1].timeStamp - trade_list[0].timeStamp;
	for (size_t i = 1; i + 1 < len; ++i)
		if (trade_list[i + 1].timeStamp - trade_list[i].timeStamp < minGap)
			minGap = trade_list[i + 1].timeStamp - trade_list[i].timeStamp;
	feat.push_back(minGap);
	return feat;
}

feature feat_trade_avgGap(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double sum = 0;
	for (size_t i = 0; i + 1 < len; ++i)
		sum += trade_list[i + 1].timeStamp - trade_list[i].timeStamp;
	if (len > 1)
		feat.push_back(sum / (len - 1));
	else
		feat.push_back(0);
	return feat;
}

feature feat_trade_avgGap2(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double sum = 0;
	for (size_t i = 0; i + 1 < len; ++i)
		sum += (trade_list[i + 1].timeStamp - trade_list[i].timeStamp) * (trade_list[i+1].timeStamp - trade_list[i].timeStamp);
	if (len > 1)
		feat.push_back(sum / (len - 1));
	else
		feat.push_back(0);
	return feat;
}
*/


/*
feature feat_trade_minDate(vec_t trade_list)
{
	feature feat;
	feat.push_back(trade_list[0].timeStamp.get_time());
	return feat;
}

feature feat_trade_maxDate(vec_t trade_list)
{
	feature feat;
	feat.push_back(trade_list[trade_list.size() - 1].timeStamp.get_time());
	return feat;
}

feature feat_trade_avgDate(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double sum = 0;
	for (size_t i = 0; i < len; ++i)
		sum += trade_list[i].timeStamp.get_time();
	feat.push_back(sum / len);
	return feat;
}

feature feat_trade_medianDate(vec_t trade_list)
{
	feature feat;
	feat.push_back(trade_list[trade_list.size() / 2].timeStamp.get_time());
	return feat;
}

feature feat_trade_varianceDate(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double sum = 0;
	for (size_t i = 0; i < len; ++i)
		sum += trade_list[i].timeStamp.get_time();
	double avg = sum / len;
	sum = 0;
	for (size_t i = 0; i < len; ++i)
		sum += (trade_list[i].timeStamp.get_time() - avg) * (trade_list[i].timeStamp.get_time() - avg);
	feat.push_back(sqrt(sum / len));
	return feat;
}

feature feat_trade_variance2Date(vec_t trade_list)
{
	feature feat = feat_trade_varianceDate(trade_list);
	feat[0] *= feat[0];
	return feat;
}

feature feat_trade_StandardDeviationDate(vec_t trade_list)
{
	feature feat = feat_trade_varianceDate(trade_list);
	size_t len = trade_list.size();
	if (len > 1) feat[0] = feat[0] * sqrt(len / (len - 1));
	else feat[0] = 1;
	return feat;
}

feature feat_trade_SkewnessDate(vec_t trade_list)
{
	feature avg = feat_trade_avgDate(trade_list);
	feature S = feat_trade_StandardDeviationDate(trade_list);
	size_t len = trade_list.size();
	double sum = 0;
	for (size_t i = 0; i < len; ++i)
		sum = sum + pow((trade_list[i].timeStamp.get_time() - avg[0]) / S[0], 3);
	feature feat;
	feat.push_back(sum / len);
	return feat;
}

feature feat_trade_Kurtosis(vec_t trade_list)
{
	feature avg = feat_trade_avgDate(trade_list);
	feature S = feat_trade_StandardDeviationDate(trade_list);
	size_t len = trade_list.size();
	double sum = 0;
	for (size_t i = 0; i < len; ++i)
		sum = sum + pow((trade_list[i].timeStamp.get_time() - avg[0]) / S[0], 4);
	feature feat;
	feat.push_back(sum / len);
	return feat;
}
*/
feature feat_trade_dist2_total(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double sum = 0;
	for (size_t i = 0; i+1 < len; ++i)
		sum += dist2(trade_list[i].addr, trade_list[i + 1].addr);
	feat.push_back(sum);
	return feat;
}

feature feat_trade_distglobal_total(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double sum = 0;
	for (size_t i = 0; i + 1 < len; ++i)
		sum += dist_global(trade_list[i].addr, trade_list[i + 1].addr);
	feat.push_back(sum);
	return feat;
}

feature feat_trade_dist2_max(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double maxDist = 0;
	for (size_t i = 0; i + 1 < len; ++i)
		for (size_t j = i + 1; j < len; ++j)
			if (dist2(trade_list[i].addr, trade_list[j].addr) > maxDist)
				maxDist = dist2(trade_list[i].addr, trade_list[j].addr);
	feat.push_back(maxDist);
	return feat;
}

feature feat_trade_distglobal_max(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	double maxDist = 0;
	for (size_t i = 0; i + 1 < len; ++i)
		for (size_t j = i + 1; j < len; ++j)
			if (dist_global(trade_list[i].addr, trade_list[j].addr) > maxDist)
				maxDist = dist_global(trade_list[i].addr, trade_list[j].addr);
	feat.push_back(maxDist);
	return feat;
}

feature feat_trade_location_avg(vec_t trade_list)
{
	feature feat;
	size_t len = trade_list.size();
	feature distVec;
	for (size_t i = 0; i + 1 < len; ++i)
		for (size_t j = i + 1; j < len; ++j)
			distVec.push_back(dist2(trade_list[i].addr, trade_list[j].addr));

	return feat;
}

feature get_Date_statistics(vec_t trade_list)
{
	vec Date;
	for (auto it : trade_list)
		Date.push_back((double)it.timeStamp.get_time());
	return get_statistics_feature(Date);
}
feature get_Gap_statistics(vec_t trade_list)
{
	vec Gap;
	size_t len = trade_list.size();
	for (size_t i = 0; i + 1 < len; ++i)
		Gap.push_back(trade_list[i + 1].timeStamp.get_time() - trade_list[i].timeStamp.get_time());
	return get_statistics_feature(Gap);
}

feature get_dist2_statistics(vec_t trade_list)
{
	vec Dist;
	size_t len = trade_list.size();
	for (size_t i = 0; i + 1 < len; ++i)
		for (size_t j = i + 1; j < len; ++j)
			Dist.push_back(dist2(trade_list[i].addr, trade_list[j].addr));
	return get_statistics_feature(Dist);
}

feature get_distglobal_statistics(vec_t trade_list)
{
	vec Dist;
	size_t len = trade_list.size();
	for (size_t i = 0; i + 1 < len; ++i)
		for (size_t j = i + 1; j < len; ++j)
			Dist.push_back(dist_global(trade_list[i].addr, trade_list[j].addr));
	return get_statistics_feature(Dist);
}

feature get_track_dist2_statistics(vec_t trade_list)
{
	vec Dist;
	size_t len = trade_list.size();
	for (size_t i = 0; i + 1< len; ++i)
		Dist.push_back(dist2(trade_list[i].addr, trade_list[i + 1].addr));
	return get_statistics_feature(Dist);
}


feature get_track_distglobal_statistics(vec_t trade_list)
{
	vec Dist;
	size_t len = trade_list.size();
	for (size_t i = 0; i + 1< len; ++i )
		Dist.push_back(dist_global(trade_list[i].addr, trade_list[i + 1].addr));
	return get_statistics_feature(Dist);
}

void make_feature_list()
{
	func_vec.push_back(feat_trade_amount);
	func_vec.push_back(feat_trade_region);
	//Basic
	func_vec.push_back(get_Gap_statistics);
	//Date Gap
	func_vec.push_back(get_Date_statistics);
	//Date
	func_vec.push_back(get_dist2_statistics);
	func_vec.push_back(get_distglobal_statistics);
	//Location dist
	func_vec.push_back(get_track_dist2_statistics);
	func_vec.push_back(get_track_distglobal_statistics);
	//Track
}

feature get_basic_feature(customer x)
{
	feature feat;
	feat.push_back(type2int[x.type]);
	feat.push_back(x.id);
	feat.push_back(x.gender);
	if (x.birth.isVailed())
	{
		int year, month, day;
		x.birth.get_date(year, month, day);
		for (int i = 1; i < 13; ++i)
		{
			if (i == month)
				feat.push_back(1);
			else
				feat.push_back(-1);
		}
		for (int i = 0; i < 4; ++i)
			if (i * 3 < month && month <= (i * 3 + 3))
				feat.push_back(1);
			else
				feat.push_back(-1);
		// month
		for (int k = 0; k < 10; ++k)
			for (int i = 1910; i + k <= 2012; ++i)
				if (i <= year && year <= i + k)
					feat.push_back(1);
				else
					feat.push_back(-1);
	}
	else
	{
		for (int i = 1; i < 13; ++i)
			feat.push_back(0);
		for (int i = 0; i < 4; ++i)
			feat.push_back(0);
		for (int k = 0; k < 10; ++k)
			for (int i = 1910; i + k <= 2012; ++i)
				feat.push_back(0);
	}
	//histogram of month and year;
	for (int i = 0; i < 35; ++i)
		if (x.addr.get_province() == i)
			feat.push_back(+1);
		else feat.push_back(-1);
	return feat;
}

void extract_feature()
{
	/*
	int cnt = 0;
	for (auto fun : func_vec)
	{
		++cnt;
		std::cout << cnt << std::endl;
		for (auto it : Hash)
		{
			std::sort(it.second.begin(), it.second.end(), cmp);
			feature tfeature = fun(it.second);
			feat[it.first].push_back(tfeature);
		}
	}
	*/
	for (auto it : Hash)
	{
		feat[it.first].push_back(get_basic_feature(T_customer[it.first]));
		std::sort(it.second.begin(), it.second.end(), cmp);
		for (auto fun : func_vec)
		{
			feature tfeature = fun(it.second);
			feat[it.first].push_back(tfeature);
		}
	}
}



void formulation_feat2vec()
{
	for (auto it : feat)
	{
		for (auto f : it.second)
		{
			for (auto d : f)
				featVec[it.first].push_back(d);
		}
	}
}

vec check_each_feat()
{

#ifndef LOAD_MARK
	std::ofstream ofs("check_each_feature.txt");
	size_t dim = featVec.begin()->second.size();
	vec feature_mark;
	
	for (size_t i = 0; i < dim; ++i)
	{
		std::vector<int> id;
		vec Feat;
		for (auto it : featVec)
		{
			id.push_back(it.first);
			Feat.push_back(it.second[i]);
		}
		double result = mark(id, Feat);
		feature_mark.push_back(result);
		std::cout << i+1 << " :" << result << std::endl;
		ofs << result << std::endl;
		//system("pause");
	}
	ofs.close();
	return feature_mark;
#endif

#ifdef LOAD_MARK
	std::ifstream ifs("check_each_feature.txt");
	vec feature_mark;
	double x;
	while (ifs >> x)
		feature_mark.push_back(x);
	ifs.close();
	return feature_mark;
#endif
}

void display_feature(double threshold)
{
#ifdef TRAIN
	std::ofstream ofs("feat1_train.data");
#endif
#ifdef TEST
	std::ofstream ofs("feat1_test.data");
#endif
	srand(time(NULL));
	for (auto it : featVec)
	{
#ifdef TRAIN
		if (Label[it.first] == 0)
		{
			int ran = rand() % 1000;
			if (ran < 800) continue;
		}
#endif
		ofs << (Label[it.first]*2)-1 << " :";
		size_t len = it.second.size();
		for (size_t i = 0; i < len; ++i)
			if (feature_mark[i] >= threshold)
				ofs << " " << i+1 << ":" << it.second[i];
		ofs << std::endl;
	}
	ofs.close();
}

#endif