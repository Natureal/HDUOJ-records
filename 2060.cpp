////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-15 14:30:07
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2060
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,num,sp,so;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&num,&sp,&so);
		if(num>6)
		{
			sp+=(8*(num-6)+27);
		}
		else
		{
			while(num--)
			{
				sp+=(7-num);
			}
		}
		if(sp>=so)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}