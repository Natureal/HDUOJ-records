////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-29 13:52:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2082
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int c1[51],c2[51];
int main()
{
	int i,j,k,n,a[27],t;
	scanf("%d",&n);
	while(n--)
	{
		for(i=1;i<=26;i++)
		{
			scanf("%d",&a[i]);
		}
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for(i=0;i<=a[1];i++)
		{
			c1[i]=1;
		}
		for(i=2;i<=26;i++)
		{
			for(j=0;j<=50;j++)//ºÏ²¢
			{
				for(k=0;k+j<=50 && k<=i*a[i];k+=i)
				{
					c2[j+k]+=c1[j];
				}
			}
			for(j=0;j<=50;j++)
			{
				c1[j]=c2[j];
				c2[j]=0;
			}
		}
		int sum=0;
		for(j=1;j<=50;j++)
		{
			sum+=c1[j];
		}
		printf("%d\n",sum);
	}
	return 0;
}