#ifndef DATE_TYPE
#define DATE_TYPE

#include <ctime>

/*
class date{
private:
	time_t timer;
public:
	date()
	{
		timer = 0;
	}
	date(const date& t)
	{
		timer = t.timer;
	}
	void set_date(const date&t)
	{
		timer = t.timer;
	}
	void set_date(int year, int month, int day)
	{
		struct tm *timeinfo;
		timeinfo = new(struct tm);
		memset((void *)timeinfo, 0, sizeof(tm));
		timeinfo->tm_year = year;
		timeinfo->tm_mon = month;
		timeinfo->tm_mday = day;
		timer = mktime(timeinfo);
		delete timeinfo;
	}
	int year() const
	{
		struct tm * timeinfo;
		gmtime_s(timeinfo,&timer);
		return timeinfo->tm_year;
	}
	int month() const
	{
		struct tm * timeinfo;
		gmtime_s(timeinfo, &timer);
		return timeinfo->tm_mon;
	}

	int day() const
	{
		struct tm * timeinfo;
		gmtime_s(timeinfo, &timer);
		return timeinfo->tm_mday;
	}

	int operator -(date t)
	{
		return (double)timer - t.timer;
	}
	friend bool operator != (const date a, const date b)
	{
		return a.timer != b.timer;
	}
	friend bool operator < (const date a, const date b)
	{
		return a.timer < b.timer;
	}
};

*/
const int mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

class date
{
private:
	int time;
public:

	int day_of_year(int year)
	{
		if (year % 400 == 0) return 366;
		if (year % 100 == 0) return 365;
		if (year % 4 == 0) return 366;
		return 365;
	}

	int day_of_month(int year,int month)
	{
		if (month != 1) return mdays[month];
		if (day_of_year(year) == 366) return 29;
		return 28;
	}

	int date2time(int year, int month, int day)
	{
		int res = 0;
		for (int i = 1990; i < year; ++i)
			res += day_of_year(i);
		for (int i = 0; i < month-1; ++i)
			res += day_of_month(year, i);
		res += day - 1;
		return res;
	}
	void set_date(int year, int month, int day)
	{
		time = date2time(year, month, day);
	}
	void get_date(int &year, int&month, int &day)
	{
		int sum = 0;
		year = 1990; month = 0; day = 0;
		while (sum + day_of_year(year) < time)
		{
			sum += day_of_year(year);
			++year;
		}
		while (sum + day_of_month(year, month) < time)
		{
			sum += day_of_month(year, month);
			++month;
		}
		++month;
		day = time - sum + 1;
	}
	int get_time() const
	{
		return time;
	}
	int operator -(date t)
	{
		return time - t.time;
	}
	friend bool operator != (const date a, const date b)
	{
		return a.time != b.time;
	}
	friend bool operator < (const date a, const date b)
	{
		return a.time < b.time;
	}
};

class date_v :public date
{
private:
	bool vailed;
public:
	bool isVailed() const
	{
		return vailed;
	}
	void setVailed(bool flag = true)
	{
		vailed = flag;
	}
};

#endif 