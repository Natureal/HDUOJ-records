////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-10 19:01:47
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5052
////Problem Title: 
////Run result: Accept
////Run time:2703MS
////Run memory:7152KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: sy.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Thu 09 Oct 2014 10:04:37 PM CST
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
typedef long long ll;
const int INF = 1 << 30;
const int maxn = 50010;

int T,N,Q;
int first[maxn],next[maxn << 1],ver[maxn << 1],ecnt;
int dep[maxn],sz[maxn],son[maxn],fa[maxn],top[maxn],tsz;
int w[maxn],aw[maxn],val[maxn];

struct node{
	int add;
	int tmax,tmin, tans1,tans2;
}t[maxn << 2];

inline int Read(){
    int x = 0,f = 1;char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return x * f;
}

inline void Write(int num){  
    bool flag=false;  
    if(num<0){  
        putchar('-');  
        num=-num;  
    }  
    int ans[20],top=0;  
    while(num!=0){  
        ans[top++]=num%10;  
        num/=10;  
    }  
    if(top==0)  
        putchar('0');  
    for(int i=top-1;i>=0;i--){  
        char ch=ans[i]+'0';  
        putchar(ch);  
    }  
    puts("");  
}  

void Init(){
	memset(aw,0,sizeof(aw));
	memset(w,0,sizeof(w));
    memset(first,-1,sizeof(first));
    ecnt = 0;
	tsz = 0;
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

void Push_up(int p){
	t[p].tmax = max(t[lp].tmax,t[rp].tmax);
	t[p].tmin = min(t[lp].tmin,t[rp].tmin);
	
	t[p].tans1 = max(t[lp].tans1,t[rp].tans1);
	t[p].tans1 = max(t[p].tans1,t[rp].tmax - t[lp].tmin);
	
	t[p].tans2 = max(t[lp].tans2,t[rp].tans2);
	t[p].tans2 = max(t[p].tans2,t[lp].tmax - t[rp].tmin);
}

void Build_tree(int p,int l,int r){
	t[p].add = 0;
	if(l == r){
		t[p].tmin = t[p].tmax = (ll)val[aw[l]];
		t[p].tans1 = t[p].tans2 = 0;
		return;
	}
	int mid = getmid(l,r);
	Build_tree(lp,l,mid);
	Build_tree(rp,mid + 1,r);
	Push_up(p);
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

int Query_tree(int f,int a,int b,int p,int l,int r,int & minn,int & maxx){
	if(a <= l && r <= b){
		maxx = t[p].tmax;
		minn = t[p].tmin;
		if(f == 1) return t[p].tans1;
		else return t[p].tans2;
	}
	Push_down(p);
	int mid = getmid(l,r);
	if(b <= mid)
		return Query_tree(f,a,b,lp,l,mid,minn,maxx);
	else if(a > mid)
		return Query_tree(f,a,b,rp,mid + 1,r,minn,maxx);
	else{
		int max1,min1,max2,min2,res;
		res = max(Query_tree(f,a,b,lp,l,mid,min1,max1),
				Query_tree(f,a,b,rp,mid + 1,r,min2,max2));
		maxx = max(max1,max2);
		minn = min(min1,min2);
		if(f == 1) return max(res,max2 - min1);
		else return max(res,max1 - min2);
	}
}

int Find(int a,int b,int c){
	int f1 = top[a],f2 = top[b];
	int ans = -1,tmax,tmin,max1 = -INF,min1 = INF,max2 = -INF,min2 = INF;
	while(f1 != f2){
		if(dep[f1] > dep[f2]){
			ans = max(ans,Query_tree(2,w[f1],w[a],1,1,tsz,tmin,tmax));
			ans = max(ans,tmax - min1);
			max1 = max(max1,tmax);
			min1 = min(min1,tmin);
			a = fa[f1];
			f1 = top[a];
		}
		else{
			ans = max(ans,Query_tree(1,w[f2],w[b],1,1,tsz,tmin,tmax));
			ans = max(ans,max2 - tmin);
			max2 = max(max2,tmax);
			min2 = min(min2,tmin);
			b = fa[f2];
			f2 = top[b];
		}
	}
	if(dep[a] > dep[b])
		ans = max(ans,Query_tree(2,w[b],w[a],1,1,tsz,tmin,tmax));
	else
		ans = max(ans,Query_tree(1,w[a],w[b],1,1,tsz,tmin,tmax));
	ans = max(ans,tmax - min1);
	ans = max(ans,max2 - tmin);
	ans = max(ans,max2 - min1);
	return ans;
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
        N = Read();
		Init();
		for(int i = 1; i <= N; ++i) val[i] = Read();
        for(int i = 1; i < N; ++i){
            a = Read(),b = Read();
            Add_edge(a,b);
            Add_edge(b,a);
        }
        Dfs(1,0,0);
        Dfs_pos(1,1);
        Build_tree(1,1,tsz);
		Q = Read();
		int ans;
        for(int i = 1; i <= Q; ++i){
			a = Read(),b = Read(),c = Read();
			ans = Find(a,b,c);
			Change(a,b,c);
			if(ans < 0) ans = 0;
			Write(ans);
		}
	}
    return 0;
}
