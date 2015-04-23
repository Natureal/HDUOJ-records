////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-01 01:21:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2521
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int num(int n)
{
	int i,num=0;
	for(i=1;i<=n;i++)
	{
		if(0==n%i)
			num++;
	}
	return num;
}
int main()
{
	int a,b,t,i,count,re,number;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d %d",&a,&b);
		for(i=a;i<=b;i++)
		{
			number=num(i);
			if(number>count)
			{
				count=number;
				re=i;
			}
		}
		printf("%d\n",re);
	}
	return 0;
}