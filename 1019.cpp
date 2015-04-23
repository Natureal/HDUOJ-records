////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 01:10:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1019
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int lcm(int x,int y)
{
	int m,n,r;
	m=x;
	n=y;
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	return (x/m*y);
}
int main()
{
	int n,t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&a);
		n--;
		while(n--)
		{
			scanf("%d",&b);
			a=lcm(a,b);
		}
		printf("%d\n",a);
	}
	return 0;
}