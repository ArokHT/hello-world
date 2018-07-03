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
