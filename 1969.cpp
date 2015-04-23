////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-06 22:19:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1969
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:284KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#define PI 2.0*acos(0.0)
const double EPS=1e-7;
int r[10000],n,f;
bool count(double x)
{
	int i,num=0;
	for(i=0;i<n;i++)
	{
		num+=r[i]/x;
	}
	if(num>=f+1)
		return true;
	else
		return false;
}
double cal(double max)
{
	double low=0,high=max,mid;
	while(high-low>EPS)
	{
		mid=low+(high-low)/2;
		if(count(mid))
		{
			low=mid;
		}
		else
		{
			high=mid;
		}
	}
	return mid;
}
int main()
{
	int t,i,max;
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		scanf("%d %d",&n,&f);
		for(i=0;i<n;i++)
		{
			scanf("%d",&r[i]);
			r[i]*=r[i];
			if(r[i]>max)
			{
				max=r[i];
			}
		}
		printf("%.4lf\n",PI*cal(max));
	}
	return 0;
}