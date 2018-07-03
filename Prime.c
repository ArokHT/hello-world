/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
#include<stdio.h>  
int main()  
{  
int a=0,i=0;  
scanf("%d",&a);
if(a==1) printf("This is not a prime.");   
for(i=a-1;i>1;i--)  
{   
    if(a%i==0)
 { 
       printf("This is not a prime.");  
       break ;  
 }  
}   
if(i==1)  
    printf ("This is a prime.");    
    return 0;  
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
