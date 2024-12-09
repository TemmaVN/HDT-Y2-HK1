#ifndef PHANSO_H
#define PHANSO_H
#include"Library.h"

class PhanSo
{
private:
	int tu;
	int mau;
public:
	PhanSo();
	PhanSo(int tu, int mau);
	friend PhanSo operator+(PhanSo ps1, PhanSo ps2);
	friend PhanSo operator*(PhanSo ps1,PhanSo ps2);
	friend PhanSo operator-(PhanSo ps1);
	friend PhanSo operator/(PhanSo ps1, PhanSo ps2);
	friend istream& operator>>(istream& i, PhanSo &ps1);
	friend ostream& operator<<(ostream& o, PhanSo ps1);
	void RutGon();
	void CongSN(int n);
};

#endif // !PHANSO_H