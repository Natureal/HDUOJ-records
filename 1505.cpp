////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-12 17:29:11
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1505
////Problem Title: 
////Run result: Accept
////Run time:921MS
////Run memory:8140KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <iostream>
using namespace std;
#define MAXN 1000
char map[MAXN + 5][2*(MAXN + 5)];
__int64 h[MAXN + 5][MAXN + 5],l[MAXN + 5],r[MAXN + 5];
int m,n;
void Cal()
{
	int i,j;
	for(i = 1;i <= m;i ++)
	{
		for(j = 1;j <= n;j ++)
		{
			int th = 0;
			while(i + th <= m && h[i + th][j] == 1)
			{
				th ++;
			}
			h[i][j] = th;
		}
	}
	return;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int k,i,j;
	char arr[5];
	scanf("%d",&k);
	while(k --)
	{
		scanf("%d %d",&m,&n);
		getchar();
		for(i = 1;i <= m;i ++)
		{
			for(j = 1;j <= n;j ++)
			{
				scanf("%s",arr);
				if(arr[0] == 'F')
					h[i][j] = 1;
				else
					h[i][j] = 0;
			}
		}
		Cal();
		__int64 maxs = 0;
		for(i = 1;i <= m;i ++)
		{
			h[i][0] = h[i][n + 1] = -1;

			for(j = 1;j <= n;j ++) l[j] = r[j] = j;

			for(j = 1;j <= n;j ++)
			{
				while(h[i][l[j] - 1] >= h[i][j])
				{
					l[j] = l[l[j] - 1];
				}
			}
			for(j = 1;j <= n;j ++)
			{
				while(h[i][r[j] + 1] >= h[i][j])
				{
					r[j] = r[r[j] + 1];
				}
			}
			for(j = 1;j <= n;j ++)
			{
				maxs = max(maxs,h[i][j]*(r[j] - l[j] + 1));
			}
		}
		printf("%I64d\n",3 * maxs);
	}
	return 0;
}