////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-06 21:36:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2886
////Problem Title: 
////Run result: Accept
////Run time:624MS
////Run memory:1204KB
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
#define REP(i,n) for(int i=0;i<(n);++i)
#define REV(i,n) for(int i=(n-1);i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const ll mod = 2009;

ll N;

ll Q_pow(ll x,ll y){
	ll res = 1LL;
	while(y){
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}

int main(){
	while(cin >> N){
		if(N < 3){
			cout << N << endl;
			continue;
		}
		ll k = N / 3;
		if(N % 3 == 1){
			cout << Q_pow(3,k - 1) * 4LL % mod << endl;
		}
		else if(N % 3 == 2){
			cout << Q_pow(3,k) * 2LL % mod << endl;
		}
		else cout << Q_pow(3,k) << endl;
	}
	return 0;
}
