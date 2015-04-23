////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-30 14:14:26
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1412
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:304KB
//////////////////System Comment End//////////////////
#include <stdio.h>
void sort(int arr[],int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[k])
				k=j;
		}
		if(k!=i)
		{
			temp=arr[i];
			arr[i]=arr[k];
			arr[k]=temp;
		}
	}
	return;
}
int tighten(int arr[],int n)
{
	int i,j;
	for(i=1,j=1;i<n;i++)
	{
		if(arr[i]!=arr[j-1])
			arr[j++]=arr[i];
	}
	return j;
}

int main()
{
	int a[20001];
	int i,j,s,n,m,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		sort(a,n);
		for(j=0;j<m;j++)
		{
			scanf("%d",&k);
			for(i=0;i<n+j;i++)
			{
				if(k<a[i])
				{
					for(s=n+j;s>i;s--)
					{
						a[s]=a[s-1];
					}
					a[i]=k;
					break;
				}
			}
			if(i==n+j)
				a[n+j]=k;
		}
		n=tighten(a,n+m);
		for(i=0;i<n-1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n-1]);
	}
	return 0;
}