////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-02 17:23:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3853
////Problem Title: 
////Run result: Accept
////Run time:2480MS
////Run memory:32748KB
//////////////////System Comment End//////////////////
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
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int maxn = 1010;

int R,C;
double g[maxn][maxn][3];
double dp[maxn][maxn];

int main(){
	while(scanf("%d%d",&R,&C) != EOF){
		for(int i = 1; i <= R; ++i){
			for(int j = 1; j <= C; ++j){
				scanf("%lf%lf%lf",&g[i][j][0],&g[i][j][1],&g[i][j][2]);
			}
		}
		//memset(dp,0,sizeof(dp));
		for(int i = 1; i <= R; ++i)
			for(int j = 1; j <= C; ++j)
				dp[i][j] = -1.0;
		dp[R][C] = 0.0;
		for(int i = R; i >= 1; --i){
			for(int j = C; j >= 1; --j){
				if(i == R && j == C) continue;
				double top = 2.0 * g[i][j][0];
				double bot = (1.0 - g[i][j][0]);
				if(j < C && dp[i][j + 1] != -1.0){
					top += g[i][j][1] * (dp[i][j + 1] + 2.0);
				}
				if(i < R && dp[i + 1][j] != -1.0){
					top += g[i][j][2] * (dp[i + 1][j] + 2.0);
				}
				if(bot) dp[i][j] = top / bot;
				//printf("dp[%d][%d] : %.3f\n",i,j,dp[i][j]);
			}
		}
		printf("%.3f\n",dp[1][1]);
	}
	return 0;
}



