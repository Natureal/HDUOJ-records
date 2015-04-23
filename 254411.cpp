////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-12 15:46:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1660KB
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
int first[maxn],nxt[maxn * maxn],ver[maxn * maxn],ecnt;
int dis[maxn];
struct edge{
    int v,cost;
    friend bool operator < (edge a,edge b){
        return a.cost > b.cost;
    }
}e[maxn * maxn];

void Add_edge(int u,int v,int c){
    nxt[++ecnt] = first[u];
    e[ecnt].v = v;
    e[ecnt].cost = c;
    first[u] = ecnt;
}

int Dijstra(int s){
    priority_queue<pii> PQ;
    fill(dis + 1,dis + N + 1,INF);
    dis[s] = 0;
    PQ.push(MP(dis[s],1));
    int cnt = 0;
    while(!PQ.empty()){
        pii x = PQ.top(); PQ.pop();
        if(dis[x.second] < x.first) continue; //当前的x并非最短路径，舍弃
        for(int i = first[x.second]; i != -1; i = nxt[i]){
            int v = e[i].v;
            if(dis[v] > dis[x.second] + e[i].cost){
                dis[v] = dis[x.second] + e[i].cost;
                PQ.push(MP(dis[v],v));
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
