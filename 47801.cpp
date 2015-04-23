////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-23 16:07:07
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4780
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:2480KB
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
#define X first
#define Y second

typedef long long ll;
typedef pair<int,int> pii;
const ll INF = (1 << 28);
const int MAXN = 510;

int N,M,K;
int C[MAXN][MAXN],D[MAXN][MAXN],E[MAXN][MAXN],F[MAXN][MAXN];
int st[MAXN],ed[MAXN];

struct edge{
	int v,next;
	ll cost;
	int cp;
};

inline int Read(){
	int x = 0;char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x;
}

struct MCMF{
	edge e[MAXN * MAXN * 2];
	int sou,sin;
	int first[MAXN],ecnt;
	ll dis[MAXN];
	int prev[MAXN],pree[MAXN],inq[MAXN];
	void Init(){
		MEM(first,-1);
		ecnt = 0;
	}
	void Add_edge(int u,int v,int cap,int fee){
		e[++ecnt].next = first[u];
		e[ecnt].v = v;
		e[ecnt].cp = cap;
		e[ecnt].cost = fee;
		first[u] = ecnt;

		e[++ecnt].next = first[v];
		e[ecnt].v = u;
		e[ecnt].cp = 0;
		e[ecnt].cost = -fee;
		first[v] = ecnt;
	}
	bool Spfa(){
		fill(dis,dis + MAXN,INF);
		dis[sou] = 0;
		MEM(prev,-1),MEM(inq,0);
		queue<int> Q;
		while(!Q.empty()) Q.pop();
		Q.push(0);
		while(!Q.empty()){
			int x = Q.front(); Q.pop();
			inq[x] = 0;
			for(int i = first[x]; ~i; i = e[i].next){
				if(e[i].cp <= 0) continue;
				int v = e[i].v;
				if(dis[x] + e[i].cost < dis[v]){
					dis[v] = dis[x] + e[i].cost;
					prev[v] = x;
					pree[v] = i;
					if(inq[v] == 0){
						inq[v] = 1;
						Q.push(v);
					}
				}
			}
		}
		return prev[sin] != -1;
	}
	ll Solve(){
		ll min_cost = 0;
		while(Spfa()){
			//ll minf = INF;
			//for(int i = sin; i != sou; i = prev[i]){
			//	minf = min(minf,(ll)e[pree[i]].cp);
			//}
			for(int i = sin; i != sou; i = prev[i]){
				int id = pree[i];
				e[id].cp--;
				e[((id - 1) ^ 1) + 1].cp++;
			}
			min_cost += dis[sin];
		}
		return min_cost;
	}
}Nat;

int main(){
	while(scanf("%d%d%d",&N,&M,&K) != EOF,N + M + K){
		Nat.Init();
		REP(i,N) st[i] = Read(),ed[i] = Read();
		REP(i,N) REP(j,M) C[i][j] = Read(); //init time
		REP(i,N) REP(j,M) D[i][j] = Read(); //init cost
		REP(i,N) REP(j,N) E[i][j] = Read(); //change time
		REP(i,N) REP(j,N) F[i][j] = Read(); //change cost
		Nat.sou = 0; //source : 0
		//machine : 1 ~ M , candy(1) : M + 1 ~ M + N , candy(2) : M + N + 1 ~ M + 2 * N
 		Nat.sin = M + 2 * N + 1; //sin : M + 2 * N + 1
		REP(i,M){
			Nat.Add_edge(Nat.sou,i,1,0); //source - machines
			Nat.Add_edge(i,Nat.sin,1,0);
		}
		REP(i,N){
			Nat.Add_edge(M + i,M + N + i,1,-INF); //candy(1) - candy(2)
			Nat.Add_edge(M + N + i,Nat.sin,1,0); //candy(2) - sink
		}
		REP(i,N) REP(j,M){	//candy(1)[i] , machine[j]
			if(C[i][j] >= ed[i]) continue;
			int add_cost = K * (max(C[i][j],st[i]) - st[i]);
			Nat.Add_edge(j,M + i,1,D[i][j] + add_cost);
		}
		REP(i,N) REP(j,N) if(i != j){ //candy(2)[i] - candy(1)[j]
			if(ed[i] + E[i][j] >= ed[j]) continue;
			int add_cost = K * (max(ed[i] + E[i][j],st[j]) - st[j]);
			Nat.Add_edge(M + N + i,M + j,1,F[i][j] + add_cost);
		}
		ll ans = Nat.Solve();
		ans += N * INF;
		if(ans >= INF) printf("-1\n");
		else	printf("%d\n",ans);
	}
	return 0;
}
