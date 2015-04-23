////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 18:52:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5178
////Problem Title: 
////Run result: Accept
////Run time:639MS
////Run memory:2216KB
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

int T;
int n,k;
int X[100010];

int main(){
    scanf("%d",&T);
    REP(tt,T){
        scanf("%d%d",&n,&k);
        REP(i,n) scanf("%d",&X[i]);
        sort(X + 1,X + n + 1);
        ll ans = 0;
        REP(i,n){
            int pos = upper_bound(X + 1,X + n + 1,X[i] + k) - X;
            if(pos > i)    ans += (ll)(pos - i - 1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}