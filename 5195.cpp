////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-28 23:05:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5195
////Problem Title: 
////Run result: Accept
////Run time:561MS
////Run memory:5552KB
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
#include <ctime>
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
const int MAXN = 200010;

int n,m,k;
int first[MAXN],ecnt;
int deg[MAXN];
int vis[MAXN];
int ans[MAXN],sz;

struct edge{
	int v,next;
}e[MAXN * 2];

void Add_edge(int u,int v){
	e[++ecnt].next = first[u];
	e[ecnt].v = v;
	first[u] = ecnt;
}

void Topo(){
	sz = 0;
	priority_queue<int> Q;
	while(!Q.empty()) Q.pop();
	for(int i = 1; i <= n; ++i) if(deg[i] <= k) Q.push(i);
	while(!Q.empty()){
		int cur = Q.top(); Q.pop();
		if(!vis[cur] && deg[cur] <= k){
			k -= deg[cur];
			deg[cur] = 0;
			vis[cur] = 1;
		}
		else continue;
		ans[sz++] = cur;
		for(int i = first[cur]; i != -1; i = e[i].next) if(!vis[e[i].v]){
			int v = e[i].v;
			deg[v]--;
			if(deg[v] <= k) Q.push(v);
		}
	}
}

int main(){
	int a,b;
	while(scanf("%d%d%d",&n,&m,&k) != EOF){
		//clock_t st,ed;
		//st = clock();
		MEM(first,-1);
		ecnt = 0;
		MEM(deg,0);
		MEM(vis,0);
		REP(i,m){
			scanf("%d%d",&a,&b);
			Add_edge(a,b);
			deg[b]++;
		}
		Topo();
		//ed = clock();
		printf("%d",ans[0]);
		for(int i = 1; i < sz; ++i) printf(" %d",ans[i]);
		puts("");
		//printf("time : %.2f\n",(double)(ed - st) / CLOCKS_PER_SEC);
	}
	return 0;
}
