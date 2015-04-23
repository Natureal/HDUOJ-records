////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-08-30 12:27:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2770
////Problem Title: 
////Run result: Accept
////Run time:2937MS
////Run memory:16756KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = (ll)1 << 50;
const int RA = 100;

ll Q[30000];
ll P[30000];
ll h[105];
ll Th[30000];
ll dp[105][30000];
ll cnt;
ll Case,n,d;
ll head,tail;

void Update_queue(ll pos,ll val){
	while(head <= tail && Q[tail] >= val)
        --tail;
	Q[++tail] = val;
	P[tail] = pos;
}

ll Get(ll k){
    while(head <= tail && Th[P[head]] + d < Th[k]) ++head;
    if(head > tail) return INF;
    else return Q[head];
}

void Dp(){
	ll x;
	for(ll i = 2; i <= n; ++i){
		head = 1;
		tail = 0;
		ll p = 1;
		for(ll j = 1; j <= cnt; ++j){
			x = Th[j];
			while(p <= cnt && Th[p] - d <= x){
                Update_queue(p,dp[i - 1][p]);
                ++p;
            }
			dp[i][j] = ((x > h[i]) ? (x - h[i]) : (h[i] - x))  + Get(j);
		}
	}
}

void Init(){
	for(ll i = 1; i <= cnt; ++i)
		if(Th[i] == h[1])	dp[1][i] = 0;
		else	dp[1][i] = INF;
}

int main(){
    ios::sync_with_stdio(false);
	ll v;
	cin >> Case;
	while(Case--){
		cnt = 0;
		cin >> n >> d;
		for(ll i = 1; i <= n; ++i){
            cin >> h[i];
			for(ll k = -n; k <= n; ++k){
				v = h[i] + k * d;
				if(v < 0) continue;
				Th[++cnt] = v;
			}
		}
		sort(Th + 1,Th + cnt + 1);
		ll tmp = cnt;
		cnt = 1;
		for(ll i = 2; i <= tmp; ++i)
            if(Th[i] != Th[cnt]) Th[++cnt] = Th[i];
		Init();
		Dp();
		ll ans = INF;
		for(ll i = 1; i <= cnt; ++i)
			if(Th[i] == h[n]){
				ans = dp[n][i];
				//break;
			}
		if(ans >= INF) cout << "impossible" << endl;
		else cout << ans << endl;
	}
	return 0;
}
