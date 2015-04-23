////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-25 12:49:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5163
////Problem Title: 
////Run result: Accept
////Run time:670MS
////Run memory:2652KB
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
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int T,n,m;
ll d[100010],sum[100010];

int main(){
    int a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        REP(i,n - 1) scanf("%I64d",&d[i]);
        sum[1] = 0;
        FOR(i,2,n) sum[i] = sum[i - 1] + d[i - 1];
        REP(i,m){
            scanf("%d%d",&a,&b);
            int st = (i - 1) % n + 1;
            if(a < b){
                if(st <= a) printf("%I64d\n",sum[b] - sum[st]);
                else printf("%I64d\n",sum[n] - sum[st] + sum[n] + sum[b]);
            }
            else{
                printf("%I64d\n",sum[n] - sum[st] + sum[n] - sum[b]);
            }
        }
    }
    return 0;
}