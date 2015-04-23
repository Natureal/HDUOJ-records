////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-26 22:58:44
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1395
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,i,k;
	while(scanf("%d",&n)!=EOF)
	{
		if(0==n%2 || n==1)
		{
			printf("2^? mod %d = 1\n",n);
			continue;
		}
		k=1;
		for(i=1;;i++)
		{
			k=(k*2)%n;  //¼¼ÇÉ£¡
			if(1==k)
			{
				break;
			}
		}
		printf("2^%d mod %d = 1\n",i,n);
	}
	return 0;
}