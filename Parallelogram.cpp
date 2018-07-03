#include<iostream>
using namespace std;
class Parallelogram
{
  public:
  	Parallelogram(int x, int y);
    void show();
    void area()
    {
      cout << height1*length1 << endl;
    }
    void height(int y)
    {
      height1=y;
    }
    void length(int x)
    {
      length1=x;
    }
    private:
    	int height1;
    	int length1;
};
Parallelogram::Parallelogram(int x, int y)
{
	height1=y;
	length1=x;
}
void Parallelogram::show()
{
  Parallelogram::area();
}
int main()
{
  Parallelogram pg(1, 1);
  pg.show();
  pg.area();
  pg.height(1);
  pg.length(1);
  return 0;
}
