////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-14 22:41:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5175
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:1224KB
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

ll N;
vector<ll> ans;

ll Gcd(ll a,ll b){
	return b == 0 ? a : Gcd(b,a % b);
}

int main(){
	int tt = 0;
	while(cin >> N){
		ll k = sqrt(N);
		ll cnt = 0;
		ans.clear();
		printf("Case #%d:\n",++tt);
		REP(i,k) if(N % i == 0){
			ll tmp = N ^ i;
			if(tmp > 0 && tmp <= N && Gcd(N,tmp) == i) ans.push_back(tmp);
			tmp = N ^ (N / i);
			if(tmp > 0 && tmp <= N && Gcd(N,tmp) == N / i) ans.push_back(tmp);
		}
		cout << ans.size() << endl;
		sort(ans.begin(),ans.end());
		for(int i = 0; i < ans.size(); ++i){
			if(i > 0) printf(" ");
			printf("%I64d",ans[i]);
		}
		puts("");
	}
	return 0;
}
		