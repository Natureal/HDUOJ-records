////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-08 23:19:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2586
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:8224KB
//////////////////System Comment End//////////////////
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
const int MAXN = 40010;
const int MAX_LOG = 16;

int T,n,m;
int first[MAXN],ecnt;
int fa[MAX_LOG][MAXN],dep[MAXN];
ll dis[MAXN];

struct edge{
	int v,next,w;
}e[MAXN << 1];

void Add_edge(int u,int v,int c){
	e[++ecnt].next = first[u];
	e[ecnt].v = v;
	e[ecnt].w = c;
	first[u] = ecnt;
}

void Dfs(int p,int pre,int d){
	fa[0][p] = pre;
	dep[p] = d;
	for(int i = first[p]; ~i; i = e[i].next){
		int v = e[i].v;
		if(v == pre) continue;
		dis[v] = dis[p] + e[i].w;
		Dfs(v,p,d + 1);
	}
}
	
void Pre(){
	dis[1] = 0;
	Dfs(1,-1,0);
	for(int k = 0; k + 1 < MAX_LOG; ++k){
		for(int v = 1; v <= n; ++v){
			if(fa[k][v] < 0) fa[k + 1][v] = -1;
			else fa[k + 1][v] = fa[k][fa[k][v]];
		}
	}
}

int Lca(int u,int v){
	if(dep[u] > dep[v]) swap(u,v);
	for(int k = MAX_LOG - 1; k >= 0; --k){
		if((dep[v] - dep[u]) & (1 << k))
			v = fa[k][v];
	}
	if(u == v) return u; //u为v的根
	for(int k = MAX_LOG - 1; k >= 0; --k){
		if(fa[k][u] != fa[k][v]){
			u = fa[k][u];
			v = fa[k][v];
		}
	}
	return fa[0][u]; //u离lca只差一步
}

int main(){
	int a,b,c;
	scanf("%d",&T);
	REP(tt,T){
		MEM(first,-1);
		ecnt = 0;
		scanf("%d%d",&n,&m);
		REP(i,n - 1){
			scanf("%d%d%d",&a,&b,&c);
			Add_edge(a,b,c);
			Add_edge(b,a,c);
		}
		Pre();
		REP(i,m){
			scanf("%d%d",&a,&b);
			int lca = Lca(a,b);
			printf("%I64d\n",dis[a] + dis[b] - (dis[lca] << 1));
		}
	}
	return 0;
}

