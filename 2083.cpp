////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-14 14:52:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2083
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
void sort(int x[],int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(x[j]<x[k])
				k=j;
		}
		if(k!=i)
		{
			temp=x[i];
			x[i]=x[k];
			x[k]=temp;
		}
	}
	return;
}
int main()
{
	int i,m,k,sum,n,a[500];
	scanf("%d",&m);
	while(m--)
	{
		sum=0;
		scanf("%d",&n);
		k=n/2;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,n);
		for(i=0;i<n;i++)
		{
			sum+=labs(a[k]-a[i]);
		}
		printf("%d\n",sum);
	}
	return 0;
}