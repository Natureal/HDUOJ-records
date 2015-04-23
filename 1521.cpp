////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-07 00:07:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1521
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
double c1[100],c2[100];
int fac(int x)
{
	if(0==x)
		return 1;
	else
		return x*fac(x-1);
}
int main()
{
	int i,j,k,n,m,num[11];
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		memset(c1,0,sizeof(c1));
		memset(c1,0,sizeof(c2));
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
		}
		for(i=0;i<=num[1];i++)//切记要取到0
		{
			c1[i]=1.0/fac(i);
		}
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
				for(k=0;k+j<=m && k<=num[i];k++)
				{
					c2[k+j]+=c1[j]/fac(k);
				}
			}
			for(j=0;j<=m;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%.0lf\n",fac(m)*c1[m]);
	}
	return 0;
}
