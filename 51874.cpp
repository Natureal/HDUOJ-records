////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-14 23:07:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5187
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:1688KB
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

ll n,p;

//ll Mul(ll x,ll y){
//	double res = (double)x * y;
//	res = res - (double)((ll)(res / (double)p) * (double)p);
//	return (ll)res;
//}

ll Mul(ll x,ll y){
	ll res = 0;
	while(y){
		if(y & 1){
			res += x;
			while(res > p) res -= p;
		}
		x += x;
		while(x > p) x -= p;
		y >>= 1;
	}
	return res;
}

ll Q_pow(ll x,ll y){
	ll res = 1;
	while(y){
		if(y & 1) res = Mul(res,x);
		x = Mul(x,x);
		y >>= 1;
	}
	return res;
}

int main(){
	ios::sync_with_stdio(false);
	while(cin >> n >> p){
		if(n == 1){
			if(p == 1) printf("0\n");
			else printf("1\n");
			continue;
		}
		cout << (Q_pow(2LL,n) - 2 + p) % p << endl;
	}
	return 0;
}		
	
