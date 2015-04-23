////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 00:21:56
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2020
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
void sort(int a[],int l);
int main()
{
	int n,i,a[100];
	while(scanf("%d",&n)!=EOF && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,n);
		for(i=0;i<n-1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n-1]);
	}
	return 0;
}

void sort(int a[],int l)
{
	int i,j,k,temp;
	for(i=0;i<l-1;i++)
	{
		k=i;
		for(j=i+1;j<l;j++)
		{
			if(labs(a[j])>labs(a[k]))
				k=j;
		}
		temp=a[i];
		a[i]=a[k];
		a[k]=temp;
	}
	return;
}