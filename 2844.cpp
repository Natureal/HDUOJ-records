////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-04-01 22:31:04
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2844
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:1032KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define MAXN 100000
int dp[MAXN + 5],val[105],cnt[105],used[MAXN + 5];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		memset(dp,0,sizeof(dp));
		if(n == 0 && m == 0)
			break;
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d",&val[i]);
		}
		for(int i = 1 ; i <= n ; i++)
		{
			scanf("%d",&cnt[i]);
		}
		dp[0]=1;
		int count=0;
		for(int i = 1 ; i <= n ; i++)
		{
			memset(used,0,sizeof(used));
			for(int j = val[i] ; j <= m ; j++)
			{
				if(!dp[j] && dp[j-val[i]] && used[j-val[i]] < cnt[i])
				{
					dp[j]=1;
					used[j]=used[j-val[i]]+1;
					count++;
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}