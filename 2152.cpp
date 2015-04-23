////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-29 17:07:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2152
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int c1[105],c2[105];
int main()
{
	int i,j,k,n,m,a[105],b[105],sum;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=a[1];i<=b[1];i++)
		{
			c1[i]=1;
		}
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=100;j++)
			{
				for(k=a[i];k<=b[i];k++)
				{
					c2[j+k]+=c1[j];
				}
			}
			for(j=0;j<=100;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		printf("%d\n",c1[m]);
	}
	return 0;
}