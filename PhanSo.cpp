#include "PhanSo.h"

PhanSo::PhanSo()
{
	this->tu = 0;
	this->mau = 1;
}

PhanSo::PhanSo(int tu, int mau)
{
	if (mau == 0)
	{
		this->tu = 0;
		this->mau = 1;
	}
	else
	{
		this->tu = tu;
		this->mau = mau;
	}
}

void PhanSo::RutGon()
{
	int a = this->tu;
	int b = this->mau;
	while (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
	}
	this->mau /= a;
	this->tu /= a;
}

PhanSo operator+(PhanSo ps1, PhanSo ps2)
{
	PhanSo ps;
	ps.tu = ps1.tu * ps2.mau + ps1.mau * ps2.tu;
	ps.mau = ps1.mau * ps2.mau;
	return ps;
}

PhanSo operator-(PhanSo ps2)
{
	PhanSo ps;
	ps.tu = -ps2.tu;
	ps.mau = ps2.mau;
	return ps;
}

PhanSo operator*(PhanSo ps1, PhanSo ps2)
{
	PhanSo ps;
	ps.tu = ps1.tu * ps2.tu;
	ps.mau = ps1.mau * ps2.mau;
	return ps;
}

PhanSo operator/(PhanSo ps1, PhanSo ps2)
{
	PhanSo ps;
	ps.tu = ps1.tu * ps2.mau;
	ps.mau = ps1.mau * ps2.tu;
	return ps;
}

istream& operator>>(istream& i, PhanSo &ps1)
{
	cout << "Nhap phan so : " << endl;
	cout << "Tu so la : ";
	i >> ps1.tu;
	cout << "Mau so la :";
	i >> ps1.mau;
	if (ps1.mau == 0)
	{
		cout << "Nhap lai : ";
		i >> ps1.mau;

	}
	return i;
}

ostream& operator<<(ostream& o, PhanSo ps1)
{
	cout << ps1.tu << '/' << ps1.mau;
	return o;
}

void PhanSo::CongSN(int d)
{
	d *= this->mau;
	this->tu += d;
}
