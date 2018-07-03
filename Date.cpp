#include<iostream>
using namespace std;
class Date {
public:
  Date(int y, int m, int d);
  ~Date();

  void nextDay(int y, int m, int d);
  void previousDay(int y, int m, int d);
  bool equal(Date other);
  void show();
private:
  int year;
  int month;
  int day;
};
Date::Date(int y, int m, int d)
{
  year=y;
  month=m;
  day=d;
}
void Date::nextDay(int y, int m, int d)
{
  year=y;
  month=m;
  day=d+1;
}
void Date::previousDay(int y, int m, int d)
{
  year=y;
  month=m;
  day=d-1;
}
class Date
{
public:
    Date(int year = 1900,int month = 1,int day = 1);
    ~Date(){}
    bool IsValid();
    int GetMonthDay(int year,int month);
    bool IsLeapYear(int year);
    void Show();
 
    Date& operator=(const Date& d);
    Date operator+(int day);
    Date& operator+=(int day);
    Date operator-(int day);
    Date& operator-=(int day);
    int operator-(const Date& d);//日期-日期 返回天数
    Date& operator++();//默认前置
    Date operator++(int);//用参数标志后置++
    Date& operator--();
    Date operator--(int);
 
private:
    int _year;
    int _month;
    int _day;
};
Date::Date(int year,int month,int day):_year(year),_month(month),_day(day)
{
    if(!IsValid())  // -> this.IsValid()
    {
        assert(false);
    }
}
 
bool Date::IsValid()
{
    return (_year > 0 
       && _month > 0 && _month <= 12 
       &&_day > 0 && _day <= GetMonthDay(_year,_month));
}
 
int Date::GetMonthDay(int year,int month)
{
    int arr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(month == 2 && IsLeapYear(year))
    {
        ++arr[2];
    }
    return arr[month];
}
 
bool Date::IsLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0)
        || year % 400 == 0);
}
 
void Date::Show()
{
    cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
}
 

bool Date::operator==(const Date& d)
{
    if(_year == d._year && _month == d._month && _day == d._day)
        return true;
    return false;
}
Date& Date::operator=(const Date& d)
{
    if(this != &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    return *this;
}
 
bool Date::operator>=(const Date& d)
{
    return !(*this < d);
}
 
bool Date::operator<=(const Date& d)
{
    return ((*this < d) || (*this == d));
}
bool Date::operator!=(const Date& d)
{
    return !(*this == d);
}
 
bool Date::operator>(const Date& d)
{
    return !(*this <= d);
}
 
bool Date::operator<(const Date& d)
{
    if((_year < d._year) ||
       (_year == d._year && _month < d._month) ||
       (_year == d._year && _month == d._month && _day < d._day))
        return true;
    return false;
}
 
Date Date::operator+(int day)
{
    if(day < 0)
    {
        return (*this) - (-day);
    }
    Date d(*this);
    d._day += day;
    while(d.IsValid() == false)
    {
        int month_day = GetMonthDay(d._year,d._month);
        d._day -= month_day;
        ++d._month;
        if(d._month > 12)
        {
            d._month = 1;
            ++d._year;
        }
    }
    return d;
}
 
Date& Date::operator+=(int day)
{
    *this = (*this + day);
    return *this;
}
 
Date Date::operator-(int day)
{
    if(day < 0)
    {
        return (*this) + (-day);
    }
    Date d(*this);
    d._day -= day;
    while(d.IsValid() == false)
    {
        --d._month;
        if(d._month == 0)
        {
            --d._year;
            d._month = 12;
        }
        int pre_month_day = GetMonthDay(d._year,d._month);
        d._day += pre_month_day;
    }
    return d;
}
 
Date& Date::operator-=(int day)
{
    *this = (*this - day);
    return *this;
}
 
int Date::operator-(const Date& d)//日期-日期 返回天数
{
    int flag = 1;
    Date max = (*this);
    Date min = d;
    if((*this) < d)
    {
        max = d;
        min = (*this);
        flag = -1;
    }
    int count = 0;
    while(max != min)
    {
        ++min;
        ++count;
    }
    return flag*count;
}
Date& Date::operator++()//默认前置
{
    *this += 1; // 只调用一个函数
    //*this = *this + 1; //调用两个函数，还要调用拷贝构造函数
    return *this;
}
 
//  d1++ ->  d1.operator++(&d1,0);
Date Date::operator++(int)//用参数标志后置++
{
    Date tmp(*this);
    *this += 1;
    return tmp;
}
 
Date& Date::operator--()
{
    *this -= 1;
    return *this;
}
 
Date Date::operator--(int)
{
    Date tmp(*this);
    *this -= 1;
    return tmp;
}
int main() {
  Date today(2018,3,20);
  Date day(2018,3,20);
  day.show();
  for(int i=0;i<30;i++)
    day.nextDay();
  day.show();
  for(int i=0;i<30;i++)
    day.previousDay();
  day.show();
  if(day.equal(today))
    printf("Very Good!\n");
  else
    printf("Very Bad!\n");
  return 0;
}
