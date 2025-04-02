#include <iostream>
#include "../include/Time.h"
using namespace std;

// Overload the + operator
Time Time::operator+(const Time &other) const
{   
    int totalMinutes = minutes + other.getMinutes();
    int newHours = totalMinutes / 60;
    int newMinutes = totalMinutes % 60;
    int totalHours = (hours + other.getHours()) + newHours;
    return Time(totalHours, newMinutes);
}

// Overload the += operator
Time& Time::operator+=(const Time &other)
{   
    *this = *this + other;
    return *this;
}

// Overload the < operator
bool Time::operator<(const Time &other) const
{   

    if (hours < other.getHours()) return true;
    else if (hours == other.getHours()) {
        if (minutes < other.getMinutes()) return true;
    }
    else return false;
}

// Overload the > operator
bool Time::operator>(const Time &other) const
{
    if (hours > other.getHours()) return true;
    else if (hours == other.getHours()) {
        if (minutes > other.getMinutes()) return true;
    }
    else return false;
}

// Overload the == operator
bool Time::operator==(const Time &other) const
{
    return (this->hours == other.getHours()) && (this->minutes == other.getMinutes());
}

// Overload the friend function operator<<
ostream &operator<<(ostream &os, const Time &tm)
{
    return os << tm.getHours() << ":" << tm.getMinutes();
}
