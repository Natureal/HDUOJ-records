////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-03 23:28:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1562
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t,a,b,c,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&c);
		for(x=1000;x<10000;x++)
		{
			if(0==x%a && 0==(x+1)%b && 0==(x+2)%c)
				break;
		}
		if(x>=10000)
			printf("Impossible\n");
		else
			printf("%d\n",x);
	}
	return 0;
}