////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-23 19:40:03
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2161
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int isprime(int x)
{
	int i,k;
	k=sqrt(1.0*x);
	if(x==2 || x==1) return 0;
	for(i=2;i<=k;i++)
	{
		if(0==x%i)
			return 0;
	}
	return 1;
}
int main()
{
	int i=1,n;
	while(scanf("%d",&n)!=EOF && n>0)
	{
		if(isprime(n))
			printf("%d: yes\n",i);
		else
			printf("%d: no\n",i);
		i++;
	}
	return 0;
}