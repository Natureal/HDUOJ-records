////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-07 15:04:36
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2111
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
void sort(int arr[],int m[],int n)
{
	int i,j,k,temp;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]>arr[k])
				k=j;
		}
		if(k!=i)
		{
			temp=arr[i];
			arr[i]=arr[k];
			arr[k]=temp;

			temp=m[i];
			m[i]=m[k];
			m[k]=temp;
		}
	}
	return;
}
int main()
{
	int i,v,n,p[100],m[100],sum;
	while(scanf("%d",&v)!=EOF && v)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d %d",&p[i],&m[i]);
		}
		sort(p,m,n);
		sum=0;
		for(i=0;i<n;i++)
		{
			if(v-m[i]>0)
			{
				sum+=p[i]*m[i];
				v-=m[i];
			}
			else if(v-m[i]<=0)
			{
				sum+=v*p[i];
				break;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}