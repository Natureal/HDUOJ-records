////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-29 21:21:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2189
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:272KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 150
int c1[200],c2[200];
void isprime(int arr[])
{
	int i,j,k,num;
	num=1;
	for(i=2;num<=150;i++)
	{
		k=sqrt(1.0*i);
		for(j=2;j<=k;j++)
		{
			if(0==i%j) break;
		}
		if(j>k)
		{
			arr[num++]=i;
		}
	}
	return;
}
int main()
{
	int i,j,k,c,n,prime[151];
	memset(prime,0,sizeof(prime));
	isprime(prime);
	memset(c1,0,sizeof(c1));
	memset(c2,0,sizeof(c2));
	for(i=0;i<=150;i+=prime[1])
	{
		c1[i]=1;
	}
	for(i=2;i<=75;i++)
	{
		for(j=0;j<=150;j++)
		{
			for(k=0;k+j<=150;k+=prime[i])
			{
				c2[j+k]+=c1[j];
			}
		}
		for(j=0;j<=150;j++)
		{
			c1[j]=c2[j];
     		c2[j]=0;
		}
	}
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d",&n);
		printf("%d\n",c1[n]);
	}
	return 0;
}