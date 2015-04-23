////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-03-13 22:53:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2178
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:268KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2178.c
    > Author: cpu
    > email: 564374850@qq.com
    > Created Time: 2014年03月13日 星期四 22时47分15秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",(int)pow(2.0,n)-1);
	}
	return 0;
}