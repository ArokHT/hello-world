#include<iostream>
using namespace std;
class Prime 
{
public:
  Prime(int num);
  int druge(int num);
  ~Prime();

private:
  const int mNum;
};
Prime::Prime(int num)
{
  mNum=num;
}
int Prime::druge(int num)
{
  //判断素数
}
class SuperPrime : public Prime
{
public:
  SuperPrime(int num);
  ~SuperPrime();

  //bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int num;
}
int main()
{
    SuperPrime sp(113);
    if(sp.isPrime()) 
    {
        cout << "yes" << endl; // do something
    }
  return 0;
}
