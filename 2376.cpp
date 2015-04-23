////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-01 01:45:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2376
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1600KB
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
const int maxn = 10010;

int T,n;
int first[maxn],next[maxn << 1],ver[maxn << 1],w[maxn << 1],ecnt;
int sz[maxn],total;
double ans;

void Init(){
	memset(first,-1,sizeof(first));
	ecnt = 0;
}

void Add_edge(int u,int v,int c){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	w[ecnt] = c;
	first[u] = ecnt;
}

void Dfs(int p,int fa){
	sz[p] = 1;
	for(int i = first[p]; ~i; i = next[i]){
		int v = ver[i];
		if(v == fa) continue;
		Dfs(v,p);
		ans += (double)sz[v] * (n - sz[v]) * w[i] / total;
		sz[p] += sz[v];
	}
}

int main(){
	int a,b,c;
	scanf("%d",&T);
	while(T--){
		Init();
		scanf("%d",&n);
		total = n * (n - 1) / 2;
		for(int i = 1; i < n; ++i){
			scanf("%d%d%d",&a,&b,&c);
			Add_edge(a,b,c);
			Add_edge(b,a,c);
		}
		ans = 0.0;
		Dfs(0,-1);
		printf("%.10f\n",ans);
	}
	return 0;
}
