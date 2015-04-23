////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-23 20:49:35
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 2153
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2153.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: Sun 23 Feb 2014 08:12:42 PM CST
 ************************************************************************/

#include<stdio.h>
int main()
{
	int n,i,j,num1,num2;
	while(scanf("%d",&n)!=EOF && n)
	{
		num1=1;
		num2=4*(n-1);
		for(i=1;i<=n;i++)
		{
			printf("%3d",num1++);
		}
		puts("");
		for(i=2;i<=n-1;i++)
		{
			printf("%3d",num2--);
			for(j=1;j<=n-2;j++)
			{
				printf("   ");
			}
			printf("%3d\n",num1++);
		}
		for(i=1;i<=n;i++)
		{
			printf("%3d",num2--);
		}
		puts("");
	}
	return 0;
}