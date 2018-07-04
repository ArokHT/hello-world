/*��λת��������ҵ�� 
��Ա��������github���ƣ�ExecutantLK�������Σ�GitHub��ArokHT�����½�(Github:gitvide)
��Ա����������������������λ��������λ�������λ���������ƣ�����д����������
���Σ������ʱ�䣬���ȣ�������ѹ����
�½ܣ������������룬������˻��ຯ����ʵ�ּ̳У���Ʊ�ʾ�¶ȵĵ�λת���ࡣ
//////////////////////////////////////////////////////////////// 
˼·��������ҵ�涨������������ԭ��ֵ��ԭ��λ��Ҫת���ɵĵ�λ����ô������Ϊ�����Ļ����ͻ����������ݳ�Ա��
����Ա�������������������˼·��������ֻ��Ҫһ��find����������ƥ��õ�λ����һ�൥λ����translate����
������ת����ֵ������ֵ�λ��ֵ����Ȼ������һ��show�������������ֵ��show���������������������Ҫ��ƵĻ���
��ÿһ�����ж����У���ô�������һ�����࣬���е�������Ա����ȫ��Ū�ɴ��麯�����ɼ̳г���������ʵ�֣�������
��Ա���ǽ���Ū��protect���Ӷ����м̳к󣬸����ݳ�Ա��Ȼ�������˽�г�Ա������ͨ����Ա���������ã��Ӷ�ʵ��
����
//////////////////////////////////////////////////////////////// 
������ʵ�ֵĵ�λת����
1.���ȵ�λ��km, m, dm, cm, mm 
2.������λ��t, kg, g, mg 
3.ʱ�䵥λ��day, h, min, s, ms 
4.�����λ��mm2,cm2,dm2,m2,ha,km2��mm2���У�2�������ƽ���� 
5.������λ��pa,na,ua,ma,a,ka 
6.ѹǿ��λ��mpa, kpa, psi, Pa(Ϊ�������pa��ͻ���ʴ�д) 
7.�¶ȵ�λ���������¶�K�������¶� F�������¶�C 
8.�����λ�� mm3,cm3,dm3,m3,ml,l���ֱ�Ϊ�������ף��������ס������������������� */
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<string.h> 
#include<iomanip>

int which; //ȫ�ֱ������������Ƶ���
using namespace std;
class units
{
public:
	virtual int find(string s1,string s2) = 0;
	virtual void translate() = 0;
	virtual void show() const = 0;
protected:
	long  double num;
	string ori;
	string now;									//���������Ϊ�������ԭʼ��λ���ֵ�λ�������е�λ��������num
	int first,second;
};
class temperature:public units
{
public:
	temperature(long  double x,string s1,string s2);
	int find(string s1,string s2);
	void translate();
	void show() const ;
	
};
temperature::temperature(long  double x,string s1,string s2)
{
	ori = s1;
	now = s2;
	num = x;
}
temperature::find(string s1,string s2)
{
	char temper[3][3]=
	{
		"F",
		"K",
		"C",
	 };
	for(int i = 0;i<3;i++)
	{
		if(temper[i]==s1)
		{
			which = 7;
			first = i;
		}
		if(temper[i]==s2)
		{
			second = i;
		}
	}
	
}
void temperature::translate()
{
	if(first==0&&second==1)
	{
		double t = 5*(num-32)/9;
		num = t+273.16;
	}
	if(first==0&&second==2)
	{
		num = 5*(num-32)/9;
	}
	if(first==1&&second==0)
	{
		double t = num - 273.16;
		num = t*(9/5) + 32;
	}
	if(first==1&&second==2)
	{
		num = num - 273.16;
	}
	if(first==2&&second==0)
	{
		num = num*(9/5) + 32;
	}
	if(first==2&&second==1)
	{
		num = num + 273.16;
	}
}
void temperature::show() const
{
	cout << num << endl;
}
class areaunits:public units
{         //�����λ 
	public:
		areaunits(long double x,string s1,string s2);  //�ù��캯������frist��second��ֵ 
		int find(string s1,string s2);  //�����ж��Ƿ�õ��ø��� 
		void translate();                 //��������ת����ֵ 
		void show() const;       //չʾ 
};
class vunits:public units
{        //�����λ 
	public:
		vunits(long  double x,string s1,string s2);   //����ͬ�� 
		int find(string s1,string s2);
		void translate();
		void show() const;
}; 

class eleunits:public units
{          //������λ 
	public:
		eleunits(long  double x,string s1,string s2);   //����ͬ�� 
		int find(string s1,string s2);
		void translate();
		void show() const;
};
areaunits::areaunits(long double x,string s1,string s2)
{   //���캯�� 
	num=x;
	ori=s1;
	now=s2;
}
void areaunits::translate()
{ 
	                             //cout<<first<<"  "<<second<<endl;���ڵ��� 
	if(first<=3&&second<=3)
	{    //�������λ�Ĺ�ϵ��������Ӧ�����е�λ�ã���������Ӧ�û�õ�ֵ���Լ��ı��ϵ 
		int temp=first-second;
		if(first>second)
		{
			num=num*(pow(100,temp));
		}
		else if(first<second)
		{
			temp=fabs(temp);
			num=num/(pow(100,temp));
	    }
	}
	else if(first>3&&second<=3)
	{
		int temp=3-second;
		int temp1=first-3;
		if(temp!=0)
		{
		num=num*(pow(100,temp));
		}
		
		if(temp1==1)
		{
			num=num*10000;
		} 
		else
		{
			num=num*1000000;
		}
	}
	else if(first<=3&&second>3)
	{
		int temp=3-first;
		int temp1=second-1;
		if(temp!=0)
		{
		num=num/(pow(100,temp));
		}
		
		if(temp1==1)
		{
			num=num/10000;
		} 
		else
		{
			num=num/1000000;
		}
	}
	else{
		if(first>second)
		{
			num=num*100;
		}
		else
		{
			num=num/100;
		}
	}
}
areaunits::find(string s1,string s2)
{    //�����ҵ�ƥ���ʹ�� 
	char units[10][100]=
	{
		"mm2",
		"cm2",
		"dm2",
		"m2",
		"ha",   //���� 
		"km2",  		
	};
	for(int i=0;i<6;i++)
	{
	     if(units[i]==s1)
		{
			which=4;
			first=i;
		}
			
	}
	for(int i=0;i<6;i++)
	{
	     if(units[i]==s2)
	        { 
				second=i;
			}
	}		

}
void areaunits::show() const
{
	cout<<setiosflags(ios::fixed)<<num<<endl;//�˴�����ʹ�����С����ʽ��� 
}     //����Ϊ�����λ��ʵ��
vunits::vunits(long double x,string s1,string s2)
{   //���캯�� 
	num=x;
	ori=s1;
	now=s2;
}
int vunits::find(string s1,string s2)
{    //�����ҵ�ƥ���ʹ�� 
	char units[10][100]=
	{
		"mm3",
		"cm3",
		"dm3",
		"m3",
		"ml",
		"l",
	};
	for(int i=0;i<7;i++)
	{
	     if(units[i]==s1)
		{
			which=8;
			first=i;
		}
			
	}
	for(int i=0;i<7;i++)
	{
	     if(units[i]==s2)
	        { 
				second=i;
			}
	}		
	

}
void vunits::translate()
{  //����ļ��������λ֮��Ĺ�ϵ�ĺ��� 
	if(first==4)
	{
		first=1;	
	}
	else if(first==5)
	{
		first=2;
	}
	if(second==4)
	{
		second=1;	
	}
	else if(second==5)
	{
		second=2;
	}
	int temp=first-second;
	if(temp>0)
	{
		num=num*(pow(1000,temp));
	}
	else if(temp<0)
	{
		temp=fabs(temp);
		num=num/(pow(1000,temp));
	}
	
}   
void vunits::show() const
{
	cout<<setiosflags(ios::fixed)<<num<<endl;//�˴�����ʹ�����С����ʽ��� 
}    
 
 
 
 
 
 
eleunits::eleunits(long double x,string s1,string s2)
{
	num=x;
	ori=s1;
	now=s2;
}
int eleunits::find(string s1,string s2)
{
	char units[10][100]=
	{
	    "pa", 
		"na",
		"ua",
		"ma",
		"a",
		"ka",	
	};
	for(int i=0;i<6;i++)
	{
	     if(units[i]==s1)
		 {
	     	 first=i;
			 which=5;
		 }
	}	
	for(int i=0;i<6;i++)
	{
	     if(units[i]==s2)
		 {
	     	 second=i;
		 }
	}		
}   
void eleunits::translate()
{
	int temp=first-second;
	
	if(temp>0){
		num=num*(pow(1000,temp));
		
	}
	else if(temp<0)
	{
		temp=fabs(temp);
		num=num/(pow(1000,temp));
	}
}

void eleunits::show() const
{
	cout<<num<<endl;//�˴�����ʹ�����С����ʽ��� 
}


class transform
{
	public:
		transform(long  double x, string s1, string s2);
		void inputfind(string s1, string s2);
		double calculate(long  double x);
		double digit;
		string str1, str2, oringe, now; 
		
};
transform::transform(long double x, string s1, string s2)
{
	digit=x;
	str1=s1;
	str2=s2;
}
void transform::inputfind(string s1, string s2)
{
	string length[5]={"km", "m", "dm", "cm", "mm"};//???? 
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
				
					break; 
				}
			}
			break; 
		}
	}
	string weight[4]={"t", "kg", "g", "mg"};//???? 
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
	string time[5]={"day", "h", "min", "s", "ms"};//???? 
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
	string pressure[4]={"mpa", "kpa", "psi", "Pa"};//???? 
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
//double transform::calculate(double x)
double transform::calculate(long double x)
{
	if(which==1)
	{
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
	}
	if(which==2)
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
	if(which==3)
	{
	string s=oringe+now;
	
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
	if(which==6) 
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
}

int main(){
	long double x;
	string str1,str2;
	char ch;
	printf("\n");
	printf("\n\t\t               ��λת��ϵͳ\n");
	do{
	
	cout<<"��������Ҫת������ֵ��";
	
	cin>>x;
	cout<<"������ԭ��λ�ĵ�λ���ƣ�";
	cin>>str1;
	cout<<"��������Ҫת���ɵĵ�λ��" ;
	cin>>str2;
	


	transform T(x,str1,str2);       //�˴��ֱ�����࣬��ƥ��Ӧ�����ĸ��������㵥λת�� 
	T.inputfind(str1, str2);
	T.calculate(x);
	temperature temper(x,str1,str2);
	temper.find(str1,str2);
	areaunits area1(x,str1,str2);
	eleunits ele1(x,str1,str2);
	vunits vun1(x,str1,str2);
	area1.find(str1,str2);
	ele1.find(str1,str2);
	vun1.find(str1,str2);

	switch(which)        //����������� 
	{
	    case 1:
	    case 2:
		case 3:
		case 6:cout<<"ת�������ս��Ϊ��"<<setiosflags(ios::fixed)<<T.calculate(x)<<endl;break;
		case 7: temper.translate();
				cout << "ת�������ս��Ϊ��";
				temper.show(); 
				break;
		case 4: area1.translate();
		        cout<<"ת�������ս��Ϊ��";
		        area1.show();
		        break;
	    case 5: ele1.translate();
	            cout<<"ת�������ս��Ϊ��";
	            ele1.show();
	            break;
	    case 8: vun1.translate();
	            cout<<"ת�������ս��Ϊ��";
	            vun1.show();
	            break;
	}
	cout<<endl;
}while (ch=getchar()!=EOF);
	return 0;
}
