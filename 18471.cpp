////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-23 00:03:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1847
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int sg[1005],num[15];
void init()
{
	for(int i = 0; i <= 10; i++)
	{
		num[i] = 1 << i;
	}
	for(int i = 0; i <= 1000; i++)
	{
		if(!sg[i])
		{
			for(int j = 0; j <= 10; j++)
			{
				if(i + num[j] <= 1000)
					sg[i + num[j]] = 1;
			}
		}
	}
}
int main()
{
	int n;
	init();
	sg[1] = 1;
	while(scanf("%d",&n)!=EOF)
	{
		if(sg[n] == 1)
		{
			printf("Kiki\n");
		}
		else
		{
			printf("Cici\n");
		}
	}
	return 0;
}
