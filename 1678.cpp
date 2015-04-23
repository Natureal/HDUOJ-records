////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-24 16:31:39
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1678
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:300KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1678.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月24日 星期一 16时14分09秒
 ************************************************************************/

#include<stdio.h>
void quick_sort(int s[],int l,int r)
{
	if(l<r)
	{
		int i=l,j=r,x=s[l];
		while(i<j)
		{
			while(i<j&&s[j]<x)
				j--;
			if(i<j)s[i++]=s[j];
			
			while(i<j&&s[i]>=x)
				i++;
			if(i<j)s[j--]=s[i];
		}
		s[i]=x;
		quick_sort(s,l,i-1);
		quick_sort(s,i+1,r);
	}
	return;
}
int main()
{
	int i,t,n,a[20001],sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
		}
		quick_sort(a,1,n);
		/*for(i=1;i<=n;i++)
		{
			printf(" %d\n",a[i]);
		}*/
		for(i=3;i<=n;i+=3)
		{
			sum+=a[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}