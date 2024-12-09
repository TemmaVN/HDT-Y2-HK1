#include "Cylinder.h"

Cylinder::Cylinder()
{
	this->h = 0;
	this->r = 0;
}

Cylinder::Cylinder(double r, double h)
{
	this->r = r;
	this->h = h;
}

double Cylinder::Stp()
{
	double Sday = this->r * this->r * pi;
	double Sben = 2 * this->r * this->h * pi;
	return Sday * 2 + Sben;
}

double Cylinder::Vht()
{
	return (this->r * this->r * this->h * pi);
}
