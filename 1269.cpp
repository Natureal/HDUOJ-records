////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-12 02:14:12
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1269
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1392KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1269.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 12 Oct 2014 01:11:38 AM CST
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
const int maxn = 10010;

int n,m;
stack<int> S;
vector<int> G[maxn];
int tot,dfn[maxn],sc[maxn],scnt,low[maxn];

void Dfs(int p){
	dfn[p] = low[p] = ++tot;
	S.push(p);
	for(int i = 0; i < G[p].size(); ++i){
		int v = G[p][i];
		if(!dfn[v]){
			Dfs(v);
			low[p] = min(low[p],low[v]);
		}
		else if(!sc[v])
			low[p] = min(low[p],dfn[v]);
	}
	if(low[p] == dfn[p]){
		scnt++;
		while(1){
			int x = S.top(); S.pop();
			sc[x] = scnt;
			if(x == p) break;
		}
	}
}
	
int main(){
	int a,b;
	while(scanf("%d%d",&n,&m) != EOF){
		if(!n && !m)
			break;
		for(int i = 1; i <= n; ++i) G[i].clear();
		for(int i = 1; i <= m; ++i){
			scanf("%d%d",&a,&b);
			G[a].push_back(b);
		}
		memset(dfn,0,sizeof(dfn));
		memset(sc,0,sizeof(sc));
		tot = 0;
		scnt = 0;
		while(!S.empty()) S.pop();
		for(int i = 1; i <= n; ++i){
			if(!dfn[i]) Dfs(i);
		}
		if(scnt > 1) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
		