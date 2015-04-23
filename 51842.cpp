////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 18:51:36
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5184
////Problem Title: 
////Run result: Accept
////Run time:811MS
////Run memory:18452KB
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
const ll mod = 1000000007LL;
const int MAXN = 1000000;

int N;
ll fac[MAXN + 10],afac[MAXN + 10];
char s[MAXN + 10];

ll Q_pow(ll x,ll y){
	ll res = 1,X = x;
	while(y){
		if(y & 1) res = res * X % mod;
		X = X * X % mod;
		y >>= 1;
	}
	return res;
}

void Pre(){
	fac[0] = 1;
	REP(i,MAXN)	fac[i] = fac[i - 1] * (ll)i % mod;
	afac[MAXN] = Q_pow(fac[MAXN],mod - 2);
	RFOR(i,MAXN - 1,0) afac[i] = afac[i + 1] * (i + 1) % mod;
}

ll Comb(ll n,ll m){
	if(n < m || m < 0) return 0;
	return fac[n] * afac[m] % mod * afac[n - m] % mod;
}

bool Judge(int &q,int &p){
	if(N & 1) return false;
	q = p = N / 2;
	int len = strlen(s);
	for(int i = 0; i < len; ++i){
		if(s[i] == '(') q--;
		else p--;
		if(q > p) return false;
	}
	if(q < 0 || p < 0) return false;
	return true;
}

int main(){
	Pre();
	while(scanf("%d",&N) != EOF){
		scanf("%s",s);
		int q,p;
		if(!Judge(q,p)){
			printf("0\n");
			continue;
		}
		ll ans = (Comb(p + q,q) - Comb(p + q,q - 1) + mod) % mod;
		printf("%d\n",(int)ans);
	}
	return 0;
}

