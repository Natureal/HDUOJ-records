////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-07 17:39:09
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2190
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,t,a[31];
	a[1]=1;
	a[2]=3;
	a[3]=5;
	for(i=4;i<=30;i++)
	{
		a[i]=a[i-1]+2*a[i-2];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&i);
		printf("%d\n",a[i]);
	}
	return 0;
}