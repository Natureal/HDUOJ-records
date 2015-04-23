////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-01-07 11:01:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1551
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <stdio.h>
double len[10005],max;
int n,k;

bool count(double mid)
{
	int i,num=0;
	for(i=1;i<=n;i++)
	{
		num+=len[i]/mid;
	}
	if(num>=k)
		return true;
	else
		return false;
}

double cal()
{
	double low=0,high=max,mid;
	while(high-low>1e-4)
	{
		mid=low+(high-low)/2;
		if(count(mid))
			low=mid;
		else
			high=mid;
	}
	return mid;
}

int main()
{
	int i;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		if(n==0 && k==0)
		{
			break;
		}
		max=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lf",&len[i]);
			if(len[i]>max) max=len[i];
		}
		printf("%.2lf\n",cal());
	}
	return 0;
}
	