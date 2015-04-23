////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-11 21:21:54
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2139
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	_int64 i,n,a[10000];
	a[1]=1;
	for(i=3;i<5000;i+=2)
	{
		a[i]=a[i-2]+i*i;
	}
	while(scanf("%I64d",&n)!=EOF)
	{
		printf("%I64d\n",a[n]);
	}
	return 0;
}