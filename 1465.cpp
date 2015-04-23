////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-03 23:16:17
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1465
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,n;
	_int64 a[21];
	a[1]=0;
	a[2]=1;
	for(i=3;i<21;i++)
	{
		a[i]=(i-1)*(a[i-1]+a[i-2]);
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%I64d\n",a[n]);
	}
	return 0;
}