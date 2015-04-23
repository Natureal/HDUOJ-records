////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-18 14:13:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5160
////Problem Title: 
////Run result: Accept
////Run time:312MS
////Run memory:5008KB
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
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const ll mod = 1e9 + 7;
const int maxn = 1e5 + 10;

int T,n,A[maxn],sumnum,num[maxn],cur;
ll fac[maxn],afac[maxn],cnt[maxn],rcnt[maxn];

ll Q_pow(ll x,ll y){
	ll res = 1;
	while(y){
		if(y & 1) res = (res * x) % mod;
		x = (x * x) % mod;
		y >>= 1;
	}
	return res;
}

void Pre(){
	fac[0] = afac[0] = 1;
	REP(i,100000){
		fac[i] = (fac[i - 1] * (ll)i) % mod;
		afac[i] = Q_pow(fac[i],mod - 2);
	}
}

void Read(){
	scanf("%d",&n);
	REP(i,n) scanf("%d",A + i);
	sort(A + 1,A + n + 1);
	cur = 0;
	MEM(num,0);
	sumnum = 0;
	REP(i,n){
		if(A[i] != A[i - 1]){
			A[++cur] = A[i];
			num[cur] = 1;
		}
		else num[cur]++;
	}
	REP(i,cur) sumnum += num[i];
	int sum = 0;
	ll bot = 1;
	REP(i,cur){
		sum += num[i];
		bot = (bot * afac[num[i]]) % mod;
		cnt[i] = (fac[sum] * bot) % mod;
	}
	sum = 0;
	bot = 1;
	REV(i,cur){
		sum += num[i];
		bot = (bot * afac[num[i]]) % mod;
		rcnt[i] = (fac[sum] * bot) % mod;
	}
	cnt[0] = 1;
	rcnt[cur + 1] = 1;
}

int main(){
	Pre();
	scanf("%d",&T);
	REP(tt,T){
		Read();
		
		ll ans = 0;
		int tot = sumnum;
		REP(i,cur){
			tot -= num[i];
			ll C = fac[n] * afac[n - num[i] - tot] % mod * afac[num[i] + tot] % mod;
			ll tmp = num[i];
			FOR(j,1,num[i] - 1){
				int top = j;
				int bot = tot + j - 1;
				tmp = (tmp + (num[i] - j) * (fac[bot] * afac[bot - top] % mod * afac[top] % mod) % mod) % mod;
			}
			ans = (ans + C * cnt[i - 1] % mod * A[i] % mod * tmp % mod * rcnt[i + 1]) % mod;
		}
		printf("Case #%d: %I64d\n",tt,ans);
	}
	return 0;
}


