////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-08 23:04:01
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2005
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,n,year,moth,day,a[]={31,28,31,30,31,30,31,31,30,31,30,31};
	while(scanf("%d/%d/%d",&year,&moth,&day)!=EOF)
	{	
		if(moth > 2 && ((year % 400 == 0) || (year % 100 != 0) && (year % 4 == 0)))
		  day += 1;
		for(n = i = 0;i<moth-1;i++)
		  n += a[i];
		printf("%d\n",n + day);
	}
	return 0;
}