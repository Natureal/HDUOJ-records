////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-10 22:34:41
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5029
////Problem Title: 
////Run result: Accept
////Run time:1375MS
////Run memory:18904KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 5029.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Fri 10 Oct 2014 08:34:44 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
const int maxn = 100010;

inline int Read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){ x = x * 10 + c - '0'; c = getchar();}
	return x;
}

int n,m;
int first[maxn],next[maxn << 1],ver[maxn << 1],ecnt;
int dep[maxn],sz[maxn],son[maxn],fa[maxn],top[maxn],w[maxn],aw[maxn],tsz;
int tmax[maxn << 2],col[maxn << 2],ans[maxn];
vector<int> f[maxn];

void Init(){
	for(int i = 1; i <= n; ++i) f[i].clear();
	memset(col,0,sizeof(col));
	memset(tmax,0,sizeof(tmax));
	memset(first,-1,sizeof(first));
	ecnt = tsz = 0;
}

void Add_edge(int u,int v){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	first[u] = ecnt;
}

void Dfs(int p,int pre,int d){
	sz[p] = 1;
	son[p] = -1;
	fa[p] = pre;
	dep[p] = d;
	int v,tmp = 0;
	for(int i = first[p]; i != -1; i = next[i]) if((v = ver[i]) != pre){
		Dfs(v,p,d + 1);
		if(sz[v] > tmp){
			tmp = sz[v];
			son[p] = v;
		}
		sz[p] += sz[v];
	}
}

void Dfs_pos(int p,int tp){
	w[p] = ++tsz;
	aw[tsz] = p;
	top[p] = tp;
	if(son[p] != -1) Dfs_pos(son[p],tp);
	for(int i = first[p]; i != -1; i = next[i]){
		int v = ver[i];
		if(v != son[p] && v != fa[p])
			Dfs_pos(v,v);
	}
}

void Change(int a,int b,int c){
	int f1 = top[a],f2 = top[b];
	while(f1 != f2){
		if(dep[f1] > dep[f2]){
			swap(a,b);
			swap(f1,f2);
		}
		f[w[f2]].push_back(c);
		f[w[b] + 1].push_back(-c);
		b = fa[f2];
		f2 = top[b];
	}
	if(dep[a] > dep[b]) swap(a,b);
	f[w[a]].push_back(c);
	f[w[b] + 1].push_back(-c);
}

void Update_tree(int a,int c,int p,int l,int r){
	if(l == r){
		tmax[p] += c;
		if(tmax[p] > 0) col[p] = l;
		else col[p] = 0;
		return;
	}
	int mid = getmid(l,r);
	if(a <= mid) Update_tree(a,c,lp,l,mid);
	else Update_tree(a,c,rp,mid + 1,r);
	if(tmax[lp] >= tmax[rp]){
		tmax[p] = tmax[lp];
		col[p] = col[lp];
	}
	else{
		tmax[p] = tmax[rp];
		col[p] = col[rp];
	}
}

int main(){
	int a,b,c;
	while(1){
		n = Read(),m = Read();
		if(!n && !m) break;
		Init();
		for(int i = 1; i < n; ++i){
			a = Read(),b = Read();
			Add_edge(a,b);
			Add_edge(b,a);
		}
		Dfs(1,0,0);
		Dfs_pos(1,1);
		for(int i = 1; i <= m; ++i){
			a = Read();
			b = Read();
			c = Read();
			Change(a,b,c);
		}
		for(int i = 1; i <= n; ++i){
			for(unsigned int j = 0; j < f[i].size(); ++j)
				Update_tree(abs(f[i][j]),f[i][j] > 0 ? 1 : -1,1,1,maxn);
			ans[aw[i]] = col[1];
		}
		for(int i = 1; i <= n; ++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}



