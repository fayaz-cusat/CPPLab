#include <iostream>

class Time
{
    int hours, minutes, seconds;

public:
    Time()
    {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    Time(int t)
    {
        hours = t / 3600;
        t %= 3600;
        minutes = t / 60;
        t %= 60;
        seconds = t;
    }
    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    friend Time add_time(Time t1, Time t2);
};

Time add_time(Time t1, Time t2)
{
    Time t3;
    t3.seconds += t1.seconds + t2.seconds;
    if (t3.seconds >= 60)
    {
        t3.seconds -= 60;
        t3.minutes++;
    }

    t3.minutes += t1.minutes + t2.minutes;
    if (t3.minutes >= 60)
    {
        t3.minutes -= 60;
        t3.hours++;
    }

    t3.hours += t1.hours + t2.hours;

    std::cout << "Hours: " << t3.hours << ", ";
    std::cout << "Minutes: " << t3.minutes << ", ";
    std::cout << "Seconds: " << t3.seconds;

    return t3;
}

int main()
{
    Time t1(10, 59, 59);
    Time t2(2, 0, 1);

    add_time(t1, t2);
}
