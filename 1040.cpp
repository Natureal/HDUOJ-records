////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-10 21:20:49
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1040
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define N 1000
void sort(int x[N],int y);
int main()
{
	int t,n,i,a[N];
	while(scanf("%d",&t)!=EOF)
	{
		while(t--)
		{
			scanf("%d",&n);
			for(i=0;i<n;i++)
			{
				scanf("%d",&a[i]);
			}
			sort(a,n);
			for(i=0;i<n-1;i++)
				printf("%d ",a[i]);
			printf("%d\n",a[n-1]);//注意这里是a[n-1]，因为循环中最多输出的是a[i-2],或者这里可以直接写a[i]!!!
		}
	}
	return 0;
}
void sort(int x[N],int y)
{
	int i,j,k,temp;
	for(i=0;i<y-1;i++)
	{
		k = i;
		for(j=i+1;j<y;j++)
		{
			if(x[j]<x[k])
			k = j;
		}
		if( k!=i)
		{
			temp=x[i];
			x[i]=x[k];
			x[k]=temp;
		}
	}
	return;
}