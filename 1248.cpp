////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-25 22:24:34
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1248
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int main()
{
	int i,j,k,t,c1[10005],n,c2[10005],a[4];
	a[1]=150;
	a[2]=200;
	a[3]=350;
	scanf("%d",&t);
	while(t--)
	{
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		scanf("%d",&n);
		for(i=0;i<=n;i+=a[1])
		{
			c1[i]=1;
		}
		for(i=2;i<=3;i++)
		{
			for(j=0;j<=n;j++)
			{
				for(k=0;k+j<=n;k+=a[i])
				{
					c2[j+k]+=c1[j];
				}
			}
			for(j=0;j<=n;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		for(j=n;j>=1;j--)
		{
			if(c1[j]!=0) break;
		}
		printf("%d\n",n-j);
	}
	return 0;
}