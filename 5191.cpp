////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-21 21:56:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5191
////Problem Title: 
////Run result: Accept
////Run time:499MS
////Run memory:5936KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 150010;

ll n,W,H;
ll h[MAXN],v[MAXN];
ll sum[MAXN],hsum[MAXN];

ll Abs(ll x){
	if(x < 0) return -x;
	return x;
}

int main(){
	while(scanf("%I64d%I64d%I64d",&n,&W,&H) != EOF){
		for(int i = 1; i <= W; ++i) h[i] = 0;
		for(int i = W + 1; i <= W + n; ++i){
			scanf("%I64d",&h[i]);
		}
		for(int i = W + n + 1; i <= W + n + W; ++i) h[i] = 0;
		n = n + W + W;
		for(int i = 1; i <= n; ++i){
			v[i] = Abs(H - h[i]);
			sum[i] = sum[i - 1] + v[i];
			hsum[i] = hsum[i - 1] + h[i];
		}
		if(hsum[n] < W * H){
			printf("-1\n");
			continue;
		}
		ll ans = INF;
		for(int i = W; i <= n; ++i){
			ll cur = sum[i] - sum[i - W];
			ll tmp = Abs(W * H - (hsum[i] - hsum[i - W]));
			ans = min(ans,(cur + tmp) / 2LL);
			}
		printf("%I64d\n",ans);
	}
	return 0;
}
