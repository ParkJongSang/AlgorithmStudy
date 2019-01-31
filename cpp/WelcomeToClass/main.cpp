#include <iostream>

using namespace std;

class Date{
    int year;
    int month;
    int day;

public:
    void setDate(int _year, int _month, int _day);
    void addDay(int inc);
    void addMonth(int inc);
    void addYear(int inc);
    void showDate();
};

void Date::setDate(int _year, int _month, int _day) {
    year = _year;
    month = _month;
    day = _day;
}

void Date::addDay(int inc) {
    int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int i = month;

    if(month_day[i-1] - day >= inc){
        day += inc;
        return;
    }else{
        addMonth(1);
        day = 1;

        inc = inc - (month_day[i-1] - day) - 1;
        i++;
    }

    while(true){
        if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
            month_day[1] = 29;
        } else{
            month_day[1] = 28;
        }

        if(inc - month_day[i-1] >= 0){
            addMonth(1);
            inc = inc - month_day[i-1];
        }else if(inc - month_day[i-1] < 0){
            day = day + inc;
            break;
        }

        i++;
        if(i > 12) i = i - 12;
    }
}

void Date::addMonth(int inc) {
    addYear((inc + month - 1) / 12);
    month = month + inc % 12;
    month = (month == 12 ? 12 : month % 12);
}

void Date::addYear(int inc) {
    year += inc;
}

void Date::showDate() {
    cout << "오늘은 " << year << " 년 " << month << "월" << day << "일 입니다." << endl;
}

int main() {
    Date day;
    day.setDate(2011, 3, 1);
    day.showDate();

    day.addYear(10);
    day.showDate();
    return 0;
}