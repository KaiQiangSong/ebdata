#include <cmath>
#include <cstring>
#include "location.hpp"

#ifndef PI
#define PI 3.14159265
#endif


static double Re = 6378137;//equator
static double Rp = 6356725;//poles

location::location()
{
	memset(this, 0, sizeof(location));
}

location::location(double lati, double logi)
{
	latitude = lati;
	logitude = logi;
}

location::location(const location& x)
{
	memcpy(this, &x, sizeof(location));
}

location& location::operator=(const location& x)
{
	memcpy(this, &x, sizeof(location));
	return *this;
}


bool operator<(location x, location y)
{
	if (x.latitude < y.latitude) return true;
	if (x.latitude > y.latitude) return false;
	if (x.logitude < y.logitude) return true;
	if (x.logitude > y.logitude) return false;
	return false;
}


double dist2(location a, location b)
{
	return sqrt(pow(a.latitude - b.latitude, 2) + pow(a.logitude - b.logitude, 2));
}

double dist_global(location a, location b)
{
	double a_Radian_Latitude = a.get_latitude() * PI / 180;
	double a_Radian_Logitude = a.get_logitude() * PI / 180;
	double a_Ec = Rp + (Re - Rp) * (90 - a.get_latitude()) / 90;
	double a_Ed = a_Ec * cos(a_Radian_Latitude);


	double b_Radian_Latitude = b.get_latitude() * PI / 180;
	double b_Radian_Logitude = b.get_logitude() * PI / 180;
	double b_Ec = Rp + (Re - Rp) * (90 - b.get_latitude()) / 90;
	double b_Ed = b_Ec * cos(b_Radian_Latitude);

	double dx = (b_Radian_Logitude - a_Radian_Logitude) * a_Ed;
	double dy = (b_Radian_Latitude - a_Radian_Latitude) * a_Ec;
	return sqrt(dx * dx + dy * dy);
}