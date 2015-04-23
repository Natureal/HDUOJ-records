////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-23 22:24:37
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2570
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:240KB
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
			if(arr[j]<arr[k]) k=j;
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
	int t,a[100],i,n,v,w,v2,count;
	double w2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&v,&w);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,n);
		v2=0;
		w2=0;
		count=0;
		for(i=0;i<n;i++)
		{
			if(((w2+a[i])/(i+1))>w) 
			{
				break;
			}
			w2+=a[i];
			v2+=v;
			count++;
		}
		if(v2==0) printf("0 0.00\n");
		else printf("%d %.2lf\n",v2,w2/count/100);
	}
	return 0;
}