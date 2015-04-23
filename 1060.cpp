////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-16 17:01:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	double a,c,n;
	_int64 b,d,t;
	scanf("%I64d",&t);
	while(t--)
	{
		scanf("%lf",&n);
		a=n*log10(n);
		b=(_int64)a;
		c=a-b;
		d=(_int64)pow(10.0,c);
		printf("%I64d\n",d);
	}
	return 0;
}