#ifndef TIME2_H
#define TIME2_H
#include"Time.h"

class Time2:public Time 
{
public:
	Time2 operator-(int s);
	bool operator==(Time2 t2);
	bool operator>(Time2 t2);
	bool operator<(Time2 t2);
};

#endif // !TIME2_H