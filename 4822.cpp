////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-09 02:47:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4822
////Problem Title: 
////Run result: Accept
////Run time:2527MS
////Run memory:15936KB
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
const int MAXN = 200010;
const int MAX_LOG = 17;

int T,N,M;
int fa[MAX_LOG][MAXN],dep[MAXN],sz[MAXN];
int first[MAXN],ecnt;

struct edge{
	int v,next;
}e[MAXN << 1];	

void Add_edge(int u,int v){
	e[++ecnt].next = first[u];
	e[ecnt].v = v;
	first[u] = ecnt;
}

void Dfs(int p,int pre,int d){
	fa[0][p] = pre;
	dep[p] = d;
	sz[p] = 1;
	for(int i = first[p]; ~i; i = e[i].next){
		int v = e[i].v;
		if(v == pre) continue;
		Dfs(v,p,d + 1);
		sz[p] += sz[v];
	}
}

void Pre(){
	Dfs(1,-1,0);
	for(int k = 0; k + 1 < MAX_LOG; ++k){
		for(int v = 1; v <= N; ++v){
			if(fa[k][v] < 0) fa[k + 1][v] = -1;
			else fa[k + 1][v] = fa[k][fa[k][v]];
		}
	}
}

int Up(int u,int len){
	for(int k = MAX_LOG - 1; k >= 0; --k)
		if(len & (1 << k))
			u = fa[k][u];
	return u;
}

int Lca(int u,int v){
	if(dep[u] > dep[v]) swap(u,v);
	v = Up(v,dep[v] - dep[u]);
	if(u == v)
		return u;
	for(int k = MAX_LOG - 1; k >= 0; --k){
		if(fa[k][u] != fa[k][v]){
			u = fa[k][u];
			v = fa[k][v];
		}
	}
	return fa[0][u];
}

int Getmid(int u,int v){
	int len = dep[u] + dep[v] - (dep[Lca(u,v)] << 1);
	if(dep[u] >= dep[v])	return Up(u,(len - 1) / 2);
	else	return Up(v,len / 2);
}

int Solve(int a,int b,int c,int ab,int ac){
	int m_ab = Getmid(a,b),m_ac = Getmid(a,c);
	int lca = Lca(m_ab,m_ac);
	//printf("(%d,%d,%d) : mid : %d %d , lca : %d\n",a,b,c,m_ab,m_ac,lca);
	if(dep[a] >= dep[b] && dep[a] >= dep[c]){
		//printf("1\n");
		if(dep[m_ab] < dep[m_ac]) swap(m_ab,m_ac);
		return (lca == m_ac) ? sz[m_ab] : 0;
	}
	if(dep[a] < dep[b] && dep[a] < dep[c]){
		//printf("2\n");
		if(dep[m_ab] < dep[m_ac]) swap(m_ab,m_ac);
		if(lca == m_ac) return N - sz[m_ac];
		return N - sz[m_ab] - sz[m_ac];
	}
	else{
		//printf("3\n");
		if(dep[a] >= dep[b]) swap(m_ab,m_ac);
		if(lca == m_ac)
			return sz[m_ac] - sz[m_ab];
		else if(lca == m_ab)
			return N - sz[m_ab];
		return sz[m_ac];
	}
}

int main(){
	int a,b,c;
	scanf("%d",&T);
	REP(tt,T){
		MEM(first,-1);
		ecnt = 0;
		scanf("%d",&N);
		REP(i,N - 1){
			scanf("%d%d",&a,&b);
			Add_edge(a,b);
			Add_edge(b,a);
		}
		Pre();
		scanf("%d",&M);
		REP(i,M){
			scanf("%d%d%d",&a,&b,&c);
			int ab = Lca(a,b),ac = Lca(a,c),bc = Lca(b,c);
			//printf("a,b,c : %d %d %d , ab,ac,bc : %d %d %d\n",a,b,c,ab,ac,bc);
			int ans1 = Solve(a,b,c,ab,ac);
			int ans2 = Solve(b,a,c,ab,bc);
			int ans3 = Solve(c,a,b,ac,bc);
			printf("%d %d %d\n",ans1,ans2,ans3);
		}
	}
	return 0;
}
