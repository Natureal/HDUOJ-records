////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-25 21:45:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1273
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1273.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月25日 星期二 21时40分51秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		printf("%d\n",(n-1)/2);
	}
	return 0;
}