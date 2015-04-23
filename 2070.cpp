////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-28 09:57:38
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2070
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	_int64 i,a[51],n;
	a[0]=0;
	a[1]=1;
	for(i=2;i<51;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	while(scanf("%I64d",&n)!=EOF && n!=-1)
	{
		printf("%I64d\n",a[n]);
	}
	return 0;
}