////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-06 14:16:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2199
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
double f(double x)
{
	return 8*pow(x,4)+7*pow(x,3)+2*pow(x,2)+3*x+6;
}
int main()
{
	int t;
	double y,low,high,mid;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf",&y);
		if(f(0)<=y && y<=f(100))
		{
			low=0;
			high=100;
			while(high-low > 1e-6)
			{
				mid=low+((high-low)/2);
				if(f(mid)>y)
				{
					high=mid-1e-7;
				}
				else
				{
					low=mid+1e-7;
				}
			}
			printf("%.4lf\n",mid);
		}
		else
		{
			printf("No solution!\n");
		}
	}
	return 0;
}