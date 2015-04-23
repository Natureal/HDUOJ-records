////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 18:46:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5184
////Problem Title: 
////Run result: Accept
////Run time:858MS
////Run memory:18440KB
//////////////////System Comment End//////////////////

/*
ID:naturec1
PROG: 
LANG: C++
*/
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
const int MAXN = 1000000;
const ll mod = 1e9 + 7;

int N;
char s[MAXN + 10];
ll fac[MAXN + 10],afac[MAXN + 10];

ll Q_pow(ll x,ll y){
	ll res = 1;
	x %= mod;
	while(y){
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

ll Comb(ll n,ll m){
	if(n < m || m < 0) return 0;
	return fac[n] * afac[m] % mod * afac[n - m] % mod;
}

int main(){
	fac[0] = 1;
	for(int i = 1; i <= MAXN; ++i) fac[i] = fac[i - 1] * i % mod;
	afac[MAXN] = Q_pow(fac[MAXN],mod - 2);
	for(int i = MAXN -  1; i >= 0; --i)
		afac[i] = afac[i + 1] * (i + 1) % mod;
	while(scanf("%d",&N) != EOF){
		scanf("%s",s);
		int x = N / 2,y = N / 2,len = strlen(s);
		for(int i = 0; i < len; ++i){
			if(s[i] == '(') x--;
			else y--;
			if(x > y) break;
		}
		if(x < 0 || y < 0 || (N % 2 == 1) || x > y){
			printf("0\n");
			continue;
		}
		ll ans = (Comb(x + y,x) - Comb(x + y,x - 1) + mod) % mod;
		printf("%d\n",(int)ans);
	}
	return 0;
}
