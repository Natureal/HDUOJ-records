////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-02-21 17:00:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1224
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
int map[105][105],pre[105],dp[105],inst[105];
void output(int x)
{
	if(x==-1)
		return;
	output(pre[x]);
	printf("%d->",x);
}
int main()
{
	int t,ti,n,m,i,j,a,b;
	scanf("%d",&t);
	for(ti=1;ti<=t;ti++)
	{
		scanf("%d",&n);
		//------------------
		//init
		for(i=1;i<=n+1;i++)
		{
			for(j=1;j<=n+1;j++)
			{
				map[i][j]=-1;
			}
		}
		for(i=1;i<=n;i++)
			scanf("%d",&inst[i]);
		inst[n+1]=0;
		for(i=1;i<=n+1;i++)
			dp[i]=0;
		pre[1]=-1;
		//-------------------
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d%d",&a,&b);
			map[a][b]=inst[b];
		}
		for(i=1;i<=n+1;i++)
		{
			for(j=1;j<i;j++)
			{
				if(map[j][i]!=-1&&dp[i]<dp[j]+map[j][i])
				{
					dp[i]=dp[j]+map[j][i];
					pre[i]=j;
				}
			}
		}
		//output
		if(ti!=1)
			printf("\n");
		printf("CASE %d#\n",ti);
		printf("points : %d\n",dp[n+1]);
		printf("circuit : ");
		output(pre[n+1]);
		printf("1\n");
	}
	return 0;
}