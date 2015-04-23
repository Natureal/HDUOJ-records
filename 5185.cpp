////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 19:30:22
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5185
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:44480KB
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
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int T,n,m;
int dp[320][50010];

int main(){
	scanf("%d",&T);
	REP(tt,T){
		scanf("%d%d",&n,&m);
		int top = sqrt(2.0 * n);
		dp[0][0] = 1;
		REP(i,top){
			int up = min(n,i * n);
			for(int j = i * (i + 1) / 2; j <= up; ++j){
				dp[i][j] = (dp[i][j - i] + dp[i - 1][j - i]) % m;
				//printf("dp[%d][%d] : %d\n",i,j,dp[i][j]);
			}
		}
		int ans = 0;
		REP(i,top) ans = (ans + dp[i][n]) % m;
		printf("Case #%d: %d\n",tt,ans);
	}
	return 0;
}
