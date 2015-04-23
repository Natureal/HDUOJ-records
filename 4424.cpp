////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-31 01:03:18
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4424
////Problem Title: 
////Run result: Accept
////Run time:1341MS
////Run memory:6576KB
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
const int maxn = 200010;

int N,fa[maxn],sz[maxn];
ll sum[maxn];
struct edge{
    int u,v,c;
}e[maxn];

int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

bool cmp(edge a,edge b){
    return a.c > b.c;
}

int main(){
    while(scanf("%d",&N) != EOF){
        //init
        MEM(sum,0);
        REP(i,N) fa[i] = i,sz[i] = 1;
        //solve
        REP(i,N - 1) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
        sort(e + 1,e + N,cmp);
        REP(i,N - 1){
            int a = e[i].u;
            int b = e[i].v;
            int c = e[i].c;
            int x = Find(a),y = Find(b);
            fa[x] = y;
            ll wx = sum[x] + (ll)c * sz[y];
            ll wy = sum[y] + (ll)c * sz[x];
            sz[y] += sz[x];
            sum[y] = max(wx,wy);
        }
        printf("%I64d\n",sum[Find(1)]);
    }
    return 0;
}