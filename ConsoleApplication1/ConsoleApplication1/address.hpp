#ifndef ADDRESS
#define ADDRESS

#include <string>
#include <iostream>
#include <vector>

const std::vector<std::string> Province =
{
	"河北省",
	"陕西省",
	"辽宁省",
	"吉林省",
	"黑龙江省",
	"江苏省",
	"浙江省",
	"安徽省",
	"福建省",
	"江西省",
	"山东省",
	"河南省",
	"湖北省",
	"湖南省",
	"四川省",
	"贵州省",
	"云南省",
	"陕西省",
	"甘肃省",
	"青海省",
	"台湾省",
	"北京市",
	"天津市",
	"上海市",
	"重庆市",
	"广西藏族自治区",
	"内蒙古自治区",
	"西藏自治区",
	"宁夏回族自治区",
	"新疆维吾尔族自治区",
	"香港特别行政区",
	"澳门特别行政区"
};

class address
{
public:
	std::string whole;
	bool vailed;
public:
	void setVailed(bool v = true)
	{
		vailed = v;
	}
	bool isVailed() const
	{
		return vailed;
	}
	int get_province() const
	{
		if (!isVailed()) return 0;
		size_t len = Province.size();
		for (size_t i = 0; i < len; ++i)
			if (whole.find(Province[i]) != Province.size())
				return i+1;
		return 0;
	}
};

#endif