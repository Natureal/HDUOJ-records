////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-24 23:32:45
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1028
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int c1[1000],c2[1000];
int main()
{
	int i,j,k,n;
	for(i=0;i<=125;i++)
	{
		c1[i]=1;
		c2[i]=0;
	}
	for(i=2;i<=125;i++)
	{
		for(j=0;j<=125;j++)
		{
			for(k=0;k+j<=125;k+=i)
			{
				c2[j+k]+=c1[j];
			}
		}
		for(j=0;j<=125;j++)
		{
			c1[j]=c2[j];
			c2[j]=0;
		}
	}
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",c1[n]);
	}
	return 0;
}