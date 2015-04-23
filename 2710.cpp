////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-11 00:18:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2710
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:380KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 20000+20
int main()
{
	int i,n,k,max,maxre;
	int isprime[MAX]={1};
	for(i=2;i<MAX;i++)
	{
		for(int j=i*i;j<MAX;j+=i)
		{
			isprime[j]=1;
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		max=0;
		maxre=0;
		while(n--)
		{
			scanf("%d",&k);
			for(i=k;i>0;i--)
			{
				if(!isprime[i] && 0==k%i)
				{
					if(i>max)
					{
						max=i;
						maxre=k;
						break;
					}
				}
			}
		}
		printf("%d\n",maxre);
	}
	return 0;
}