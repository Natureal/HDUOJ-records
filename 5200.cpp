////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-04 21:39:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5200
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:3004KB
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
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 50010;

int fa[MAXN];
int N,Q;
int vis[MAXN];
int now;
int ans[MAXN];

struct node{
    int h,id;
}nd[MAXN];

struct query{
    int q,id;
}q[MAXN];

bool cmp(query a,query b){
    return a.q > b.q;
}

bool cmp1(node a,node b){
    return a.h < b.h;
}

int Find(int x){
    return fa[x] == x ? x : fa[x] = Find(fa[x]);
}

void Union(int a,int b){
    int x = Find(a);
    int y = Find(b);
    if(x != y) fa[y] = x;
}

int main(){
    while(scanf("%d%d",&N,&Q) != EOF){
        now = 0;
        MEM(vis,0);
        for(int i = 1; i <= N; ++i) fa[i] = i;
        for(int i = 1; i <= N; ++i){
            scanf("%d",&nd[i].h);
            nd[i].id = i;
        }
        for(int i = 1; i <= Q; ++i){
            scanf("%d",&q[i].q);
            q[i].id = i;
        }
        sort(q + 1,q + Q + 1,cmp);
        sort(nd + 1,nd + N + 1,cmp1);
        //init
        int pos = -1;
        for(int i = 1; i <= N; ++i){
            if(nd[i].h > q[1].q){
                pos = i - 1;
                break;
            }
        }
        if(pos == -1) pos = N;
        for(int i = pos + 1; i <= N; ++i) if(nd[i].h > q[1].q) vis[nd[i].id] = 1;
        for(int i = 2; i <= N; ++i) if(vis[i]){
            if(vis[i - 1]) Union(i - 1,i);
        }
        for(int i = 1; i <= N; ++i) if(vis[i] && fa[i] == i) now++;
        ans[q[1].id] = now;
        for(int i = 2; i <= Q; ++i){
            for(; pos >= 1; --pos){
                if(nd[pos].h <= q[i].q) break;
                //left
                int cur = nd[pos].id;
                int cnt = 0;
                vis[cur] = 1;
                if(vis[cur - 1]) Union(cur - 1,cur),cnt++;
                //right
                if(cur < N && vis[cur + 1]) Union(cur + 1,cur),cnt++;
                if(cnt == 2) now--;
                if(cnt == 0) now++;
            }
            ans[q[i].id] = now;
        }
        for(int i = 1; i <= Q; ++i)
            printf("%d\n",ans[i]);
    }
    return 0;
}