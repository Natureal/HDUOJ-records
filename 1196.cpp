////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-02 21:49:13
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1196
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1196.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月02日 星期日 21时44分42秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		printf("%d\n",n&-n);
	}
	return 0;
}