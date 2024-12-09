#include "Time.h"

Time::Time()
{
	this->h = 0;
	this->m = 0;
	this->s = 0;
}

Time::Time(int h, int m, int s)
{
	this->h = h;
	this->m = m;
	this->s = s;
}

istream& operator>>(istream& i, Time& t1)
{
	cout << "Hay nhap theo kieu h:m:s : ";
	cout << "Gio la : ";i >> t1.h;
	while (t1.h < 0 || t1.h >= 24)
	{
		cout << "Nhap lai gio : ";
		i >> t1.h;
	}
	cout << "Phut la : ";
	i >> t1.m;
	while (t1.m < 0 || t1.m >= 60)
	{
		cout << "Nhap lai phut : ";
		i >> t1.m;
	}
	cout << "Giay la : ";
	i >> t1.s;
	while (t1.s < 0 || t1.s >= 60)
	{
		cout << "Nhap lai giay : ";
		i >> t1.s;
	}
	return i;
}

ostream& operator<<(ostream& o, Time t1)
{
	o << "Thoi gian hien tai la : " << t1.h << ':' << t1.m << ':' << t1.s;
	return o;
}

Time Time::operator+(int s)
{
	Time t1;
	t1.s = this->s + s;
	t1.m = this->m;
	t1.h = this->h;
	while (t1.s >= 60)
	{
		t1.s -= 60;
		t1.m++;
	}
	while (t1.m >= 60)
	{
		t1.m -= 60;
		t1.h++;
	}
	while (t1.h >= 24)
	{
		t1.h -= 24;
	}
	return t1;
}

Time &Time::operator++()
{
	this->s++;
	if (this->s >= 60)
	{
		this->s -= 60;
		this->m++;
	}
	if (this->m >= 60)
	{
		this->m -= 60;
		this->h++;
	}
	if (this->h >= 24)
	{
		this->h -= 24;
	}
	return *this;
}

Time &Time::operator--()
{
	this->s--;
	if (this->s < 0)
	{
		this->s += 60;
		this->m--;
	}
	if (this->m < 0)
	{
		this->m += 60;
		this->h--;
	}
	if (this->h<0)
	{
		this->h += 24;
	}
	return *this;
}