////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-03 22:41:47
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1420
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,re;
	_int64 a,b,c,temp;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&c);
		temp=a;
		for(i=0;i<b;i++)
		{
			re=temp%c;
			temp=a*re;
		}
		printf("%d\n",re);
	}
	return 0;
	}