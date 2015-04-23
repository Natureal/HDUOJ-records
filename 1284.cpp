////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-28 23:05:07
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1284
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n;
	int i,num;
	while(scanf("%d",&n)!=EOF)
	{
		num=0;
		for(i=0;i*3<=n;i++)
		{
			num+=((n-i*3)/2+1);
		}
		printf("%d\n",num);
	}
	return 0;
}