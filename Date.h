#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int d;
	int m;
	int y;
public:
	Date();
	Date(int d, int m, int y);
	static bool KTNhuan(int y);
	static int SoNgay(int m, int y);
	int NgayThu();
	int CachNgay(Date d1);
};
#endif // !DATE_H