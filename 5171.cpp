////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-08 05:25:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5171
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:1944KB
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
const ll mod = 10000007;

ll n,k,val[100010];

struct Mx{
    ll a[3][3];
    void clear(){ memset(a,0,sizeof(a));}
    void stand(){ memset(a,0,sizeof(a)); for(int i = 0; i < 3; ++i) a[i][i] = 1;}
    Mx operator * (Mx b){
        Mx c; c.clear();
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                for(int k = 0; k < 3; ++k){
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j] % mod) % mod;
                }
            }
        }
        return c;
    }
};

Mx Q_pow(ll num){
    Mx t; t.clear();
    Mx res; res.stand();
    t.a[0][1] = 1;
    t.a[1][0] = t.a[1][1] = 1;
    t.a[2][0] = t.a[2][1] = t.a[2][2] = 1;
    while(num){
        if(num & 1) res = res * t;
        t = t * t;
        num >>= 1;
    }
    return res;
}

int main(){
    while(scanf("%I64d%I64d",&n,&k) != EOF){
        REP(i,n) scanf("%I64d",&val[i]);
        ll sum = 0;
        sort(val,val + n);
        for(int i = 0; i < n - 2; ++i) sum = (sum + val[i]) % mod;
        Mx ans;
        ans.clear();
        ans.a[0][0] = val[n - 2];
        ans.a[1][0] = val[n - 1];
        ans.a[2][0] = val[n - 1] + val[n - 2];
        ans = Q_pow(k) * ans;
        printf("%I64d\n",(ans.a[2][0] + sum) % mod);
    }
    return 0;
}