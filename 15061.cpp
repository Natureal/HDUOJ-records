////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-02 16:53:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1506
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:2624KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 100000
__int64 h[MAXN+5],l[MAXN+5],r[MAXN+5];
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF && n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%I64d",&h[i]);
			l[i]=i;
			r[i]=i;
		}
		h[0] = -1;
		h[n+1] = -1;
		l[0] = 1;
		r[n+1] = n;
		for(int i=1;i<=n;i++)
		{
			while(h[l[i]-1] >= h[i])
			{  
				l[i] = l[l[i]-1];
			}
		}
		__int64 maxn=0;
		for(int i=n;i>=1;i--)
		{
			while(h[r[i]+1] >= h[i])
			{
				r[i] = r[r[i]+1];
			}
		}
		for(int i=1;i<=n;i++)
		{
			maxn=max(maxn,h[i]*(r[i]-l[i]+1));
		}
		printf("%I64d\n",maxn);
	}
	return 0;
}