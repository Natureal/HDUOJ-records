////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-30 22:43:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2566
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int c1[10000],c2[10000];
int main()
{
	int i,j,k,t,m,n,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		sum=0;
		for(i=0;i<=m/5;i++)
		{
			for(j=0;j<=(m-i*5)/2;j++)
			{
				if(n+j+4*i==m)
				{
					sum++;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}