////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-06 14:47:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2899
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
const double d=1e-8;
double der(double x,double y)
{
	return 42*pow(x,6)+48*pow(x,5)+21*pow(x,2)+10*x-y;
}
double f(double x,double y)
{
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
int main()
{
	int t;
	double l,h,m,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&y);
		if(der(100.0,y)<=0.0)
		{
			printf("%.4lf\n",f(100.0,y));
			continue;
		}
		l=0.0;
		h=100.0;
		while(h-l>d)
		{
			m=l+((h-l)/2);
			if(der(m,y)<0.0)
			{
				l=m+d;
			}
			else
			{
				h=m-d;
			}
		}
		printf("%.4lf\n",f(m,y));
	}
	return 0;
}