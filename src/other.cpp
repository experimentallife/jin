#include "../include/basic.h"

std::string convertSecondsToMinutes(float time)
{
	int total, seconds, minutes;
	std::ostringstream ss;
	total = static_cast<int>(std::round(time));
	minutes = total / 60;
	seconds = total % 60;
	ss << minutes << ":" << seconds;
	return ss.str();
}


std::string convertIntToString(int number)
{
	std::ostringstream ss;
	ss << number;
	return ss.str();
}