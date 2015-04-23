////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-08 23:45:35
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3666
////Problem Title: 
////Run result: Accept
////Run time:436MS
////Run memory:6220KB
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
const int maxn = 1000;

int N,M,L,U,g;
int first[maxn],ecnt;
int inq[maxn],cnt[maxn],vis[maxn];
double dis[maxn];

struct edge{
    int v,next;
    double cost;
}e[maxn * maxn * 2];

inline void Add_edge(int u,int v,double c){
    e[++ecnt].next = first[u];
    e[ecnt].v = v;
    e[ecnt].cost = c;
    first[u] = ecnt;
}

bool Spfa(int p){
	inq[p] = vis[p] = 1;
	for(int i = first[p]; ~i; i = e[i].next){
		int v = e[i].v;
		if(dis[v] > dis[p] + e[i].cost){
			dis[v] = dis[p] + e[i].cost;
			if(inq[v] || !Spfa(v))
				return false;
		}
	}
	inq[p] = 0;
	return true;
}

bool Solve(){
	memset(inq,0,sizeof(inq));
	memset(vis,0,sizeof(vis));
	//memset(dis,0,sizeof(dis));
	for(int i = N + M; i >= 0; --i) dis[i] = 0.0;
	for(int i = N + M; i >= 0; --i) if(!vis[i]){
		if(Spfa(i) == false){
			return false;
		}
	}
	return true;
}

int main(){
    while(scanf("%d%d%d%d",&N,&M,&L,&U) != EOF){
        memset(first,-1,sizeof(first));
        ecnt = 0;
        double tl = log(1.0 * L);
        double tu = log(1.0 * U);
        for(int i = 1; i <= N; ++i){
            for(int j = 1; j <= M; ++j){
                scanf("%d",&g);
				double tg = log(1.0 * g);
                Add_edge(i,N + j,tg - tl);
                Add_edge(N + j,i,tu - tg);
            }
        }
		for(int i = N + M; i >= 1; --i)
			Add_edge(0,i,0);
		if(Solve()) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}