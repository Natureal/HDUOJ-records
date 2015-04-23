////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-02 00:14:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3836
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:1784KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1001.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 01 Nov 2014 11:22:56 PM CST
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
const int maxn1 = 20010;
const int maxn2 = 50010;

int N,M;
int first[maxn1],next[maxn2],ver[maxn2],ecnt;
int low[maxn1],dfn[maxn1],sc[maxn1],scnt,tot;
int din[maxn1],dout[maxn1];
stack<int> S;

void Init(){
	memset(first,-1,sizeof(first));
	memset(din,0,sizeof(din));
	memset(dout,0,sizeof(dout));
	ecnt = 0;
}

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
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(sc,0,sizeof(sc));
	while(!S.empty()) S.pop();
	scnt = tot = 0;
	for(int i = 1; i <= N; ++i)
		if(!dfn[i]) Dfs(i);
}

void Build_graph(){
	for(int k = 1; k <= N; ++k){
		for(int i = first[k]; i != -1; i = next[i]){
			int v = ver[i];
			if(sc[k] != sc[v]){
				din[sc[v]]++;
				dout[sc[k]]++;
			}
		}
	}
}

int main(){
	int a,b;
	while(scanf("%d%d",&N,&M) != EOF){
		Init();
		for(int i = 1; i <= M; ++i){
			scanf("%d%d",&a,&b);
			Add_edge(a,b);
		}
		Tarjan();
		if(scnt == 1){
			printf("0\n");
			continue;
		}
		Build_graph();
		int c1 = 0,c2 = 0;
		for(int i = 1; i <= scnt; ++i){
			if(din[i] == 0) c1++;
			if(dout[i] == 0) c2++;
		}
		printf("%d\n",max(c1,c2));
	}
	return 0;
}

