////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-14 20:28:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1003
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:648KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define MAX 100005

int sum,max,num[MAX];
int start,end,te,ts;
void cal(int n)
{
	int i;
	sum=max=-99999;
	for(i=0;i<n;i++)
	{
		if(sum<0)
		{
			if(num[i]>sum)
			{
				sum=num[i];
				ts=te=i;
				if(sum>max)
				{
					max=sum;
					start=ts;
					end=te;
				}
			}
		}
		else
		{
			sum+=num[i];
			te=i;
			if(sum>max)
			{
				max=sum;
				start=ts;
				end=te;
			}
		}
	}
}
int main()
{
	int i,j,n,t;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%d",num+j);
		}
		cal(n);
		printf("Case %d:\n%d %d %d\n",i,max,start+1,end+1);
		if(i!=t)puts("");
	}
	return 0;
}