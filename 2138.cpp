////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-10 12:22:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2138
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int isprime(int x)
{
	int i,k;
	k=sqrt(1.0*x);
	for(i=2;i<=k;i++)
	{
		if(0==x%i) break;
	}
	if(i>k) return 1;
	return 0;
}
int main()
{
	int n,t,count;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		while(n--)
		{
			scanf("%d",&t);
			if(isprime(t))
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}