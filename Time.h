#ifndef TIME_H
#define TIME_H

#include"Library.h"

class Time
{
protected:
	int h;
	int m;
	int s;
public:
	Time();
	Time(int h, int m, int s);
	friend istream& operator>>(istream& i, Time& t1);
	friend ostream& operator<<(ostream& o, Time t1);
	Time operator+(int s);
	Time &operator++();
	Time &operator--();
};

#endif // !TIME_H