////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-30 00:17:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5124
////Problem Title: 
////Run result: Accept
////Run time:1046MS
////Run memory:2664KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1002.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 29 Nov 2014 07:03:40 PM CST
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
const int maxn = 200010;

int T,N;
int x[maxn],y[maxn],st[maxn];
int add[maxn],cnt;

int main(){
	scanf("%d",&T);
	while(T--){
		cnt = 0;
		memset(add,0,sizeof(add));
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i){
			scanf("%d%d",&x[i],&y[i]);
			st[++cnt] = x[i];
			st[++cnt] = y[i];
		}
		sort(st + 1,st + cnt + 1);
		int sz = unique(st + 1,st + cnt + 1) - st;
		for(int i = 1; i <= N; ++i){
			int a = lower_bound(st + 1,st + sz + 1,x[i]) - st;
			int b = lower_bound(st + 1,st + sz + 1,y[i]) - st;
			add[a]++;
			add[b + 1]--;
		}
		int ans = 0,tmp = 0;
		for(int i = 1; i <= sz; ++i){
			tmp += add[i];
			ans = max(ans,tmp);
		}
		printf("%d\n",ans);
	}
	return 0;
}
