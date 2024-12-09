#include "HinhHoc.h"

Diem::Diem()
{
	this->x = 0;
	this->y = 0;
}

Diem::Diem(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Diem::KCach(Diem d2)
{
	double a = this->x - d2.x;
	double b = this->y - d2.y;
	return sqrt(a * a + b * b);
}

TuGiac::TuGiac()
{
	
}

TuGiac::TuGiac(Diem d[4])
{
	this->d[0] = d[0];
	this->d[1] = d[1];
	this->d[2] = d[2];
	this->d[3] = d[3];
}

void TuGiac::NhapDinh()
{
	cout << "Nhap dinh cua tu giac : " << endl;
	for (int i = 0;i < 4;i++)
	{
		double a, b;
		cout << "Nhap dinh thu " << i + 1 << endl;
		cout << "x = "; cin >> a;
		cout << "y = "; cin >> b;
		Diem dn(a, b);
		d[i] = dn;
	}
}

double TuGiac::C()
{
	double a = this->d[0].KCach(d[1]);
	double q = this->d[1].KCach(d[2]);
	double w = this->d[2].KCach(d[3]);
	double e = this->d[3].KCach(d[0]);
	return a + q + w + e;
}

double TuGiac::S()
{
	double a = this->d[0].KCach(d[1]);
	double q = this->d[1].KCach(d[2]);
	double ch = this->d[0].KCach(d[2]);
	double w = this->d[2].KCach(d[3]);
	double e = this->d[3].KCach(d[0]);
	double p1 = (a + q + ch) / 2;
	double p2 = (ch + w + e) / 2;
	double S1 = sqrt(p1 * (p1 - a) * (p1 - q) * (p1 - ch));
	double S2 = sqrt(p2 * (p2 - ch) * (p2 - w) * (p2 - e));
	return S1 + S2;
}
