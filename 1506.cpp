////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-02 15:57:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1506
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:2624KB
//////////////////System Comment End//////////////////

#include<stdio.h>
#include<algorithm>

using namespace std;
__int64 h[100002],l[100002],r[100002];
__int64 m,i,j;

int main()
{
	int t;
	while(scanf("%d",&t),t)
	{
		for(i=1;i<=t;i++)
		{
			scanf("%I64d",&h[i]);
			l[i]=i;
			r[i]=i;
		}
		h[0] = -1;
		h[t+1] = -1;
		l[0] = 1;
		r[t+1] = t;
		for(i=1;i<=t;i++)
		{
			while(h[l[i]-1]>=h[i])
			 l[i] = l[l[i]-1];
		}
		m = h[t]*(r[t]-l[t]+1);
		for(i=t;i>=1;i--)
		{
			while(h[r[i]+1]>=h[i])
			 r[i] = r[r[i]+1];
	 
 				m = max(m ,h[i]*(r[i]-l[i]+1));
		}
		printf("%I64d\n",m); 
	}
}