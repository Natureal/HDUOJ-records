////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-24 22:25:19
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1249
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1249.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年02月24日 星期一 22时17分15秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int i,t,n,re[10005];
	re[1]=2;
	for(i=2;i<=10000;i++)
	{
		re[i]=re[i-1]+6*(i-1);
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",re[n]);
	}
	return 0;
}