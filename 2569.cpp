////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-23 21:51:04
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2569
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,t,n;
	int a[40];
	a[1]=3;
	a[2]=9;
	for(i=3;i<40;i++)
	{
		a[i]=2*a[i-1]+a[i-2];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}