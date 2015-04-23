////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-08-30 12:54:27
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2770
////Problem Title: 
////Run result: Accept
////Run time:2531MS
////Run memory:16536KB
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

ll Q[30005];
ll P[30005];
ll h[105];
ll Th[30005];
ll dp[105][30005];
ll cnt;
ll Case,n,d;
ll head,tail;

inline ll Read(){
    int x = 0; char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(ch >= '0' && '9'){x = x*10 + ch - '0'; ch = getchar();}
    return x;
}

void Update_queue(ll limit,ll pos,ll val){
	while(head <= tail && Q[tail] >= val)
        --tail;
	Q[++tail] = val;
	P[tail] = pos;
	while(head <= tail && Th[P[head]] < limit) ++head;
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
                Update_queue(x - d,p,dp[i - 1][p]);
                ++p;
            }
			dp[i][j] = ((x > h[i]) ? (x - h[i]) : (h[i] - x))  + (head <= tail ? Q[head] : INF);
		}
	}
}

void Init(){
	for(ll i = 1; i <= cnt; ++i)
		if(Th[i] == h[1])	dp[1][i] = 0;
		else	dp[1][i] = INF;
}

int main(){
	ll v;
	Case = Read();
	while(Case--){
		cnt = 0;
		n = Read();
		d = Read();
		for(ll i = 1; i <= n; ++i){
            h[i] = Read();
			for(ll k = -n + 1; k < n; ++k){
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
		if(ans >= INF) printf("impossible\n");
		else printf("%I64d\n",ans);
	}
	return 0;
}
