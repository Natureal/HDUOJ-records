////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-14 02:19:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2767
////Problem Title: 
////Run result: Accept
////Run time:125MS
////Run memory:1788KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 2767.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Tue 14 Oct 2014 12:54:49 AM CST
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

int first[maxn],next[maxn * 3],ver[maxn * 3],ecnt;
int dfn[maxn],low[maxn],sc[maxn],tot,scnt,din[maxn],dout[maxn];
int n,m,T;
stack<int> S;

void Add_edge(int u,int v){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	first[u] = ecnt;
}

void Dfs(int p){
	dfn[p] = low[p] = ++tot;
	S.push(p);
	for(int i = first[p]; i != -1; i = next[i]){
		int v = ver[i];
		if(!dfn[v]){
			Dfs(v);
			low[p] = min(low[p],low[v]);
		}
		else if(!sc[v]){
			low[p] = min(low[p],dfn[v]);
		}
	}
	if(low[p] == dfn[p]){
		++scnt;
		while(1){
			int x = S.top();
			S.pop();
			sc[x] = scnt;
			if(x == p) break;
		}
	}
}

void Tarjan(){
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(sc,0,sizeof(sc));
	while(!S.empty()) S.pop();
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) Dfs(i);
}

void Init(){
	memset(first,-1,sizeof(first));
	memset(din,0,sizeof(din));
	memset(dout,0,sizeof(dout));
	ecnt = tot = scnt = 0;
}

int main(){
	int a,b;
	scanf("%d",&T);
	while(T--){
		Init();
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= m; ++i){
			scanf("%d%d",&a,&b);
			Add_edge(a,b);
		}
		Tarjan();
		if(scnt == 1){
			printf("0\n");
			continue;
		}
		for(int k = 1; k <= n; ++k){
			for(int i = first[k]; i != -1; i = next[i]){
				int v = ver[i];
				if(sc[k] != sc[v]){
					dout[sc[k]]++;
					din[sc[v]]++;
				}
			}
		}
		int c1,c2;
		c1 = c2 = 0;
		for(int i = 1; i <= scnt; ++i){
			if(dout[i] == 0) ++c1;
			if(din[i] == 0) ++c2;
		}
		printf("%d\n",max(c1,c2));
	}
	return 0;
}


