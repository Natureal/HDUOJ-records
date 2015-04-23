////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-14 23:22:35
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2006
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,p;
	while(scanf("%d",&n)!=EOF)
	{
		p=1;
		while(n--)
		{
			scanf("%d",&i);
			if(i%2!=0)
				p=p*i;
		}
		printf("%d\n",p);
	}
	return 0;
}