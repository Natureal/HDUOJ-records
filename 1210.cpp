////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-01 14:52:30
////Compiler: GUN C
//////////////////////////////////////////////////////
////Problem ID: 1210
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1210.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月01日 星期六 14时46分26秒
 ************************************************************************/

#include<stdio.h>
int main()
{
	int n,i,count;
	while(scanf("%d",&n)!=EOF)
	{
		i=1;
		count=0;
		while(1)
		{
			if(i<=n)
				i*=2;
			else
				i=2*(i-n)-1;
			count++;
			if(i==1)
				break;
		}
		printf("%d\n",count);
	}
	return 0;
}