////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-15 00:12:33
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2014
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
void sort(int a[],int l);
int main()
{
	int i,n,a[100],sum;
	double g;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,n);
		for(i=1,sum=0;i<n-1;i++)
		{
			sum+=a[i];
		}
		g=sum/(1.0*n-2);
		printf("%.2lf\n",g);
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
			if(a[j]<a[k])
				k=j;
		}
		if(k!=i)
		{
			temp=a[i];
			a[i]=a[k];
			a[k]=temp;
		}
	}
	return;
}
