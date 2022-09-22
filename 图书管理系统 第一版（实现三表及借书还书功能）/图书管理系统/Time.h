#include<iostream>
#include<time.h>
using namespace std;
class Time {
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
public:
	Time() {
		tm tm = now();
		this->year = tm.tm_year + 1900;
		this->month = tm.tm_mon + 1;
		this->day = tm.tm_mday;
		this->hour = tm.tm_hour;
		this->minute = tm.tm_min;
		this->second = tm.tm_sec;
	}

	string toString() {
		char str[32];
		snprintf(str, sizeof(str), "%04d-%02d-%02d %02d:%02d:%02d", year, month, day, hour, minute, second);
		return str;
	}
	static tm now() {
		time_t t = time(0);
		struct tm tm;
		localtime_s(&tm, &t);
		return tm;
	}
};