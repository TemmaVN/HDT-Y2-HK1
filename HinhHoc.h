#ifndef HINHHOC_H
#define HINHHOC_H
#include"Library.h"

class Diem
{
private:
	double x;
	double y;
public:
	Diem();
	Diem(double x, double y);
	double KCach(Diem d2);
};

class HinhHoc
{
public:
	virtual double C() { return 0; }
	virtual double S() { return 0; }
};

class TuGiac : public HinhHoc
{
private:
	Diem d[4];
public:
	TuGiac();
	TuGiac(Diem d[4]);
	void NhapDinh();
	double C();
	double S();
};


#endif // !HINHHOC_H