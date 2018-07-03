//单位转换程序，输入值和原单位，新单位，返回新单位下的值。
//重量单位：Kg, g, lb, gr,......
//压力单位：Pa, MPa, psi,......
//长度单位：m, km, ft, in,......
//其它单位：md, cp,......
//还有很多单位转换，有些单位是其它单位组合出来的
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int which;//全局变量 
class transform
{
	public:
		transform(float x, string s1, string s2);//构造函数 
		//int input(double x, string s1, string s2);
		void inputfind(string s1, string s2);
//		void whichfind(float x);
		float lengthcalculate(float x);
		float weightcalculate(float x);
		float timecalculate(float x);
		float pressurecalculate(float x);
//		float calculate(float x);
	//private:
		//int which;
		float digit;
		string str1, str2, oringe, now; 
		
};
transform::transform(float x, string s1, string s2)
{
	digit=x;
	str1=s1;
	str2=s2;
}
void transform::inputfind(string s1, string s2)
{
	string length[5]={"km", "m", "dm", "cm", "mm"};//长度单位 
	for(int i=0; i<5; i++)
	{
		if(s1==length[i])
		{
			which=1;
			switch(i)
			{
				case 0: oringe="0"; break;
				case 1: oringe="1"; break;
				case 2: oringe="2"; break;
				case 3: oringe="3"; break;
				case 4: oringe="4"; break;
			}
			//oringe=i;
			for(int j=0; j<5; j++)
			{
				if(s2==length[j])
				{
					switch(j)
					{
					case 0: now="0"; break;
					case 1: now="1"; break;
					case 2: now="2"; break;
					case 3: now="3"; break;
					case 4: now="4"; break;
					}
					//now=j;
					break; 
				}
			}
			break; 
		}
	}
	string weight[4]={"t", "kg", "g", "mg"};//重量单位 
	for(int i=0; i<4; i++)
	{
		if(s1==weight[i])
		{
			which=2;
			switch(i)
			{
				case 0: oringe="0"; break;
				case 1: oringe="1"; break;
				case 2: oringe="2"; break;
				case 3: oringe="3"; break;
			}
			for(int j=0; j<4; j++)
			{
				if(s2==weight[j])
				{
					switch(j)
					{
					case 0: now="0"; break;
					case 1: now="1"; break;
					case 2: now="2"; break;
					case 3: now="3"; break;
					}
					break; 
				}
			}
			break; 
		}
	}
	string time[5]={"day", "h", "min", "s", "ms"};//时间单位 
	for(int i=0; i<5; i++)
	{
		if(s1==time[i])
		{
			which=3;
			switch(i)
			{
				case 0: oringe="0"; break;
				case 1: oringe="1"; break;
				case 2: oringe="2"; break;
				case 3: oringe="3"; break;
				case 4: oringe="4"; break;
			}
			//oringe=i;
			for(int j=0; j<5; j++)
			{
				if(s2==time[j])
				{
					switch(j)
					{
					case 0: now="0"; break;
					case 1: now="1"; break;
					case 2: now="2"; break;
					case 3: now="3"; break;
					case 4: now="4"; break;
					}
					//now=j;
					break; 
				}
			}
			break; 
		}
	}
	string pressure[4]={"mpa", "kpa", "psi", "pa"};//压强单位 
	for(int i=0; i<4; i++)
	{
		if(s1==pressure[i])
		{
			which=6;
			switch(i)
			{
				case 0: oringe="0"; break;
				case 1: oringe="1"; break;
				case 2: oringe="2"; break;
				case 3: oringe="3"; break;
			}
			for(int j=0; j<4; j++)
			{
				if(s2==pressure[j])
				{
					switch(j)
					{
					case 0: now="0"; break;
					case 1: now="1"; break;
					case 2: now="2"; break;
					case 3: now="3"; break;
					}
					break; 
				}
			}
			break; 
		}
	}
}
//float transform::calculate(float x)
float transform::lengthcalculate(float x)
{
//	if(which==1)
//	{
	string s=oringe+now;
	//switch(s)
	//{
		if(s=="01") return x*1000; //break;
		if(s=="02") return x*10000; //break;
		if(s=="03") return x*100000;// break;
		if(s=="04") return x*1000000;// break;
		if(s=="10") return x/1000;// break;
		if(s=="12") return x*10; //break;
		if(s=="13") return x*100; //break;
		if(s=="14") return x*1000; //break;
		if(s=="20") return x/10000; //break;
		if(s=="21") return x/10;// break;
		if(s=="23") return x*10;// break;
		if(s=="24") return x*100;// break;
		if(s=="30") return x/100000; //break;
		if(s=="31") return x/100; //break;
		if(s=="32") return x/10; //break;
		if(s=="34") return x*10; //break;
		if(s=="40") return x/1000000; //break;
		if(s=="41") return x/1000; //break;
		if(s=="42") return x/100; //break;
		if(s=="43") return x/10; //break;*/
		//}
}
//	if(which==2)
float transform::weightcalculate(float x)
{
	string s=oringe+now;
	//switch(s)
	//{
	if(s=="01") return x*1000; //break;
	if(s=="02") return x*1000000; //break;
	if(s=="03") return x*1000000000;// break;
	//if(s=="04") return x*100000;// break;
	if(s=="10") return x/1000;// break;
	if(s=="12") return x*1000; //break;
	if(s=="13") return x*1000000; //break;
		//	if(s=="14") return x*1000; //break;
	if(s=="20") return x/1000000; //break;
	if(s=="21") return x/1000;// break;
	if(s=="23") return x*1000;// break;
		//	if(s=="24") return x*100;// break;
	if(s=="30") return x/1000000000; //break;
	if(s=="31") return x/1000000; //break;
	if(s=="32") return x/1000; //break;
		//	if(s=="34") return x*10; //break;
		//	if(s=="40") return x/1000000; //break;
		//	if(s=="41") return x/1000; //break;
		//	if(s=="42") return x/100; //break;
		//	if(s=="43") return x/10; //break;*/
		//}
}
//	if(which==3)
float transform::timecalculate(float x)
{
	string s=oringe+now;
	//switch(s)
	//{
	if(s=="01") return x*24; //break;
	if(s=="02") return x*24*60; //break;
	if(s=="03") return x*24*60*60;// break;
	if(s=="04") return x*24*60*60*1000;// break;
	if(s=="10") return x/24;// break;
	if(s=="12") return x*60; //break;
	if(s=="13") return x*60*60; //break;
	if(s=="14") return x*60*60*1000; //break;
	if(s=="20") return x/(24*60); //break;
	if(s=="21") return x/60;// break;
	if(s=="23") return x*60;// break;
	if(s=="24") return x*60*100;// break;
	if(s=="30") return x/(60*60*24); //break;
	if(s=="31") return x/(60*60); //break;
	if(s=="32") return x/60; //break;
	if(s=="34") return x*1000; //break;
	if(s=="40") return x/(24*60*60*1000); //break;
	if(s=="41") return x/(60*60*1000); //break;
	if(s=="42") return x/(60*1000); //break;
	if(s=="43") return x/1000; //break;*/
		//}
}
float transform::pressurecalculate(float x)
{
	string s=oringe+now;
	if(s=="01") return x*1000; //break;
	if(s=="02") return x*145.037744; //break;
	if(s=="03") return x*1000000;// break;
	if(s=="10") return x/1000;// break;
	if(s=="12") return x/1000*145.037744; //break;
	if(s=="13") return x*1000; //break;
	if(s=="20") return x/145.037744; //break;
	if(s=="21") return x/145.037744*1000;// break;
	if(s=="23") return x/145.037744*1000*1000;// break;
	if(s=="30") return x/1000000; //break;
	if(s=="31") return x/1000; //break;
	if(s=="32") return x/145.037744; //break;
}
//void transform::whichfind(float x)
class whichfind:transform//继承
{
	public:
		whichfind(float x, string s1, string s2):transform(x, s1, s2)
		{
		}
		void caculate(float x);
};
void whichfind::caculate(float x)
{
	switch(which)
	{
		case 1: printf("%f\n", transform::lengthcalculate(x));break;
		case 2: printf("%f\n", transform::weightcalculate(x));break;
		case 3: printf("%f\n", transform::timecalculate(x));break;
		case 6: printf("%f\n", transform::pressurecalculate(x));break;
				
	}
}
int main()
{
	float x;
	string s1, s2;
	cin >> x >> s1 >> s2;
	transform T(x, s1, s2);
	T.inputfind(s1, s2);
	T.lengthcalculate(x);
	T.weightcalculate(x);
	T.timecalculate(x);
	T.pressurecalculate(x);
	whichfind a(x, s1, s2);
	a.caculate(x);
//	T.whichfind(x);
//	printf("%f\n", T.calculate(x));
//	cout << T.calculate(x);
//	T.input(x, s1, s2);
	//cout << T.input(x, s1, s2) << endl;
	return 0;
}
