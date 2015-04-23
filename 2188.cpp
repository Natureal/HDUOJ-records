////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-29 19:16:00
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2188
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int c,n,m;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&m);
		if(n<=m) printf("Grass\n");
		else
		{
			if(0==n%(m+1)) printf("Rabbit\n");
			else printf("Grass\n");
		}
	}
	return 0;
}