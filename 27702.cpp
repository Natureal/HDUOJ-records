////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-08-29 17:06:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2770
////Problem Title: 
////Run result: Accept
////Run time:3078MS
////Run memory:16708KB
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

struct node {
    ll k,ret;
}q[30000];

ll h[105];
ll Th[30000];
ll dp[105][30000];
ll cnt;
ll Case,n,d;
ll head,tail;

void Update_queue(ll pos,ll val){
    while(head <= tail && q[tail].ret >= val)
        --tail;
    ++tail;
    q[tail].k = pos;
    q[tail].ret = val;
}

ll Get(ll k){
    while(head <= tail && Th[q[head].k] + d < Th[k]) ++head;
    if(head > tail) return INF;
    else return q[head].ret;
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
        if(Th[i] == h[1])    dp[1][i] = 0;
        else    dp[1][i] = INF;
}

int main(){
    ll v;
    scanf("%I64d",&Case);
    while(Case--){
        cnt = 0;
        scanf("%I64d%I64d",&n,&d);
        for(ll i = 1; i <= n; ++i)
            scanf("%I64d",&h[i]);
        for(ll i = 1; i <= n; ++i){
            for(ll k = -n; k <= n; ++k){
                v = h[i] + k * d;
                //if(v < 0) continue;
                //if(v > INF) break;
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