////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-23 23:34:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5074
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:264KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1005.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Wed 22 Oct 2014 03:07:01 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
const int INF = 1 << 30;

int T;
int n,m;
int g[55][55];
int a[105];
int dp[105][55];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= m; ++j)
				scanf("%d",&g[i][j]);
		for(int i = 1; i <= n; ++i)
			scanf("%d",a + i);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
				dp[i][j] = -INF;
		if(a[1] == -1)
			for(int j = 1; j <= m; ++j)
				dp[1][j] = 0;
		else
			dp[1][a[1]] = 0;
		int ans = 0;
		for(int i = 2; i <= n; ++i){
			if(a[i] != -1){
				for(int k = 1; k <= m; ++k){
					dp[i][a[i]] = max(dp[i][a[i]],dp[i - 1][k] + g[k][a[i]]);
				}
				ans = max(ans,dp[i][a[i]]);
			}
			else{
				for(int j = 1; j <= m; ++j){
					for(int k = 1; k <= m; ++k){
						dp[i][j] = max(dp[i][j],dp[i - 1][k] + g[k][j]);
					}
					ans = max(ans,dp[i][j]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
