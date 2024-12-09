#include "Date.h"

Date::Date()
{
	this->d = 1;
	this->m = 1;
	this->y = 1;
}

Date::Date(int d, int m, int y)
{
	if (d < 1) d = 1;
	switch (m)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d > 31) this->d = 1;
			else this->d = d;
			this->m = m;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (d > 30) this->d = 1;
			else this->d = d;
			this->m = m;
			break;
		case 2:
			if ((y%4==0&&y%100!=0)||y%400==0)
			{
				if (d > 29) this->d = 1;
				else this->d = d;
				this->m = m;
				break;
			}
			if (d > 28) this->d = 1;
			else this->d = d;
			this->m = m;
			break;
		default:
			this->d = 1;
			this->m = 1;
			break;
		}
	this->y = y;
}

bool Date::KTNhuan(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::SoNgay(int m, int y)
{
	if (m < 1 || m>12) return 0;
	switch (m)
	{
	case 2:
		if ((m % 4 == 0 && m % 100 != 0) || m % 400 == 0) return 29;
		else return 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	default:
		return 31;
		break;
	}
}

int Date::CachNgay(Date d1)
{
	int y1 = this->y;
	int y2 = d1.y;
	int kq = this->NgayThu() - d1.NgayThu();
	kq = (y1 >= y2) ? kq : -kq;
	while (y1 != y2)
	{
		if (y1 > y2)
		{
			if (((y1-1) % 4 == 0 && (y1-1) % 100 != 0) || (y1-1) % 400 == 0) kq += 366;
			else kq += 365;
			y1--;
		}
		else
		{
			if (((y2-1) % 4 == 0 && (y2-1) % 100 != 0) || (y2-1) % 400 == 0) kq += 366;
			else kq += 365;
			y2--;
		}
	}
	kq = (kq >= 0) ? kq : -kq;
	return kq - 1;
}

int Date::NgayThu()
{
	int m = this->m;
	int d = this->d;
	while (m > 1)
	{
		switch (m-1)
		{
		case 2:
			if ((this->y % 4 == 0 && this->y % 100 != 0) || this->y % 400 == 0) d+=29;
			else d+=28;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			d+=30;
			break;
		default:
			d+=31;
			break;
		}
		m--;
	}
	return d;
}