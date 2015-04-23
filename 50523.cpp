////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-10 20:24:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5052
////Problem Title: 
////Run result: Accept
////Run time:2765MS
////Run memory:7156KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 5052.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Fri 10 Oct 2014 07:12:29 PM CST
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
const int maxn = 50010;

inline int Read(){
	int x = 0,f = 1;char c = getchar();
	while(c < '0' || c > '9'){if(c == '-') f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
	return x * f;
}

int T,N,Q;
int first[maxn],next[maxn << 1],ver[maxn << 1],ecnt;
int dep[maxn],sz[maxn],son[maxn],fa[maxn],w[maxn],aw[maxn],top[maxn],tsz;
int val[maxn];

struct node{
	int add;
	int tmax,tmin;
	int ans1,ans2;
}t[maxn << 2];

void Add_edge(int u,int v){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	first[u] = ecnt;
}

void Dfs(int p,int pre,int d){
	sz[p] = 1;
	son[p] = -1;
	dep[p] = d;
	fa[p] = pre;
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

void Push_up(int p){
	t[p].tmax = max(t[lp].tmax,t[rp].tmax);
	t[p].tmin = min(t[lp].tmin,t[rp].tmin);

	t[p].ans1 = max(t[lp].ans1,t[rp].ans1);
	t[p].ans1 = max(t[p].ans1,t[rp].tmax - t[lp].tmin);

	t[p].ans2 = max(t[lp].ans2,t[rp].ans2);
	t[p].ans2 = max(t[p].ans2,t[lp].tmax - t[rp].tmin);
}

void Push_down(int p){
	int c = t[p].add;
	if(c){
		t[lp].add += c;
		t[rp].add += c;
		t[lp].tmax += c;
		t[lp].tmin += c;
		t[rp].tmax += c;
		t[rp].tmin += c;
		t[p].add = 0;
	}
}

void Build_tree(int p,int l,int r){
	t[p].add = 0;
	if(l == r){
		t[p].tmax = t[p].tmin = val[aw[l]];
		t[p].ans1 = t[p].ans2 = 0;
		return;
	}
	int mid = getmid(l,r);
	Build_tree(lp,l,mid);
	Build_tree(rp,mid + 1,r);
	Push_up(p);
}

int Query_tree(int f,int a,int b,int p,int l,int r,int & maxx,int & minn){
	if(a <= l && r <= b){
        maxx = t[p].tmax;
        minn = t[p].tmin;
		if(f == 1) return t[p].ans1;
		else return t[p].ans2;
	}
	int mid = getmid(l,r);
	Push_down(p);
	if(b <= mid) return Query_tree(f,a,b,lp,l,mid,maxx,minn);
	else if(a > mid) return Query_tree(f,a,b,rp,mid + 1,r,maxx,minn);
	else{
		int maxl,maxr,minl,minr;
		int res = max(Query_tree(f,a,b,lp,l,mid,maxl,minl),
				Query_tree(f,a,b,rp,mid + 1,r,maxr,minr));
        maxx = max(maxl,maxr);
        minn = min(minl,minr);
		if(f == 1) return max(res,maxr - minl);
		else return max(res,maxl - minr);
	}
}

int Find(int a,int b){
	int f1 = top[a],f2 = top[b],maxl,maxr,minl,minr,tmax,tmin;
	maxl = maxr = -INF;
	minl = minr = INF;
	int res = -INF;
	while(f1 != f2){
		if(dep[f1] > dep[f2]){
			res = max(res,Query_tree(2,w[f1],w[a],1,1,tsz,tmax,tmin));
			res = max(res,tmax - minl);
			maxl = max(maxl,tmax);
			minl = min(minl,tmin);
			a = fa[f1];
			f1 = top[a];
		}
		else{
			res = max(res,Query_tree(1,w[f2],w[b],1,1,tsz,tmax,tmin));
			res = max(res,maxr - tmin);
			maxr = max(maxr,tmax);
			minr = min(minr,tmin);
			b = fa[f2];
			f2 = top[b];
		}
	}
	if(dep[a] > dep[b])
		res = max(res,Query_tree(2,w[b],w[a],1,1,tsz,tmax,tmin));
	else
		res = max(res,Query_tree(1,w[a],w[b],1,1,tsz,tmax,tmin));
	res = max(res,tmax - minl);
	res = max(res,maxr - tmin);
	res = max(res,maxr - minl);
	return res;
}

void Update_tree(int a,int b,int c,int p,int l,int r){
	if(a <= l && r <= b){
		t[p].add += c;
		t[p].tmax += c;
		t[p].tmin += c;
		return;
	}
	Push_down(p);
	int mid = getmid(l,r);
	if(a <= mid) Update_tree(a,b,c,lp,l,mid);
	if(b > mid) Update_tree(a,b,c,rp,mid + 1,r);
	Push_up(p);
}

void Change(int a,int b,int c){
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

int main(){
	int a,b,c;
	T = Read();
	while(T--){
		memset(first,-1,sizeof(first));
		ecnt = tsz = 0;
		N = Read();
		for(int i = 1; i <= N; ++i)
			val[i] = Read();
		for(int i = 1; i < N; ++i){
			a = Read(),b = Read();
			Add_edge(a,b);
			Add_edge(b,a);
		}
		Dfs(1,0,0);
		Dfs_pos(1,1);
		Build_tree(1,1,tsz);
		Q = Read();
		for(int i = 1; i <= Q; ++i){
			a = Read(),b = Read(),c = Read();
			int ans = Find(a,b);
			if(ans < 0) ans = 0;
			printf("%d\n",ans);
			Change(a,b,c);
		}
	}
	return 0;
}


