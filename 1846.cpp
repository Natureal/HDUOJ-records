////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-17 21:07:51
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1846
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int c,n,m;
	scanf("%d",&c);
	while(c --)
	{
		scanf("%d %d",&n,&m);
		if(n % (m + 1) == 0)
		{
			printf("second\n");
		}
		else
			printf("first\n");
	}
	return 0;
}