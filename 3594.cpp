////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-01 18:56:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3594
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1328KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 3594.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 01 Nov 2014 05:33:01 PM CST
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
const int maxn = 20010;

int T,n;
int first[maxn],next[50010],ver[50010],ecnt;
int dfn[maxn],low[maxn],vis[maxn],tot;

void Init(){
	memset(first,-1,sizeof(first));
	ecnt = 0;
}

void Add_edge(int u,int v){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	first[u] = ecnt;
}

bool Dfs(int p){
	dfn[p] = low[p] = ++tot;
	vis[p] = 1;
	int ac = 0,bc = 0;
	for(int i = first[p]; i != -1; i = next[i]){
		int v = ver[i];
		if(vis[v] == 2) return false;
		if(!dfn[v]){
			if(!Dfs(v)) return false;
			if(low[v] > dfn[p]) return false;
			if(low[v] < dfn[p]) ++ac;
			low[p] = min(low[p],low[v]);
		}
		else if(dfn[v] < dfn[p]){
			low[p] = min(low[p],dfn[v]);
			++bc;
		}
	}
	vis[p] = 2;
	if(ac + bc >= 2) return false;
	return true;
}

bool Tarjan(){
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(vis,0,sizeof(vis));
	tot = 0;
	for(int i = 1; i <= n; ++i) if(!dfn[i])
		if(!Dfs(i)) return false;
	return true;
}

int main(){
	int a,b;
	scanf("%d",&T);
	while(T--){
		Init();
		scanf("%d",&n);
		while(scanf("%d%d",&a,&b) != EOF && (a || b)){
			Add_edge(a,b);
		}
		if(Tarjan()) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
