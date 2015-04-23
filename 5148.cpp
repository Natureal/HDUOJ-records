////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-20 22:15:42
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5148
////Problem Title: 
////Run result: Accept
////Run time:343MS
////Run memory:3080KB
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
const int INF = 1 << 28;
const int maxn = 4010;

int T,K,n;
int first[maxn],next[maxn],ver[maxn],w[maxn],ecnt;
ll dp[maxn][60];
ll siz[maxn];

void Init(){
	fill(dp[0],dp[0] + maxn * 60,INF);
	memset(first,-1,sizeof(first));
	ecnt = 0;
	dp[1][0] = 0;
}

void Add_edge(int u,int v,int fee){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	w[ecnt] = fee;
	first[u] = ecnt;
}

void Dfs(int p,int fa){
	siz[p] = 1;
	dp[p][1] = dp[p][0] = 0;
	for(int i = first[p]; i != -1; i = next[i]){
		int v = ver[i];
		if(v == fa) continue;
		Dfs(v,p);
		siz[p] += siz[v];
		for(int m = min(siz[p],(ll)K); m >= 0; --m){
			for(int j = 0; j <= m; ++j){
				dp[p][m] = min(dp[p][m],dp[p][m - j] + dp[v][j] + (ll)j * (K - j) * w[i]);
			}
		}
	}
}

int main(){
	int a,b,c;
	scanf("%d",&T);
	while(T--){
		Init();
		scanf("%d%d",&n,&K);
		for(int i = 1; i < n; ++i){
			scanf("%d%d%d",&a,&b,&c);
			Add_edge(a,b,c);
			Add_edge(b,a,c);
		}
		Dfs(1,0);
		printf("%I64d\n",dp[1][K] * 2);
	}
	return 0;
}
