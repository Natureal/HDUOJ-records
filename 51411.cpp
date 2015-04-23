////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-07 01:05:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5141
////Problem Title: 
////Run result: Accept
////Run time:670MS
////Run memory:3512KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1004.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 06 Dec 2014 08:17:34 PM CST
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
const int maxn = 100010;

int n;
int v[maxn];
int cp[maxn];

typedef pair<int,int> pii;

pii dp[maxn];

struct BIT{
	pii c[maxn];
	void Init(){
		fill_n(c + 1,n,pii(0,0));
	}
	int Lowbit(int x){
		return x & (-x);
	}
	void Update(int x,pii t){
		while(x <= maxn){
			c[x] = max(t,c[x]);
			x += Lowbit(x);
		}
	}
	pii Getmax(int x){
		pii res(0,0);
		while(x > 0){
			res = max(res,c[x]);
			x -= Lowbit(x);
		}
		return res;
	}
};

int main(){
	while(scanf("%d",&n) != EOF){
		BIT B;
		B.Init();
		for(int i = 1; i <= n; ++i){
			scanf("%d",&v[i]);
			cp[i] = v[i];
		}
		sort(cp + 1,cp + n + 1);
		int sz = unique(cp + 1,cp + n + 1) - cp - 1;
		int tmax = -1;
		for(int i = 1; i <= n; ++i){
			int p = lower_bound(cp + 1,cp + sz + 1,v[i]) - cp;
			pii tmp = B.Getmax(p - 1);
			if(tmp.first == 0) tmp.second = i;
			tmp.first++;
			B.Update(p,tmp);
			dp[i] = tmp;
			tmax = max(tmax,tmp.first);
		}
		ll ans = 0;
		int pos = 0;
		for(int i = 1; i <= n; ++i){
			if(dp[i].first == tmax){
				ans += (ll)(dp[i].second - pos) * (ll)(n - i + 1);
				pos = dp[i].second;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
