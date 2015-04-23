////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-28 00:08:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1405
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,t=0,n,k;
	while(scanf("%d",&n)!=EOF && n>0)
	{
		if(t>0)
			printf("\n");
		t++;
		i=0;
		k=3;
		printf("Case %d.\n",t);
		if(n==2)
		{
			printf("%d %d ",2,1);
		}
		while(n!=0 && k<=n)
		{
			if(0==n%2)
			{
				while(0==n%2)
				{
					i++;
					n/=2;
				}
				printf("%d %d ",2,i);
			}
			else
			{
				i=0;
				if(0==n%k)
				{
					while(0==n%k)
					{
						i++;
						n/=k;
					}
					printf("%d %d ",k,i);
				}
				k+=2;
			}
		}
		printf("\n");
	}
	return 0;
}