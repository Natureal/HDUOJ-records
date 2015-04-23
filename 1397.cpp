////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-27 23:08:56
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1397
////Problem Title: 
////Run result: Accept
////Run time:250MS
////Run memory:368KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int isprime(int n)
{
	int i,k;
	k=(int)sqrt((double)n);
	for(i=2;i<=k;i++)
	{
		if(0==n%i)
			return 0;
	}
	return 1;
}
int main()
{
	int n,i,k,count,a[33000];
	for(i=2;i<33000;i++)
	{
		if(isprime(i))
			a[i]=1;
		else
			a[i]=0;
	}
	while(scanf("%d",&n)!=EOF && n)
	{
		k=n/2;
		count=0;
		for(i=2;i<=k;i++)
		{
			if(a[i] && a[n-i])
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}