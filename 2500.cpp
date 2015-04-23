////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-29 13:22:18
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2500
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,m,i,j;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&m);
		for(i=0;i<3*m;i++)
		{
			for(j=0;j<m;j++)
			{
				printf("HDU");
			}
			puts("");
		}
	}
	return 0;
}