////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-08 20:53:53
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3666
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:6232KB
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
int first[maxn],next[maxn * maxn * 2],ver[maxn * maxn * 2],ecnt;
int inq[maxn];
double dis[maxn],cost[maxn * maxn * 2];

inline void Add_edge(int u,int v,double c){
	next[++ecnt] = first[u];
	ver[ecnt] = v;
	cost[ecnt] = c;
	first[u] = ecnt;
}

inline int Read(){
      int x = 0;char ch = getchar();
      while(ch < '0' || ch > '9') ch = getchar();
      while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
      return x;
}

bool Spfa(int s){
	queue<int> Q;
	memset(inq,0,sizeof(inq));
	fill(dis + 1,dis + N + M + 1,(double)INF);
	dis[s] = 0;
	int tcnt = 1;
	Q.push(s);
	int limit = 2 * (N + M);
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		for(int i = first[x]; ~i; i = next[i]){
			int v = ver[i];
			if(dis[v] > dis[x] + cost[i]){
				dis[v] = dis[x] + cost[i];
				if(inq[v] == 0){
					inq[v] = 1;
					if(++tcnt > limit) return false;
					Q.push(v);
				}
			}
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
				g = Read();
				double tg = log(1.0 * g);
				Add_edge(i,N + j,tg - tl);
				Add_edge(N + j,i,tu - tg);
			}
		}
		for(int i = N + M; i >= 1; --i)
			Add_edge(0,i,0);
		if(Spfa(0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
