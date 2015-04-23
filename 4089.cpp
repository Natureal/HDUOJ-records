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
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 2001;
const double eps = 1e-4;

int n,m,k;
double p1,p2,p3,p4;
double P2,P3,P4;
double dp[2][MAXN];
double pw[MAXN];

int main(){
	while(scanf("%d%d%d%lf%lf%lf%lf",&n,&m,&k,&p1,&p2,&p3,&p4) != EOF){
		if(fabs(p4) < eps || fabs(p1 - 1.0) < eps){
			printf("0.00000\n");
			continue;
		}
		P2 = p2 / (1.0 - p1);
		P3 = p3 / (1.0 - p1);
		P4 = p4 / (1.0 - p1);
		pw[0] = 1.0;
		for(int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * P2;
		MEM(dp,0);
		dp[1][1] = P4 / (1.0 - P2);
 		for(int i = 2; i <= n; ++i){
			int id = i&1;
			double cur = 0;
			for(int j = 1; j <= i - 1; ++j) cur += dp[id^1][j] * pw[i - j] * P3;
			for(int j = max(1,i - k + 1); j <= i - 1; ++j) cur += P4 * pw[j];
			dp[id][1] = (cur + P4) / (1.0 - pw[i]);
			for(int j = 2; j <= k; ++j)
				dp[id][j] = dp[id][j - 1] * P2 + dp[id^1][j - 1] * P3 + P4;
			for(int j = k + 1; j <= i; ++j)
				dp[id][j] = dp[id][j - 1] * P2 + dp[id^1][j - 1] * P3;
		}
		printf("%.5f\n",dp[n&1][m]);
	}
	return 0;
}
