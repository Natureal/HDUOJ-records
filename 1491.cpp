////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-02 23:52:20
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1491
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,month,day,sum;
	scanf("%d",&t);
	while(t--)
	{
		sum=0;
		scanf("%d%d",&month,&day);
		if(month==10 && day==21)
		{
			printf("It's today!!\n");
		}
		else if(month>10 || month==10 && day>21)
		{
			printf("What a pity, it has passed!\n");
		}
		else if(month==10)
		{
			printf("%d\n",21-day);
		}
		else
		{
			switch(month)
			{
			case 1:sum+=31;
			case 2:sum+=28;
			case 3:sum+=31;
			case 4:sum+=30;
			case 5:sum+=31;
			case 6:sum+=30;
			case 7:sum+=31;
			case 8:sum+=31;
			case 9:sum+=51;
			}
			sum-=day;
			printf("%d\n",sum);
		}
	}
	return 0;
}