////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-06 16:56:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1384
////Problem Title: 
////Run result: Accept
////Run time:2979MS
////Run memory:3528KB
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
const int maxn = 50010;

int N,tmax,tmin;
int first[maxn],ecnt;
int inq[maxn],dis[maxn];

struct edge{
	int v,next,cost;
}e[3 * maxn];

void Add_edge(int u,int v,int c){
	e[++ecnt].next = first[u];
	e[ecnt].v = v;
	e[ecnt].cost = c;
	first[u] = ecnt;
}

void Spfa(int s){
	queue<int> Q;
	memset(inq,0,sizeof(inq));
	for(int i = tmin; i <= tmax; ++i) dis[i] = -INF;
	inq[s] = 1;
	dis[s] = 0;
	Q.push(s);
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		for(int i = first[x]; i != -1; i = e[i].next){
			int v = e[i].v;
			if(dis[v] < dis[x] + e[i].cost){
				dis[v] = dis[x] + e[i].cost;
				if(inq[v] == 0){
					inq[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

int main(){
	int a,b,c;
	while(scanf("%d",&N) != EOF){
		memset(first,-1,sizeof(first));
		ecnt = tmax = 0;
		tmin = INF;
		for(int i = 1; i <= N; ++i){
			scanf("%d%d%d",&a,&b,&c);
			a++;
			b++;
			//S(b) - S(a-1) >= c
			//S(b) >= S(a - 1) + c
			Add_edge(a - 1,b,c);
			tmax = max(tmax,b);
			tmin = min(tmin,a - 1);
		}
		//S(i) - S(i - 1) >= 0
		//S(i) - S(i - 1) <= 1 --> S(i - 1) - S(i) >= -1
		for(int i = tmin + 1; i <= tmax; ++i){
			Add_edge(i - 1,i,0);
			Add_edge(i,i - 1,-1);
		}
		Spfa(tmin);
		printf("%d\n",dis[tmax]);
	}
	return 0;
}
		
