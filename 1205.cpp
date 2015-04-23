////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-23 13:31:00
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1205
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1205.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: Sun 23 Feb 2014 01:12:05 PM CST
 ************************************************************************/

#include<stdio.h>
/*
void quick_sort(int s[],int l,int r)
{
	if(l<r)
	{
		int i=l,j=r,x=s[l];
		while(i<j)
		{
			while(i<j&&s[j]<=x)
				j--;
			if(i<j)s[i++]=s[j];

			while(i<j&&s[i]>x)
				i++;
			if(i<j)s[j--]=s[i];
		}
		s[i]=x;
		quick_sort(s,l,i-1);
		quick_sort(s,i+1,r);
	}
	return;
}*/
int main()
{
	long long sum;
	int n,t,max,num;
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		sum=0;
		scanf("%d",&n);
		while(n--)
		{
			scanf("%d",&num);
			sum+=num;
			max=max>num?max:num;
		}
		if((max-1)>(sum-max))
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}