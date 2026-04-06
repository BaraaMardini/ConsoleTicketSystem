#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

class ClsDate
{
private:
    short _Day = 1;
    short _Month = 1;
    short _Year = 1900;
    string _TimeNow;

public:


    ClsDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        _Day = now->tm_mday;
        _Month = now->tm_mon + 1;
        _Year = now->tm_year + 1900;

        char buffer[20];
        strftime(buffer, sizeof(buffer), "%H:%M:%S", now);
        _TimeNow = buffer;
    }


    ClsDate(short Day, short Month, short Year, string TimeNow)
    {
        _Day = Day;
        _Month = Month;
        _Year = Year;
        _TimeNow = TimeNow;
    }


    static ClsDate GetSystemDate()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        char buffer[20];
        strftime(buffer, sizeof(buffer), "%H:%M:%S", now);

        return ClsDate(
            now->tm_mday,
            now->tm_mon + 1,
            now->tm_year + 1900,
            buffer
        );
    }


    string GetSystemDateTimeString()
    {
        time_t t = time(0);
        tm* now = localtime(&t);

        char buffer[50];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", now);

        return string(buffer);
    }
};