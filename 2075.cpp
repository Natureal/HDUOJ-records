////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-19 17:20:15
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2075
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>
int main()
{
	int t;
	double f,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf",&a,&b);
		f=a/b;
		if((int)f==f)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}