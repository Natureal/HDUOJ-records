////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-05-03 22:49:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3183
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:256KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 1000

char s[MAXN + 50];
int m,n,minsum[MAXN + 50][10];

int min(int a,int b)
{
	if(s[a] < s[b])
		return a;
	else if(s[a] == s[b])
		return a<b ? a:b;
	else
		return b;
}

int Query(int l,int r)
{
	int k = (int)(log((double)r - l + 1) / log(2.0));
	return min(minsum[l][k],minsum[r - (1 << k) + 1][k]);
}

int main()
{
	while(scanf("%s %d",s + 1,&m) != EOF)
	{
		n = strlen(s + 1);
		for(int i = 1; i <= n; ++i)
		{
			minsum[i][0] = i;
		}
		for(int j = 1;j <= 10; ++j)
		{
			for(int i = 1; i <= n; ++i)
			{
				if(i + (1 << j) - 1 <= n)
				{
					minsum[i][j] = min(minsum[i][j - 1],minsum[i + (1 << (j - 1))][j - 1]);
				}
			}
		}
		int pos = 1,ans[MAXN + 5],flag = 0,need = n - m;
		while(need)
		{
			pos = Query(pos,n - need + 1);
			ans[flag++] = s[pos] - '0';
			++pos;
			--need;
		}
		int cnt = 0;
		while(ans[cnt] == 0 && cnt < flag)
		{
			++cnt;
		}
		if(cnt == flag)
		{
			printf("0\n");
			continue;
		}
		for(;cnt < flag ; ++cnt)
		{
 			printf("%d",ans[cnt]);
		}
		puts("");
	}
	return 0;
}