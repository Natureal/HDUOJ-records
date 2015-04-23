////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-04 16:51:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1212KB
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

int N,M,ecnt;
int dis[maxn];

struct edge{
	int u,v,cost;
}e[maxn * maxn];

int Bellman_ford(int s){
	for(int i = 1; i <= N; ++i)
		dis[i] = INF;
	dis[s] = 0;
	for(int k = 1; k < N; ++k){
		bool flag = false;
		for(int i = 1; i <= ecnt; ++i){
			int u = e[i].u;
			int v = e[i].v;
			if(dis[u] != INF && dis[v] > dis[u] + e[i].cost){
				dis[v] = dis[u] + e[i].cost;
				flag = true;
			}
		}
		if(!flag) break;
	}
	return dis[N];
}

void Add_edge(int u,int v,int c){
	e[++ecnt].u = u;
	e[ecnt].v = v;
	e[ecnt].cost = c;

	e[++ecnt].u = v;
	e[ecnt].v = u;
	e[ecnt].cost = c;
}

int main(){
	int a,b,c;
	while(scanf("%d%d",&N,&M) != EOF){
		if(N == 0 && M == 0) break;
		ecnt = 0;
		for(int i = 1; i <= M; ++i){
			scanf("%d%d%d",&a,&b,&c);
			Add_edge(a,b,c);
			Add_edge(b,a,c);
		}
		printf("%d\n",Bellman_ford(1));
	}
	return 0;
}
