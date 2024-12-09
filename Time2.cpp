#include "Time2.h"

Time2 Time2::operator-(int s)
{
	Time2 t;
	t.h = this->h;
	t.m = this->m;
	t.s = this->s - s;
	while (t.s < 0)
	{
		t.s += 60;
		t.m--;
	}
	while (t.m < 0)
	{
		t.m += 60;
		t.h--;
	}
	while (t.h < 0)
	{
		t.h += 24;
	}
	return t;
}

bool Time2::operator>(Time2 t2)
{
	if (this->h > t2.h) return true;
	else if (this->h < t2.h) return false;
	else
	{
		if (this->m > t2.m) return true;
		else if (this->m < t2.m) return false;
		else
		{
			if (this->s > t2.s) return true;
			else return false;
		}
	}
}

bool Time2::operator<(Time2 t2)
{
	if (this->h < t2.h) return true;
	else if (this->h > t2.h) return false;
	else
	{
		if (this->m < t2.m) return true;
		else if (this->m > t2.m) return false;
		else
		{
			if (this->s < t2.s) return true;
			else return false;
		}
	}
}

bool Time2::operator==(Time2 t2)
{
	if (this->h == t2.h && this->m == t2.m && this->s == t2.s) return true;
	else return false;
}