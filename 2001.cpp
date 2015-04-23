////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-11-08 21:53:12
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2001
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:224KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
int main()
{
	double x1,y1,x2,y2,l;
	while(4==scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2))
	{
		l=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		printf("%.2lf\n",l);
	}
	return 0;
}
	