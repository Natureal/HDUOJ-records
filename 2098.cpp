////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-21 16:35:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2098
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int check(int x)
{
	int i,k;
	k=sqrt(1.0*x);
	for(i=2;i<=k;i++)
	{
		if(0==x%i) break;
	}
	if(i>k)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int n,i,count;
	while(scanf("%d",&n)!=EOF && n)
	{
		count=0;
		for(i=2;i<n/2;i++)
		{
			if(check(i) && check(n-i))
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}