////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-10 01:06:42
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5052
////Problem Title: 
////Run result: Accept
////Run time:3453MS
////Run memory:10552KB
//////////////////System Comment End//////////////////
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll inf = 1e16;
inline void rd(int &n){
	n = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') n *= 10, n += (c - '0'),c = getchar();
}
void pt64(ll num){
     if(num<0) {
         putchar('-');
         num=-num;
     }
     int ans[20],top=0;
     while(num!=0)     {
         ans[top++]=num%10;
         num/=10;
     }
     if(top==0) putchar('0');
     for(int i=top-1;i>=0;i--)
         putchar(ans[i]+'0');
	 putchar('\n');
}
#define N 50010
struct Edge{
	int to, nex;
}edge[N*2];
int head[N], edgenum;
void add(int u, int v){	Edge E = {v, head[u]}; edge[edgenum] = E; head[u] = edgenum++;}
void init(){memset(head, -1, sizeof head); edgenum = 0;}
int fa[N], son[N], siz[N], dep[N], tree_id;
//父节点 重儿子 子树节点数 深度 线段树标号
int w[N], fw[N], p[N];
//父边在线段树中的标号 节点顶端的点
void dfs(int u, int Father, int deep){
	fa[u] = Father; son[u] = 0; dep[u] = deep; siz[u] = 1;
	for(int i = head[u]; ~i; i = edge[i].nex) {
		int v = edge[i].to; if(v == Father) continue;
		dfs(v, u, deep+1);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]])son[u] = v;
	}
}
void Have_p(int u, int Father){
	w[u] = ++ tree_id; fw[tree_id] = u; p[u] = Father;
	if(son[u])
		Have_p(son[u], Father);
	else return ;
	for(int i = head[u]; ~i; i = edge[i].nex) {
		int v = edge[i].to; if(v == fa[u] || v == son[u])continue;
		Have_p(v, v);
	}
}
#define Lson(x) tree[x].l
#define Rson(x) tree[x].r
#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define Lazy(x) tree[x].lazy
#define Ans0(x) tree[x].ans[0]
#define Ans1(x) tree[x].ans[1]
#define Min(x) tree[x].min
#define Max(x) tree[x].max
struct node {
	int l, r;
	ll ans[2], min, max, lazy;
}tree[N<<2];
int a[N];
void push_down(int id){
	if(Lazy(id)){
		Min(L(id)) += Lazy(id);
		Max(L(id)) += Lazy(id);
		Min(R(id)) += Lazy(id);
		Max(R(id)) += Lazy(id);
		Lazy(L(id)) += Lazy(id);
		Lazy(R(id)) += Lazy(id);
		Lazy(id) = 0;
	}
}
void push_up(int id){
	Min(id) = min(Min(L(id)), Min(R(id)));
	Max(id) = max(Max(L(id)), Max(R(id)));
	Ans0(id) = max(Ans0(L(id)), Ans0(R(id)));
	Ans0(id) = max(Ans0(id), Max(R(id)) - Min(L(id)));
	Ans1(id) = max(Ans1(L(id)), Ans1(R(id)));
	Ans1(id) = max(Ans1(id), Max(L(id)) - Min(R(id)));
}
void build(int l, int r, int id){
	Lson(id) = l; Rson(id) = r;
	Lazy(id) = 0;
	if(l == r) {
		Ans0(id) = Ans1(id) = 0;
		Min(id) = Max(id) = (ll)a[fw[l]];
		return ;
	}
	int mid = (l + r)>>1;
	build(l, mid, L(id)); build(mid+1, r, R(id));
	push_up(id);
}
void updata(int l, int r, ll val, int id){
	if(l == Lson(id) && Rson(id) == r){
		Min(id) += val;
		Max(id) += val;
		Lazy(id) += val;
		return ;
	}
	push_down(id);
	int mid = (Lson(id) + Rson(id)) >>1;
	if(mid < l)
		updata(l, r, val, R(id));
	else if(r <= mid)
		updata(l, r, val, L(id));
	else {
		updata(l, mid, val, L(id));
		updata(mid+1, r, val, R(id));
	}
	push_up(id);
}
ll query(int l, int r, int hehe, ll &minn, ll &maxx, int id){
	if(l == Lson(id) && Rson(id) == r){
		maxx = Max(id);
		minn = Min(id);
		if(hehe == 0) return Ans0(id);
		else return Ans1(id);
	}
	push_down(id);
	int mid = (Lson(id) + Rson(id)) >>1;
	if(mid < l)
		return query(l, r, hehe, minn, maxx, R(id));
	else if(r <= mid)
		return query(l, r, hehe, minn, maxx, L(id));
	else {
		ll maxl = 0, minl = 0, maxr = 0, minr = 0, ans;
		ans = max(query(l, mid, hehe, minl, maxl, L(id)), query(mid+1, r, hehe, minr, maxr, R(id)));
		maxx = max(maxl, maxr);
		minn = min(minl, minr);
		if(hehe == 0) {
			return max(ans, maxr - minl);
		}
		else {
			return max(ans, maxl - minr);
		}
	}
}
int n, que;
ll Qu(int l, int r){
	int f1 = p[l], f2 = p[r];
	ll ans = 0, maxl = -inf, minl = inf, maxr = -inf, minr = inf, tmax, tmin;
	while(f1 != f2){
		if(dep[f1] > dep[f2]) {
			ans = max(ans, query(w[f1], w[l], 1, tmin, tmax, 1));
			ans = max(ans, tmax - minl);
			maxl = max(maxl, tmax);
			minl = min(minl, tmin);
			l = fa[f1]; f1 = p[l];
		}
		else {
			ans = max(ans, query(w[f2], w[r], 0, tmin, tmax, 1));
			ans = max(ans, maxr - tmin);
			maxr = max(maxr, tmax);
			minr = min(minr, tmin);
			r = fa[f2]; f2 = p[r];
		}
	}
	if(dep[l] < dep[r])	{
		ans = max(ans, query(w[l], w[r], 0, tmin, tmax, 1));
	}
	else {
		ans = max(ans, query(w[r], w[l], 1, tmin, tmax, 1));
	}
	ans = max(ans, tmax - minl);
	ans = max(ans, maxr - tmin);
	ans = max(ans, maxr - minl);
	return ans;
}
void Up(int l, int r, ll val){
	int f1 = p[l], f2 = p[r];
	while(f1 != f2) {
		if(dep[f1] < dep[f2])
			swap(f1, f2), swap(l, r);
		updata(w[f1], w[l], val, 1);
		l = fa[f1]; f1 = p[l];
	}
	if(dep[l] > dep[r]) swap(l, r);
	updata(w[l], w[r], val, 1);
}
void input() {
	init();
	rd(n);
	for(int i = 1; i <= n; i++) rd(a[i]);
	for(int i = 1, u, v; i < n; i++) {
		rd(u); rd(v);
		add(u, v); add(v, u);
	}
	siz[0] = tree_id = 0;
	dfs(1, 1, 1);
	Have_p(1, 1);
	build(1, n, 1);
}
int main() {
	int T, Cas = 1, u, v, val; rd(T);
	while (T -- ) {
		input();
		rd(que);
		while( que -- ) {
			rd(u); rd(v); rd(val);
			pt64( Qu(u, v) );
			Up(u, v, (ll)val);
		}
	}
	return 0;
}
/*
99
8
3 2 1 5 4 6 7 2
1 2 
2 3
2 4
3 5
5 6
5 8
4 7
99
2 6 2
3 4 5
6 1 2
5 7 3
8 1 4
2 3 1
4 4 1
6 3 5
4 7 2 
7 6 3
5 8 3

12
3 4 2 1 5 9 6 10 8 7 11 12
1 3
1 2
3 4
2 5
2 6
5 7
7 9
7 10
6 8
8 11
12 8
8
1 12 0
4 5 0
10 12 0
7 12 3
11 6 2
4 12 100
4 12 0
7 12 3

8
42 68 35 1 70 25 79 59
1 2
2 3
2 4
3 5
5 6
5 8
4 7
30
3 1 2
2 2 4
2 4 4
7 4 5
8 5 7
2 5 7
6 5 7
8 8 7
4 3 6
1 4 4
4 7 8
4 3 6
2 1 6
8 6 5
4 5 7
6 6 4
4 6 2
3 5 4
7 3 1
3 1 7
1 1 7
6 3 2
3 7 7
6 2 5
6 8 5
3 5 1
7 1 4
5 1 8
3 4 2
3 7 3

*/
