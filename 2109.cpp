////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-07 14:39:22
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2109
////Problem Title: 
////Run result: Accept
////Run time:15MS
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
	int n,i,c[100],j[100],sc,sj;
	while(scanf("%d",&n)!=EOF && n)
	{
		sc=sj=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&c[i]);
		}
		for(i=0;i<n;i++)
		{
			scanf("%d",&j[i]);
		}
		sort(c,n);
		sort(j,n);
		for(i=0;i<n;i++)
		{
			if(c[i]>j[i])
			{
				sc+=2;
			}
			else if(c[i]<j[i])
			{
				sj+=2;
			}
			else
			{
				sc++;
				sj++;
			}
		}
		printf("%d vs %d\n",sc,sj);
	}
	return 0;
}