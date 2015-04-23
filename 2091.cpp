////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-20 23:54:35
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2091
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	char c;
	int n,i,j,count=0;
	while(scanf("%c%d",&c,&n)!=EOF && c!='@')
	{
		getchar();
		if(count)
			printf("\n");
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<n-i-1;j++)
				printf(" ");
			if(0==i)
			{
				printf("%c\n",c);
			}
			else
			{
				printf("%c",c);
			for(j=0;j<(2*i-1);j++)
				printf(" ");
			printf("%c\n",c);
			}
		}
		for(i=0;i<(2*n-1);i++)
		{
			printf("%c",c);
		}
		printf("\n");
		count=1;
	}
	return 0;
}