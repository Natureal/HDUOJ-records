////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-08 21:42:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5044
////Problem Title: 
////Run result: Accept
////Run time:2203MS
////Run memory:14708KB
//////////////////System Comment End//////////////////


/*************************************************************************
    > File Name: 5044.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Mon 06 Oct 2014 10:13:01 PM CST
************************************************************************/

#pragma comment(linker,"/STACK:1024000000,1024000000")
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

int T,N,M;
int first[maxn],next[maxn << 1],ver[maxn << 1],ecnt;
int id[maxn << 1],aid[maxn];
int dep[maxn],sz[maxn],son[maxn],fa[maxn],top[maxn];
int w[maxn],aw[maxn],tsz;
ll it1[maxn],it2[maxn],val1[maxn],val2[maxn];

void Init(){
	memset(it1,0,sizeof(it1));
	memset(it2,0,sizeof(it2));
	memset(first,-1,sizeof(first));
	memset(val1,0,sizeof(val1));
	memset(val2,0,sizeof(val2));
	ecnt = 0;
	tsz = 0;
}

inline int Read(){
    int x = 0,f = 1;char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
 }

void Add_edge(int u,int v,int i){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	id[ecnt] = i;
	first[u] = ecnt;
	next[++ecnt] = first[v];
	ver[ecnt] = u;
	id[ecnt] = i;
	first[v] = ecnt;
}

void Dfs(int p,int pre,int d){
	sz[p] = 1;
	dep[p] = d;
	son[p] = -1;
	fa[p] = pre;
	int v,tmp = 0;
	for(int i = first[p]; i != -1; i = next[i]) if((v = ver[i]) != pre){
		aid[v] = id[i];
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

void Update1(int a,int b,int c){
	int f1 = top[a],f2 = top[b];
	while(f1 != f2){
		if(dep[f1] > dep[f2]){
			swap(a,b);
			swap(f1,f2);
		}
		it1[w[f2]] += c;
		it1[w[b] + 1] -= c;
		b = fa[f2];
		f2 = top[b];
	}
	if(dep[a] > dep[b]) swap(a,b);
	it1[w[a]] += c;
	it1[w[b] + 1] -= c;
}

void Update2(int a,int b,int c){
	int f1 = top[a],f2 = top[b];
	while(f1 != f2){
		if(dep[f1] > dep[f2]){
			swap(a,b);
			swap(f1,f2);
		}
		it2[w[f2]] += c;
		it2[w[b] + 1] -= c;
		b = fa[f2];
		f2 = top[b];
	}
	if(dep[a] > dep[b]) swap(a,b);
	it2[w[son[a]]] += c;
    it2[w[b] + 1] -= c;
}

int main(){
	char s[10];
	int a,b,c;
	T = Read();
	for(int Case = 1; Case <= T; ++Case){
		Init();
		N = Read();
		M = Read();
		for(int i = 1; i < N; ++i){
			a = Read(),b = Read();
			Add_edge(a,b,i);
		}
		Dfs(1,0,0);
		Dfs_pos(1,1);
		aid[1] = 0;
		while(M--){
			scanf("%s",s);
			a = Read(),b = Read(),c = Read();
			if(s[3] == '1'){
				Update1(a,b,c);
			}
			else{
				Update2(a,b,c);
			}
		}
		printf("Case #%d:\n",Case);
		it1[0] = it2[1] = 0;
		for(int i = 1; i <= N; ++i){
			it1[i] += it1[i - 1];
			val1[aw[i]] = it1[i];
		}
		for(int i = 2; i <= N; ++i){
			it2[i] += it2[i - 1];
			val2[aid[aw[i]]] = it2[i];
		}
		for(int i = 1; i <= N; ++i){
			if(i != 1) printf(" ");
			printf("%I64d",val1[i]);
		}
		puts("");
		if(N > 1){
			for(int i = 1; i < N; ++i){
				if(i != 1) printf(" ");
				printf("%I64d",val2[i]);
			}
		}
		puts("");
	}
	return 0;
}
