////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-16 15:16:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1160
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <functional>
using namespace std;
typedef struct mouse
{
	int w,s,num;
}mouse;
mouse m[1005];
int dp[1005],index[1005];
bool cmp(mouse a,mouse b)
{
	if(a.w == b.w)
		return a.s > b.s;
	else
		return a.w < b.w;
}
//void print(int pos)
//{
//	if(index[pos] != pos)
//	{
//		print(index[pos]);
//		printf("%d\n",pos + 1);
//	}
//	else
//		printf("%d\n",pos + 1);
//	return;
//}
int main()
{
	//freopen("in.txt","r",stdin);
	int count = 1,i,j;
	while(scanf("%d %d",&m[count].w,&m[count].s)!=EOF)
	{
		//if(m[count].w == 0) break;
		m[count].num = count;
		count ++;
	}
	//count刚好表示了mice的个数
	sort(m + 1,m + count,cmp);
	for(i = 0;i <= count;i ++)
	{
		dp[i] = 1;
		index[i] = -1;
	}
	for(i = 2;i <= count;i ++)
	{
		for(j = 1;j < i;j ++)
		{
			if(m[j].w < m[i].w && m[j].s > m[i].s)
			{
				if(dp[j] + 1 > dp[i])
				{
					dp[i] = dp[j] + 1;
					index[m[i].num] = m[j].num;
				}
			}
		}
	}
	int maxn = -1,mark;
	for(i = 1;i <= count;i ++)
	{
		if(dp[i] > maxn)
		{
			maxn = dp[i];
			mark = m[i].num;
		}
	}
	printf("%d\n",maxn);
	int a[1005];
	for(i = maxn;i >= 1;i --)
	{
		a[i] = mark;
		mark = index[mark];
	}
	for(i = 1;i <= maxn;i ++)
	{
		printf("%d\n",a[i]);
	}
	//print(mark);
	return 0;
}