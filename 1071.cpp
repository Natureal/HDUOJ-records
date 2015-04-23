////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-07 16:53:37
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 1071
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
double x1,x2,x3,y1,y2,y3,a,b,c,k,e;
double f(double x)
{
	return a*x*x*x/3-(a*b+k/2)*x*x+(a*b*b+c-e)*x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf",&x1,&y1);
		scanf("%lf%lf",&x2,&y2);
		scanf("%lf%lf",&x3,&y3);
		a=(y2-y1)/((x2-x1)*(x2-x1));
		b=x1;
		c=y1;
		k=(y2-y3)/(x2-x3);
		e=y2-k*x2;
		printf("%.2lf\n",f(x3)-f(x2));
	}
	return 0;
}