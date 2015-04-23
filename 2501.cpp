////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-03 15:43:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2501
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,a[31],n;
	a[1]=1;
	a[2]=3;
	for(int i=3;i<31;i++)
	{
		a[i]=a[i-1]+2*a[i-2];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
	return 0;
}