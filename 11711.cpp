////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-26 23:22:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:2296MS
////Run memory:2184KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define N 250001
int c1[N],c2[N],v[51],n[51];
int main()
{
	int i,j,k,num,sum;
	while(scanf("%d",&num)!=EOF && num>=0) 
	{
		sum=0;
		for(i=1;i<=num;i++)
		{
			scanf("%d %d",&v[i],&n[i]);
			sum+=v[i]*n[i];
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=0;i<=n[1];i++)
		{
			c1[i*v[1]]=1;
		}
		for(i=2;i<=num;i++)
		{
			for(j=0;j<=sum;j++)
			{
				for(k=0;k<=n[i] && k*v[i]+j<=sum;k++)
				{
					c2[j+k*v[i]]+=c1[j];
				}
			}
			for(j=0;j<=sum;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		for(j=sum/2;j>=0;j--)
		{
			if(c1[j]!=0)
			{
				printf("%d %d\n",sum-j,j);
				break;
			}
		}
	}
	return 0;
}