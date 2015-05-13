#include <ctime>
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

#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-8;
const int INF = (1 << 30) - 1;

int T;
ll N;
vector<ll> fac;

ll Gcd(ll a,ll b){ return b == 0 ? a : Gcd(b,a % b); }

ll Q_mul(ll a,ll b,ll mod){
	a %= mod;
	ll res = 0;
	while(b){
		if(b & 1) res = (res + a) % mod;
		a = (a + a) % mod;
		b >>= 1;
	}
	return res;
}

ll Q_pow(ll x,ll y,ll mod){
	x %= mod;
	ll res = 1;
	while(y){
		if(y & 1) res = Q_mul(res,x,mod);
		x = Q_mul(x,x,mod);
		y >>= 1;
	}
	return res;
}

bool Witness(ll a,ll n){
	int t = 0;
	ll u = n - 1;
	while(!(u & 1)) t++,u >>= 1;
	ll x,pre = Q_pow(a,u,n);
	for(int i = 1; i <= t; ++i){
		x = Q_mul(pre,pre,n);
		if(x == 1 && pre != 1 && pre != n - 1) return false;
		pre = x;
	}
	if(x != 1) return false;
	return true;
}

bool Miller_Rabin(ll n){
	if(n == 2) return true;
	if(n < 2 || !(n & 1)) return false;
	for(int i = 1; i <= 1; ++i){
		ll a = rand() % (n - 1) + 1;
		if(Witness(a,n) == false) return false;
	}
	return true;
}

ll Pollard_rho(ll n,ll c){
	ll x,y,i = 1,k = 2;
	y = x = rand() % n;
	while(1){
		i++;
		x = (Q_mul(x,x,n) + c) % n;
		ll g = Gcd(y - x + n,n);
		if(g != 1 && g != n) return g;
		if(y == x) return n;
		if(i == k){ y = x,k <<= 1; }
	}
}

void Solve(ll n){
	if(Miller_Rabin(n)){
		fac.PB(n);
		return;
	}
	ll p = n;
	while(p >= n) p = Pollard_rho(p,rand() % (n - 1) + 1);
	Solve(p);
	Solve(n / p);
}

int main(){
	srand((ll)time(NULL));
	while(scanf("%I64d",&N) != EOF){
		if(N == 1 || Miller_Rabin(N)){
			printf("is not a D_num\n");
			continue;
		}
		fac.clear();
		Solve(N);
		sort(fac.begin(),fac.end());
		bool flag = false;
		if(fac.size() == 2 && fac[0] != fac[1]) flag = true;
		else if(fac.size() == 3 && fac[0] == fac[1] && fac[1] == fac[2]) flag = true;
		if(flag) printf("%I64d %I64d %I64d\n",fac[0],fac[0]==fac[1]?fac[0]*fac[0]:fac[1],N);
		else printf("is not a D_num\n");
	}
	return 0;
}

