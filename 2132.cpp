////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-08 11:33:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2132
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1004KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	_int64 a[100005],n,i;
	a[1]=1;
	for(i=2;i<=100000;i++)
	{
		if(i%3==0)
		{
			a[i]=a[i-1]+i*i*i;
		}
		else
		{
			a[i]=a[i-1]+i;
		}
	}
	while(scanf("%I64d",&n)!=EOF && n>=0)
	{
		printf("%I64d\n",a[n]);
	}
	return 0;
}