////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-29 14:15:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2110
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1040KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int c1[100005],c2[100005];
int main()
{
	int i,j,k,n,v[101],num[101],sum,t;
	while(scanf("%d",&n)!=EOF && n)
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&v[i],&num[i]);
			sum+=v[i]*num[i];
		}
		if(sum%3!=0)
		{
			printf("sorry\n");
			continue;
		}
		sum/=3;
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=0;i<=num[1];i++)
		{
			c1[i*v[1]]=1;
		}
		t=v[1]*num[1];
		for(i=2;i<=n;i++)
		{
			for(j=0;j<=t;j++)
			{
				for(k=0;k+j<=sum && k<=v[i]*num[i];k+=v[i])
				{
					c2[j+k]+=c1[j];
				}
			}
			t+=v[i]*num[i];
			for(j=0;j<=t;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
			for(j=0;j<=t;j++)
			{
				if(c1[j]>10000)
				{
					c1[j]%=10000;
				}
			}
		}
		if(c1[sum]!=0)
		{
			printf("%d\n",c1[sum]);
		}
		else
		{
			printf("sorry\n");
		}
	}
	return 0;
}
