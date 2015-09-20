#ifndef DEF_PARAMETERS
#define DEF_PARAMETERS


#include <string>
#include <vector>
#include <valarray>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

double const G(1.), c(1.);
double const timestep(pow(10,-1)); //audace, panache...

string const savedirectory("save/");

//int const maxx(5*pow(10,7)), maxv(1000), maxm(30000);
int const maxx(100), maxv(400), maxm(10);
double const RANGEX(pow(10,0)), RANGEV(pow(10,-5)), RANGEM(pow(10,-8));


const double asterdensity(5.);
bool const fuseatcollision(1);
double const seuil(2.5);//temporaire, distance en dessous de laquelle on fusionne deux particules


double const maxtime = 3*pow(10,6);
#endif
