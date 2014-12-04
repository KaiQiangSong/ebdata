#ifndef LOCATION
#define LOCATION

#ifndef BASE
#define BASE 10000
#endif

class location
{
public:
	double latitude, logitude;
public:
	location();
	location(double lati, double logi);
	location::location(const location& x);
	location& operator=(const location& x);
	double get_latitude() const
	{
		return latitude;
	}
	double get_logitude() const
	{
		return logitude;
	}

	friend bool operator<(location x, location y);
	friend double dist2(location a, location b);
	friend double dist_global(location a, location b);
};


#endif