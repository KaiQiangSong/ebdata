#ifndef ANALYSIS
#define ANALYSIS


#include <cstdlib>
#include <iostream>
#include <algorithm>
#include "statistics.hpp"
#include "utility.hpp"

/*
double mark(std::vector<int> id, vec_d feat)
{
	std::vector<int> pid, nid;
	vec_d pfeat, nfeat;
	size_t len = id.size();
	for (size_t i = 0; i < len; ++i)
		if (Label[id[i]] == 1)
		{
			pid.push_back(id[i]);
			pfeat.push_back(feat[i]);
		}
		else
		{
			nid.push_back(id[i]);
			nfeat.push_back(feat[i]);
		}
	double pavg = get_avg(pfeat);
	double navg = get_avg(nfeat);
	double ps = get_StandardDeviation(pfeat);
	double ns = get_StandardDeviation(nfeat);
	double x0;
	if (fabs(ps - ns) > EPS)
	{
		x0 = (ps * navg - ns * pavg) / (ps - ns);
		return fabs(pavg - x0) / ps + fabs(navg - x0) / ns;
	}
	return 0;
}
*/



void qsort(int left, int right, vec_i &id, vec_d & feat)
{
	double value = feat[(left + right) / 2];
	int i = left, j = right;
	while (i <= j)
	{
		while (feat[i] < value) ++i;
		while (feat[j] > value) --j;
		if (i <= j)
		{
			Swap(feat[i], feat[j]);
			Swap(id[i], id[j]);
			++i; --j;
		}
	}
	if (left < j) qsort(left, j, id, feat);
	if (i < right) qsort(i, right, id, feat);
}

std::pair<double,int> find_threshold(vec_i id, vec_d feat,int RECALL_MIN, double &mark)
{
	size_t len = feat.size();
	if (len < 1) return std::make_pair(0,0);
	/*
	std::ofstream ofs("error.txt");
	for (size_t i = 0; i < len; ++i)
	{
		ofs << id[i] << " : " << feat[i] << std::endl;
	}
	ofs.close();
	*/
	//std::cout << len << " " << id.size() << std::endl;
	qsort(0, len - 1, id, feat);
	/*for (size_t i = 0; i < len; ++i)
	{
		std::cout << id[i] << " : " << feat[i] << std::endl;
		system("pause");
	}
	*/
	vec_i left_pos(len),right_pos(len);
	left_pos[0] = Label[id[0]];
	for (size_t i = 1; i < len; ++i)
	{
		left_pos[i] = left_pos[i - 1] + Label[id[i]];
		//std::cout << id[i] << " : " << left_pos[i] << std::endl;
	}
	right_pos[len - 1] = Label[id[len - 1]];
	for (int i = len - 2; i >= 0; --i)
	{
		right_pos[i] = right_pos[i + 1] + Label[id[i]];
		//std::cout << id[i] << " : " << right_pos[i] << std::endl;
	}
	int num_pos = left_pos[len - 1];
	int num_neg = len - num_pos;
	//std::cout << num_pos << " " << num_neg << std::endl;
	int tp, fp, tn, fn;
	double P, R;
	double MaxP = 0;
	double threshold = 0;
	int flag = 0;
	for (size_t i = 0; i < len; ++i)
		if (i == 0 || i > 0 && fabs(feat[i] - feat[i-1]) > EPS )
		{
			// Let Left be positive
			tp = left_pos[i];
			fp = num_pos - tp;
			fn = i + 1 - tp;
			tn = num_neg - fn;
			P = tp / (double)(i + 1);
			R = tp / (double) num_pos;
			//std::cout << i << " " << tp << std::endl;
			if (R > RECALL_MIN / (double)num_pos)
			{
				if (P > MaxP)
				{
					MaxP = P;
					threshold = feat[i];
					flag = NEG;
				}
			}
			//std::cout << i << " : " << tp << " " << P << " " << R << std::endl;
		}
	for (int i = len - 1; i >= 0;--i)
		if (i == len - 1 || i < len - 1 && fabs(feat[i+1] - feat[i]) > EPS)
		{
			// Let Right be positive
			tp = right_pos[i];
			fp = num_pos - tp;
			fn = len - i - tp;
			tn = num_neg - fn;
			P = tp / (double)(len - i);
			R = tp / (double) num_pos;
			//std::cout << len-i << " " << tp << std::endl;
			if (R > RECALL_MIN / (double)num_pos)
			{
				if (P > MaxP)
				{
					MaxP = P;
					threshold = feat[i];
					flag = POS;
				}
			}
			//std::cout << i << " : " << tp << " " << P << " " << R << std::endl;
			//std::cout << MaxP << " " << threshold << " " << flag << std::endl;
			//system("pause");
		}
	mark = MaxP;
	return std::make_pair(threshold, flag);
}

double mark(vec_i id, vec_d feat, int RECALL_MIN)
{
	double res;
	find_threshold(id, feat, RECALL_MIN, res);
	return res;
}

#endif