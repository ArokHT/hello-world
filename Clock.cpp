#include<iostream>
using namespace std;
class Clock 
{
	public:
		Clock(int x, int y, int k);
		~Clock()
		{
		}
		void adjust(int x, int y, int k);
		void show();
 	private:
  		int hour;
  		int minute;
  		int second;
};
Clock::Clock(int x, int y, int k)
{
	hour=x;
	minute=y;
	second=k;
}
void Clock::adjust(int x, int y, int k)
{
	hour=x;
	minute=y;
	second=k;
}
void Clock::show()
{
	cout << "现在是北京时间" << hour << "时" << minute << "分" << second << "秒" << endl; 
}
int main() 
{
  Clock ck(10, 45, 00);
  ck.adjust(16,45,00);
  ck.show();
  return 0;
}
