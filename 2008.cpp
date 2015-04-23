////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-14 23:29:11
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2008
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	double i;
	int n,s1,s2,s3;
	while(scanf("%d",&n)!=EOF && n)
	{
		s1=s2=s3=0;
		while(n--)
		{
			scanf("%lf",&i);
			if(i<0)
				s1++;
			else if(0==i)
				s2++;
			else
				s3++;
		}
		printf("%d %d %d\n",s1,s2,s3);
	}
	return 0;
}