////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-04 22:49:54
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1563
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
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
int main()
{
	int i,n,a[200],k;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,n);
		k=0;
		for(i=1;i<n;i++)
		{
			if(a[k]!=a[i])
				break;
			else
			{
				i++;
				k=i;
			}
		}
		printf("%d\n",a[k]);
	}
	return 0;
}