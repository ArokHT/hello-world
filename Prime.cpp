#include <iostream>
using namespace std;
int prime(int n);
int prime(int n)
{
int i;
for(i=2;i<=n/2;i++)
if(n%i==0)
return 0;
else
return 1;
return 0;
}
void main(){
int m;
cout<<"请输入这个数m=";
cin>>m;
if(prime(m))
cout << m << " 是素数 ";
else cout << m << " 不是素数 ";
}
class Prime {
public:
  Prime(int num);
  ~Prime();

  bool isPrime();

  Prime sumBit();
  Prime multiBit();
  Prime sqaureSumBit();
private:
  const int mNum;
};

int main() {
  Prime pm(113);
  Prime sb = pm.sumBit();
  Prime mb = pm.multiBit();
  Prime ssb = pm.sqaureSumBit();
  if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
    ; //to do sth
  return 0;
}
