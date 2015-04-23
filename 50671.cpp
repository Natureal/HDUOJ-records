////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-18 22:57:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5067
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:276KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1002.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 18 Oct 2014 09:44:23 PM CST
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

int dp[11][(1 << 10) + 10];
int x[11],y[11];
int n,m,cnt;

int main(){
	int tmp;
	while(scanf("%d%d",&n,&m) != EOF){
		cnt = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				scanf("%d",&tmp);
				if(tmp){
					x[++cnt] = i;
					y[cnt] = j;
				}
			}
		}
		for(int i = 0; i <= cnt; ++i)
            for(int j = 0; j < (1 <<cnt); ++j)
                dp[i][j] = INF;
		for(int i = 1; i <= cnt; ++i)
            dp[i][(1 << (i - 1))] = x[i] + y[i] - 2;
        for(int j = 0; j < (1 << cnt); ++j)
            for(int i = 1; i <= cnt; ++i)
                for(int k = 1; k <= cnt; ++k)
					if(j & (1 << (k - 1)))
						dp[i][j] = min(dp[i][j],dp[k][j ^ (1 << (i - 1))] + abs(x[i] - x[k]) + abs(y[i] - y[k]));
		int ans = cnt == 0 ? 0 : INF;
		for(int i = 1; i <= cnt; ++i)
            ans = min(ans,dp[i][(1 << cnt) - 1] + x[i] + y[i] - 2);
        printf("%d\n",ans);
	}
	return 0;
}


