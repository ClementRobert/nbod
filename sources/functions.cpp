#include "functions.h"

using namespace std;

double dot(valarray<double> a, valarray<double> b){
    int n(a.size()), i(0);
    double prod(0.);
    for(i=0 ; i<n ; i++){
        prod += a[i]*b[i];
    }
return prod;
}

valarray<double> cross(valarray<double> a, valarray<double> b){
    int n(a.size()), i(0);
    valarray<double> prod(0.,3);
    prod[0] = a[1]*b[2] - a[2]*b[1];
    prod[1] = a[2]*b[0] - a[0]*b[2];
    prod[2] = a[0]*b[1] - a[1]*b[0];//implémentation bourine au possible
    return prod;
}


string intToString(int i) {
     std::ostringstream oss;
     oss << i;
     return oss.str();
}
