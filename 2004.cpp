////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-14 23:15:28
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2004
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int g;
	while(scanf("%d",&g)!=EOF)
	{
		if(g<0 || g>100)
			printf("Score is error!\n");
		else if(g>=90 && g<=100)
			printf("A\n");
		else if(g>=80)
			printf("B\n");
		else if(g>=70)
			printf("C\n");
		else if(g>=60)
			printf("D\n");
		else if(g>=0)
			printf("E\n");
	}
	return 0;
}