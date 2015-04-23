////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-16 00:33:05
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2039
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	double a,b,c;
	int m;
	while(scanf("%d",&m)!=EOF)
	{
		while(m--)
		{
			scanf("%lf %lf %lf",&a,&b,&c);
			if(a+b>c && a+c>b && b+c>a)
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
	return 0;
}