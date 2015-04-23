////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2013-12-18 14:23:51
////Compiler: Visual C
//////////////////////////////////////////////////////
////Problem ID: 2080
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define PI 3.141592653
struct POINT
{
	double x;
	double y;
};
int main()
{
	int t;
	double angle,m,n,l;
	struct POINT a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
		m=sqrt(a.x*a.x+a.y*a.y);
		n=sqrt(b.x*b.x+b.y*b.y);
		l=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
		angle=acos((m*m+n*n-l*l)/(2*m*n));
		printf("%.2lf\n",angle*180/PI);
	}
	return 0;
}