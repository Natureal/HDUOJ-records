////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-04 15:05:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3333
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:3016KB
//////////////////System Comment End//////////////////


/*************************************************************************
    > File Name: 3333.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 04 Oct 2014 01:35:35 PM CST
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
const int maxn = 30010;

int T,N,Q;
int vis[maxn];
ll c[maxn];
ll A[maxn],B[maxn];

struct Query{
    int l,r,id;
}q[100010];
ll ans[100010];

bool cmp1(Query a,Query b){ return a.r < b.r;}
bool cmp2(Query a,Query b){	return a.id < b.id;}

int Lowbit(int x){return x & (-x);}
void Update(int x,int d){while(x <= N){c[x] += d; x += Lowbit(x);}}
ll Getsum(int x){ll res = 0;while(x){res += c[x]; x -= Lowbit(x);}return res;}

int main(){
	int a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i){
			scanf("%I64d",&A[i]);
			B[i] = A[i];
			c[i] = 0;
		}
		sort(B + 1,B + N + 1);
		int sz = unique(B + 1,B + N + 1) - B - 1;
		for(int i = 1; i <= N; ++i)
			A[i] = lower_bound(B + 1,B + sz + 1,A[i]) - B;
		scanf("%d",&Q);
		for(int i = 1; i <= Q; ++i){
			scanf("%d%d",&q[i].l,&q[i].r);
			q[i].id = i;
		}
		sort(q + 1,q + Q + 1,cmp1);
		memset(vis,0,sizeof(vis));
		int i = 1;
		for(int k = 1; k <= Q; ++k){
			for(; i <= q[k].r; ++i){
				Update(i,B[A[i]]);
				if(vis[A[i]]) Update(vis[A[i]],-B[A[i]]);
				vis[A[i]] = i;
			}
			ans[q[k].id] = Getsum(q[k].r) - Getsum(q[k].l - 1);
		}
		for(int i = 1; i <= Q; ++i)
			printf("%I64d\n",ans[i]);
	}
	return 0;
}

