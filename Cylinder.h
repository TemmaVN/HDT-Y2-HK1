#ifndef CYLINDER_H
#define CYLINDER_H
#include"Library.h"

const double pi = 3.14;

class Cylinder
{
private:
	double r;
	double h;
public:
	Cylinder();
	Cylinder(double r,double h);
	double Stp();
	double Vht();
};


#endif // !CYLINDER_H