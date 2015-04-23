////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-28 19:32:01
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1220
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1220.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月28日 星期五 19时28分43秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",n*n*n*(n*n*n-1)/2-3*n*n*(n-1));
	}
	return 0;
}