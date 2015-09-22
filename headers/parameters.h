#ifndef DEF_PARAMETERS
#define DEF_PARAMETERS

#include <string>
#include <vector>
#include <valarray>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;//pas bien

double const G(1.), c(1.);
double const timestep(pow(10,-1));

string const savedirectory("save/");

//int const maxx(5*pow(10,7)), maxv(1000), maxm(30000);
int const maxx(50), maxv(400), maxm(5000);
double const RANGEX(pow(10,1./2)), RANGEV(pow(10,-5)), RANGEM(pow(10,-10));


const double asterdensity(5.);
bool const fuseatcollision(1);
double const seuil(2.5);//temporaire, distance en dessous de laquelle on fusionne deux particules

double const maxtime = 3*pow(10,6);

//printing parameters 
int const PRINT_PREC(3),PRINT_WIDTH(7+PRINT_PREC+4);
#endif
