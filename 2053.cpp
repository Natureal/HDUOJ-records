////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-17 21:41:52
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2053
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,count;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		for(i=1;i<=n;i++)
		{
			if(0==n%i)
				count++;
		}
		count=count%2;
		printf("%d\n",count);
	}
	return 0;
}