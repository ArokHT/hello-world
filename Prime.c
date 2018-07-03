/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
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
int sum_bit(int num) {
  return 0;
}

int multi_bit(int num) {
  return 0;
}

int square_sum_bit(int num) {
  return 0;
}

bool isprime(int num) {
  return false;
}

int main() {
  if(isprime(113)&&isprime(sum_bit(113))&&isprime(multi_bit(113))&&isprime(square_sum_bit(113)))
    //to do sth
}
