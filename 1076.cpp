////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-07 00:34:53
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1076
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int check_leap(int );

int main()
{
	int	Y,N,T,count;

	while(scanf("%d",&T)!=EOF)
	{
		while(T--)
		{
			scanf("%d%d",&Y,&N);
			for(count=1;count<=N;Y++)
			{
				if(check_leap(Y)) count++;
			}
			Y--;
			printf("%d\n",Y);
		}
	}
	return 0;
}

int check_leap(int x)
{
	if((0 == x%4 && x%100 != 0)||0 == x%400)
	{
		return 1;
	}
	return 0;
}