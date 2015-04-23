////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-09 00:39:45
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2019
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define N 101
int main()
{
	int n,m,a[N],i,j;
	while(2 == scanf("%d %d",&n,&m))
	{
		if( 0 == n && 0 == m)
		{
			return 0;
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(i=0;i<n;i++)
		{
			if(m <= a[i])
			{
				for(j=n-1;j>=i;j--)
				{
					a[j+1]=a[j];
				}
				a[i]=m;
				break;
			}
		}
		for(i=0;i<n;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n]);
	}
	return 0;
}