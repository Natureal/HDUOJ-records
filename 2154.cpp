////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-23 23:17:24
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2154
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2154.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: Sun 23 Feb 2014 09:09:14 PM CST
 ************************************************************************/

#include<stdio.h>
int n,i,result[1005];
int main()
{
	result[2]=2;
	result[3]=2;
	result[4]=6;
	for(i=5;i<=1000;i++)
	{
		result[i]=(result[i-1]+result[i-2]*2)%10000;
	}
	while(scanf("%d",&n)!=EOF && n)
	{
		printf("%d\n",result[n]);
	}
	return 0;
}