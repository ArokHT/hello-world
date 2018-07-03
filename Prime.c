/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int i, j, len1, len2, flag=0;
	char s1[100], s2[100];
	cin >> s1 >> s2;
	len1=strlen(s1);
	len2=strlen(s2);
	if(s1[len1-1]==s2[len2-1] && len1<=len2)
	{
		for(i=len1-1, j=len2-1; i>=0; i--, j--)
		{
			if(s1[i]==s2[j])
			{
				flag++;
			}
			else
			if(s1[i]!=s2[j]) 
			{
				break;
			}
		}
		for(i=len1-flag; i<=len1-1; i++)
		{
			cout << s1[i];
		}
		cout << endl;
	}
	if(s1[len1-1]==s2[len2-1] && len1>len2)
	{
		for(i=len1-1, j=len2-1; j>=0; i--, j--)
		{
			if(s1[i]==s2[j])
			{
				flag++;
			}
			else
			if(s1[i]!=s2[j])  
			{
				break;
			}
		}
		for(j=len2-flag; j<=len2-1; j++)
		{
			cout << s2[j];
		}
		cout << endl;
	}
	if(s1[len1-1]!=s2[len2-1])
	{
		cout << "null" << endl;
	}
	//cout << s1[2] << endl;
	//cout << len1 << endl;
	//cout << len2 << endl;
	//cout << flag << endl;
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
