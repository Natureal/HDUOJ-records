////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-31 22:36:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1097
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int pow(int a,int b)
{
	a%=10;
	int r=1;
	while(b)
	{
		if(b%2)
		{
			r*=a;
			r%=10;
		}
		a*=a;
		a%=10;
		b/=2;
	}
	return r;
}

int main()
{
	int a,b,re;
    while(scanf("%d %d",&a,&b)>0)
	{
		re=pow(a,b);
		printf("%d\n",re);
	}
	return 0;
}
