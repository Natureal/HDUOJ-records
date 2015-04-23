////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-24 22:33:00
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1290
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1290.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月24日 星期一 22时30分25秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",(n*n*n+5*n)/6+1);
	}
	return 0;
}