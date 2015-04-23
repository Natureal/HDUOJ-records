////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-24 17:35:10
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1286
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:372KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1286.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月24日 星期一 16时47分44秒
 ************************************************************************/

#include<stdio.h>
int n,prime[32800],re[32800];
int eular(int n)
{
	int i,j;
	double temp=n;
	for(i=2;i<=n;i++)
	{
		if(prime[i] && 0==n%i)
		{
			temp/=i;
			temp*=(i-1);
		}
	}
	return (int)temp;
}
int main()
{
	int t,i,j,n;
	for(i=2;i<32800;i++)
	{
		prime[i]=1;
	}
	for(i=2;i*i<32800;i++)
	{
		for(j=i*i;j<32800;j+=i)
		{
			prime[j]=0;
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",eular(n));
	}
	return 0;
}