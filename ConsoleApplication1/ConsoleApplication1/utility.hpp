#ifndef UTILITY_SKQ
#define UTILITY_SKQ

//#define TRAIN
#define TEST

//#define RECALL_MIN (100)

#define Min(a,b) ((a) < (b) ? (a) : (b))
#define Max(a,b) ((a) > (b) ? (a) : (b))

#define POS (+1)
#define NEG (-1)


#include <iostream>
#include <string>
#include <vector>

#include "date.hpp"
#include "location.hpp"
#include "address.hpp"


std::string getline(std::istream& ifs);
std::string formu(std::string s);

void Swap(int &x, int &y);
void Swap(double &x, double &y);


#endif