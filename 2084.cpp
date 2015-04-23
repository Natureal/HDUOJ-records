////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-14 15:16:11
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:264KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int a[101][101],t,i,n,j;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=i;j++)
			{
				scanf("%d",&a[i][j]);
			}
		}
		for(i=n-1;i>=1;i--)
		{
			for(j=1;j<=n;j++)
			{
				a[i][j]+=(a[i+1][j]>a[i+1][j+1]?a[i+1][j]:a[i+1][j+1]);
			}
		}
		printf("%d\n",a[1][1]);
	}
	return 0;
}