////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-26 22:23:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1393
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int s,d,count;
	while(scanf("%d%d",&s,&d)!=EOF && s||d)
	{
		count=0;
		while(s!=0)
		{
			if(count>=61)    //每次进位最少的是1，所以如果循环61次还没有到0，就永远到不了0了。（前提是整数情况下）
			{
				printf("Impossible\n");
				break;
			}
			s=s+s*d;
			s=s%60;
			count++;
		}
		if(count<61)
		{
		printf("%d\n",count);
		}
	}
	return 0;
}
