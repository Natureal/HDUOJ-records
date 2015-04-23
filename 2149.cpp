////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-17 21:53:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2149
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int m,n,s;
	while(scanf("%d %d",&n,&m) != EOF)//共n，一次最多取m
	{
		s = n - n / (m + 1) * (m + 1);
		if(s)//s <= m
		{
			if(n <= m)
			{
				printf("%d",n);
				for(int i = n + 1;i <= m;i ++)
					printf(" %d",i);
				puts("");
			}
			else
				printf("%d\n",s);
		}
		else
			printf("none\n");
	}
}