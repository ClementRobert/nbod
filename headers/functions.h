#ifndef FUNCTIONS
#define FUNCTIONS

#include <valarray>
#include <string>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace std;

double dot(valarray<double> a, valarray<double> b);
valarray<double> cross(valarray<double> a, valarray<double> b);
string intToString(int i);
#endif
