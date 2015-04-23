////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-17 23:22:06
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2085
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,n;
	_int64 a[34],b[34];
	a[0]=1;
	b[0]=0;
	for(i=1;i<34;i++)
	{
		a[i]=a[i-1]*3+b[i-1]*2;
		b[i]=a[i-1]+b[i-1];
	}
	while(scanf("%d",&n)!=EOF && n!=-1)
	{
		printf("%I64d, %I64d\n",a[n],b[n]);
	}
	return 0;
}