#ifndef SONGUYEN_H
#define SONGUYEN_H
#include"Library.h"

class SoNguyen
{
private:
	long long int d;
public:
	SoNguyen();
	SoNguyen(long long d);
	void Nhap();
	bool KTSoNT();
	bool KTSoDX();
};

#endif // !SONGUYEN_H