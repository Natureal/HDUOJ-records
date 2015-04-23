////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-04 23:08:07
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1184KB
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
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int maxn = 110;

int N,M;
int first[maxn],next[maxn * maxn],ver[maxn * maxn],ecnt;
int dis[maxn];
struct edge{
    int v,cost;
    friend bool operator < (edge a,edge b){
        return a.cost > b.cost;
    }
}e[maxn * maxn];

void Add_edge(int u,int v,int c){
    next[++ecnt] = first[u];
    e[ecnt].v = v;
    e[ecnt].cost = c;
    first[u] = ecnt;
}

int Dijstra(int s){
    priority_queue<pii> PQ;
    fill(dis + 1,dis + N + 1,INF);
    dis[s] = 0;
    PQ.push(MP(1,dis[s]));
    int cnt = 0;
    while(!PQ.empty()){
        pii x = PQ.top(); PQ.pop();
        if(dis[x.first] < x.second) continue;
        for(int i = first[x.first]; i != -1; i = next[i]){
            int v = e[i].v;
            if(dis[v] > dis[x.first] + e[i].cost){
                dis[v] = dis[x.first] + e[i].cost;
                PQ.push(MP(v,dis[v]));
            }
        }
    }
    return dis[N];
}


int main(){
    int a,b,c;
    while(scanf("%d%d",&N,&M) != EOF){
        if(N == 0 && M == 0) break;
        memset(first,-1,sizeof(first));
        ecnt = 0;
        for(int i = 1; i <= M; ++i){
            scanf("%d%d%d",&a,&b,&c);
            Add_edge(a,b,c);
            Add_edge(b,a,c);
        }
        printf("%d\n",Dijstra(1));
    }
    return 0;
}
