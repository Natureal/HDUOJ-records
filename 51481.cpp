////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-20 23:29:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5148
////Problem Title: 
////Run result: Accept
////Run time:234MS
////Run memory:3116KB
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
const ll INF = 100000000000000000LL;
const int maxn = 4010;

ll T,K,n;
ll first[maxn],next[maxn],ver[maxn],ecnt;
ll dp[maxn][60],w[maxn];
ll siz[maxn];

void Init(){
    fill(dp[0],dp[0] + maxn * 60,INF);
	memset(first,-1,sizeof(first));
	ecnt = 0;
}

void Add_edge(ll u,ll v,ll fee){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	w[ecnt] = fee;
	first[u] = ecnt;
}

void Dfs(ll p,ll fa){
	siz[p] = 1;
	dp[p][1] = dp[p][0] = 0;
	for(ll i = first[p]; i != -1; i = next[i]){
		ll v = ver[i];
		if(v == fa) continue;
		Dfs(v,p);
		siz[p] += siz[v];
		for(ll m = min(siz[p],(ll)K); m >= 0; --m){
			for(ll j = 0; j <= m; ++j){
				dp[p][m] = min(dp[p][m],dp[p][m - j] + dp[v][j] + (ll)j * (K - j) * w[i]);
			}
		}
	}
}

int main(){
	ll a,b,c;
	scanf("%I64d",&T);
	while(T--){
		Init();
		scanf("%I64d%I64d",&n,&K);
		for(ll i = 1; i < n; ++i){
			scanf("%I64d%I64d%I64d",&a,&b,&c);
			Add_edge(a,b,c);
			Add_edge(b,a,c);
		}
		Dfs(1,0);
		printf("%I64d\n",dp[1][K] * 2);
	}
	return 0;
}
