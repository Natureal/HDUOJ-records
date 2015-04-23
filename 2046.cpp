////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 11:56:53
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2046
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
//从第一个方格开始，骨牌可以横放（这样下面必再放一张）占两格，也可以竖着放占一格，这样问题
//就转化成，N米的路，一次可以走1m或2m，有几种走法的问题了，即可运用斐波那契数列求解！
#include <stdio.h>
int main()
{
	int n,i;
	long long a[51]={0,1,2,3};
	while(scanf("%d",&n)!=EOF)
	{
		for(i=4;i<=n;i++)
		{
			a[i]=a[i-1]+a[i-2];
		}
		printf("%I64d\n",a[n]);
	}
	return 0;
}