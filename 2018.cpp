////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-15 19:19:24
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2018
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,n,a[55]={0};
	for(i=0;i<4;i++)
	{
		a[i]=i;
	}
	for(i=4;i<55;i++)
	{
		a[i]=a[i-1]+a[i-3];
	}
	while(scanf("%d",&n)!=EOF && n)
	{
		printf("%d\n",a[n]);
	}
	return 0;
}