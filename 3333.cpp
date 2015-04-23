////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-04 14:43:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3333
////Problem Title: 
////Run result: Accept
////Run time:1062MS
////Run memory:3400KB
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
ll tsum[maxn],A[maxn],B[maxn];

struct Query{
	int l,r,id;
	ll sum;
}q[100010];

bool cmp1(Query a,Query b){
	return a.r < b.r;
}

bool cmp2(Query a,Query b){
	return a.id < b.id;
}

void Debug(int sz){
	printf("A[] :");
	for(int i = 1; i <= N; ++i){
		printf("%d ",A[i]);
	}
	puts("");
	printf("B[] :");
	for(int i = 1; i <= sz; ++i)
		printf("%d ",B[i]);
	puts("");
}

int main(){
	int a,b;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i){
			scanf("%I64d",&A[i]);
			B[i] = A[i];
		}
		sort(B + 1,B + N + 1);
		int sz = unique(B + 1,B + N + 1) - B - 1;
		for(int i = 1; i <= N; ++i)
			A[i] = lower_bound(B + 1,B + sz + 1,A[i]) - B;
		//Debug(sz);
		scanf("%d",&Q);
		for(int i = 1; i <= Q; ++i){
			scanf("%d%d",&q[i].l,&q[i].r);
			q[i].id = i;
		}
		sort(q + 1,q + Q + 1,cmp1);
		tsum[0] = 0;
		int pos = 1;
		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= Q; ++i){
			for(; pos <= q[i].r; ++pos){
				tsum[pos] = tsum[pos - 1];
				if(!vis[A[pos]]){
                    tsum[pos] += B[A[pos]];
                    vis[A[pos]] = pos;
                }
                else{
                    for(int j = vis[A[pos]]; j < pos; ++j)
                        tsum[j] -= B[A[pos]];
                    vis[A[pos]] = pos;
                }
			}
			q[i].sum = tsum[q[i].r] - tsum[q[i].l - 1];
		}
		sort(q + 1,q + Q + 1,cmp2);
		for(int i = 1; i <= Q; ++i)
			printf("%I64d\n",q[i].sum);
	}
	return 0;
}

