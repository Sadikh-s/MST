#include "point.hpp"
#include <iostream>
#include <cassert>
#include <cmath>	// for sqrt, fabs
#include <cfloat>	// for DBL_MAX
#include <cstdlib>	// for rand, srand
#include <ctime>	// for rand seed
#include <fstream>
#include <cstdio>	// for EOF
#include <string>
#include <algorithm>	// for count
#include <vector>
 int point::get_dim(){
    return d;
}
 bool point::set_dim(int _d){
    if(d==-1){d=_d; return true;}
    else return false;
}
point::point(){
		coords = new double[d];
		for(int m = 0; m < d; m++)
			coords[m] = 0.0;
		label = 0;
}
point::~point()
{
    delete[] coords;
}
void point::print()
{
    std::cout << coords[0];

    for (int j = 1; j < d; j++)
        std::cout << '\t' << coords[j];

    std::cout << std::endl;
}
double point::dist(point &q)
{
    double sqd = 0.0;

    for (int m = 0; m < d; m++)
        sqd += (coords[m]-q.coords[m]) * (coords[m]-q.coords[m]);

    return sqrt(sqd);
}

int point::d =-1;