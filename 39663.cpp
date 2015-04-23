////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-05 16:23:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3966
////Problem Title: 
////Run result: Accept
////Run time:1093MS
////Run memory:7516KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 3966.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 05 Oct 2014 01:20:20 PM CST
************************************************************************/
#pragma comment(linker,"/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
const int maxn = 50010;

int N,M,P;
int A[maxn];
int first[maxn],next[maxn << 1],ver[maxn << 1],ecnt;
int dep[maxn],sz[maxn],son[maxn],fa[maxn],top[maxn],w[maxn],aw[maxn],tsz;

struct node{
	int add;
	int val;
}t[maxn << 2];

void Add_edge(int u,int v){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	first[u] = ecnt;
}

void Dfs(int p,int pre,int d){
	sz[p] = 1;
	dep[p] = d;
	fa[p] = pre;
	son[p] = -1;
	int v,tmp = 0;
	for(int i = first[p]; i != -1; i = next[i]) if((v = ver[i]) != pre){
		Dfs(v,p,d + 1);
		if(sz[v] > tmp){
			son[p] = v;
			tmp = sz[v];
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

void Build_tree(int p,int l,int r){
	t[p].add = 0;
	if(l == r){
		t[p].val = A[aw[l]];
		return;
	}
	int mid = getmid(l,r);
	Build_tree(lp,l,mid);
	Build_tree(rp,mid + 1,r);
}

void Update_tree(int a,int b,int c,int p,int l,int r){
	if(a <= l && r <= b){
		t[p].add += c;
		return;
	}
	int mid = getmid(l,r);
	if(a <= mid) Update_tree(a,b,c,lp,l,mid);
	if(b > mid) Update_tree(a,b,c,rp,mid + 1,r);
}

int Query_tree(int a,int p,int l,int r,int plu){
	if(l == r)
		return t[p].val + t[p].add + plu;
	int mid = getmid(l,r);
	if(a <= mid) return Query_tree(a,lp,l,mid,plu + t[p].add);
	else return Query_tree(a,rp,mid + 1,r,plu + t[p].add);
}

/*void Change(int a,int b,int c){
	int f1 = top[a],f2 = top[b];
	while(f1 != f2){
		if(dep[f1] > dep[f2]){
			swap(a,b);
			swap(f1,f2);
		}
		Update_tree(w[f2],w[b],c,1,1,tsz);
		b = fa[f2];
		f2 = top[b];
	}
	if(dep[a] > dep[b]) swap(a,b);
	Update_tree(w[a],w[b],c,1,1,tsz);
}*/

void Init(){
	memset(first,-1,sizeof(first));
	ecnt = 0;
	tsz = 0;
}

int main(){
	char s[5];
	int a,b,c;
	while(scanf("%d%d%d",&N,&M,&P) != EOF){
		Init();
		for(int i = 1; i <= N; ++i)
			scanf("%d",A + i);
		for(int i = 1; i < N; ++i){
			scanf("%d%d",&a,&b);
			Add_edge(a,b);
			Add_edge(b,a);
		}
		Dfs(1,0,0);
		Dfs_pos(1,1);
		Build_tree(1,1,tsz);
		for(int i = 1; i <= P; ++i){
			scanf("%s%d",s,&a);
			if(s[0] == 'I' || s[0] == 'D'){
				scanf("%d%d",&b,&c);
				if(s[0] == 'D') c = -c;	
				int f1 = top[a],f2 = top[b];
				while(f1 != f2){
					if(dep[f1] > dep[f2]){
						swap(a,b);
						swap(f1,f2);
					}
					Update_tree(w[f2],w[b],c,1,1,tsz);
					b = fa[f2];
					f2 = top[b];
				}
				if(dep[a] > dep[b]) swap(a,b);
				Update_tree(w[a],w[b],c,1,1,tsz);
			}
			else printf("%d\n",Query_tree(w[a],1,1,tsz,0));
		}
	}
	return 0;
}

