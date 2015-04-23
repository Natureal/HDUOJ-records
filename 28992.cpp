////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-06 19:38:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2899
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
const double EPS=1e-6;
double f(double x,double y)
{
    return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
int main()
{
	int t;
	double high,low,mid,midmid,y;
	double mid_value,midmid_value;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&y);
		low=0.0;
		high=100.0;
		while(high-low>EPS)
		{
			mid=low+((high-low)/2);
			midmid=mid+((high-mid)/2);
			//lm=(2*low+high)/3;
			//rm=(low+2*high)/3;
			mid_value=f(mid,y);
			midmid_value=f(midmid,y);
			if(mid_value<midmid_value)//这题是求最小值，要看清楚！
				high=midmid;
			else
				low=mid;
		}
		printf("%.4lf\n",mid_value);
	}
	return 0;
}