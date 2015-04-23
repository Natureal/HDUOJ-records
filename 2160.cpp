////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-24 00:09:16
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2160
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2160.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月23日 星期日 23时49分21秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int num[25];
	int i,j,n,t;
	num[1]=1;
	num[2]=2;
	num[3]=3;
	for(i=4;i<=20;i++)
	{
		num[i]=num[i-1]*2-num[i-3];
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",num[n]);
	}
	return 0;
}