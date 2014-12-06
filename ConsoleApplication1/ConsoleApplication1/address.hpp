#ifndef ADDRESS
#define ADDRESS

#include <string>
#include <iostream>
#include <vector>

const std::vector<std::string> Province =
{
	"�ӱ�ʡ",
	"����ʡ",
	"����ʡ",
	"����ʡ",
	"������ʡ",
	"����ʡ",
	"�㽭ʡ",
	"����ʡ",
	"����ʡ",
	"����ʡ",
	"ɽ��ʡ",
	"����ʡ",
	"����ʡ",
	"����ʡ",
	"�Ĵ�ʡ",
	"����ʡ",
	"����ʡ",
	"����ʡ",
	"����ʡ",
	"�ຣʡ",
	"̨��ʡ",
	"������",
	"�����",
	"�Ϻ���",
	"������",
	"��������������",
	"���ɹ�������",
	"����������",
	"���Ļ���������",
	"�½�ά�����������",
	"����ر�������",
	"�����ر�������"
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