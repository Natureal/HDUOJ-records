////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-03 23:23:25
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1555
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int i,m,k;
	while(scanf("%d%d",&m,&k)!=EOF && m||k)
	{
		i=0;
		while(m>0)
		{
			m--;
			i++;
			if(0==i%k)
				m++;
		}
		printf("%d\n",i);
	}
	return 0;
}