#ifndef ANALYSIS
#define ANALYSIS

#include "statistics.hpp"

double mark(std::vector<int> id, vec feat)
{
	std::vector<int> pid, nid;
	vec pfeat, nfeat;
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

#endif