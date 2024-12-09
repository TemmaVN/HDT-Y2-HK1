#include "SoNguyen.h"

SoNguyen::SoNguyen()
{
	this->d = 0;
}

SoNguyen::SoNguyen(long long d) 
{
	this->d = d;
}

void SoNguyen::Nhap()
{
	cout << "So nguyen la : ";
	cin >> this->d;
}

bool SoNguyen::KTSoNT()
{
	long long q = sqrt(this->d);
	if (this->d % 2 == 0) return false;
	else
	{
		for (long long i = 3;i < q;i += 2)
		{
			if (this->d % i == 0) return false;
		}
	}
	return true;
}

bool SoNguyen::KTSoDX()
{
	vector<int> k;
	long long d = this->d;
	while (d > 0)
	{
		k.push_back(d % 10);
		d /= 10;
	}
	for (int i = 0;i < k.size();i++)
	{
		if (k[i] != k[k.size() - 1 - i]) return false;
	}
	return true;
}
