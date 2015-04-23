////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-26 22:03:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1215
////Problem Title: 
////Run result: Accept
////Run time:281MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1215.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月26日 星期三 21时46分08秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
	int n,t,i,sum;
	int k;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d",&n);
		if(n==2)
		{
			printf("1\n");
			continue;
		}
		k=(int)sqrt(1.0*n);
		for(i=2;i<=k;i++)
		{
			if(0==n%i)
			{
				sum+=i;
				sum+=n/i;
			}
		}
		if(k*k==n)
			sum-=k;
		printf("%d\n",sum+1);
	}
	return 0;
}