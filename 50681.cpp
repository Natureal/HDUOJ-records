////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-19 00:07:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5068
////Problem Title: 
////Run result: Accept
////Run time:1859MS
////Run memory:4344KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1003.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 18 Oct 2014 07:54:14 PM CST
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
const int maxn = 50010;
const ll mod = 1000000007;

int n,m;

inline int Read(){
	int x = 0;
	char c;
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

struct Mx{
	ll a[2][2];
	void clear(){ memset(a,0,sizeof(a));}
	void stand(){ memset(a,0,sizeof(a)); for(int i = 0; i < 2; ++i) a[i][i] = 1;}
	Mx operator * (Mx b){
		Mx c;
		c.clear();
		for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
		for(int k = 0; k < 2; ++k){
			c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
		}
		return c;
	}
}g[maxn << 2];

void Push_up(int p){
	g[p] = g[lp] * g[rp];
}

void Build_tree(int p,int l,int r){
	if(l == r){
		g[p].a[0][0] = 1;
		g[p].a[0][1] = 1;
		g[p].a[1][0] = 1;
		g[p].a[1][1] = 1;
		return;
	}
	int mid = getmid(l,r);
	Build_tree(lp,l,mid);
	Build_tree(rp,mid + 1,r);
	Push_up(p);
}

Mx Query_tree(int a,int b,int p,int l,int r){
	if(a <= l && r <= b){
		return g[p];
	}
	int mid = getmid(l,r);
	Mx tmp;
	tmp.stand();
	if(a <= mid) tmp = tmp * Query_tree(a,b,lp,l,mid);
	if(b > mid) tmp = tmp * Query_tree(a,b,rp,mid + 1,r);
	return tmp;
}

void Update(int a,int b,int c,int p,int l,int r){
	if(l == r){
		g[p].a[b - 1][c - 1] ^= 1;
		return;
	}
	int mid = getmid(l,r);
	if(a <= mid) Update(a,b,c,lp,l,mid);
	else Update(a,b,c,rp,mid + 1,r);
	Push_up(p);
}

int main(){
	int op,a,b,c;
	while(scanf("%d%d",&n,&m) != EOF){
		Build_tree(1,1,n - 1);
		for(int i = 1; i <= m; ++i){
			op = Read(),a = Read(),b = Read();
			if(op == 0){
				Mx t = Query_tree(a,b - 1,1,1,n - 1);
				ll ans = (t.a[0][0] + t.a[0][1] + t.a[1][0] + t.a[1][1]) % mod;
				printf("%I64d\n",ans);
			}
			else{
				c = Read();
				Update(a,b,c,1,1,n - 1);
			}
		}
	}
	return 0;
}
