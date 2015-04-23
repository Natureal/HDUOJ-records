////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-14 18:43:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1029
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,time,re,num;
	while(scanf("%d",&n)!=EOF)
	{
		time=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num);
			if(0==time)
			{
				re=num;
				time++;
			}
			else
			{
				if(re==num) time++;
				else time--;
			}
		}
		printf("%d\n",re);
	}
	return 0;
}