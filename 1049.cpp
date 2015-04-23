////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-11 22:33:51
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1049
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:204KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int n,u,d,min;
	while(scanf("%d %d %d",&n,&u,&d) == 3 && n)
	{
	    min = 0;
		while(1)
		{
			n-=u;
			min++;
		   if( n <= 0 )
		  {
			printf("%d\n",min);
			break;
		  }
		  else
		  {
			min++;
			n+=d;
		  }
		}
	}
	return 0;
}