////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 01:32:22
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:8056KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define N 1000000
__int64 a[N]; //定义在外面？！
int main()
{
	__int64 n,i;
	while(scanf("%I64d",&n)!=EOF)
	{
		a[0]=7%3;
	    a[1]=11%3;
		for(i=2;i<=n;i++)
		{
			a[i]=(a[i-1]+a[i-2])%3;
		}
		if(a[n])
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}