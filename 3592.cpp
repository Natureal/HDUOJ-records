////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-07 00:38:33
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3592
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1368KB
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
const int maxn = 10010;

int T,N,X,Y;
int first[maxn],ecnt;
int cnt[maxn],inq[maxn],dis[maxn];

struct edge{
	int v,next,cost;
}e[maxn << 1];

void Add_edge(int u,int v,int c){
	e[++ecnt].next = first[u];
	e[ecnt].v = v;
	e[ecnt].cost = c;
	first[u] = ecnt;
}

bool Spfa(int s){
	queue<int> Q;
	memset(inq,0,sizeof(inq));
	memset(cnt,0,sizeof(cnt));
	fill(dis + 1,dis + N + 1,INF);
	dis[s] = 0;
	inq[s] = cnt[s] = 1;
	Q.push(s);
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		//printf("x : %d\n",x);
		for(int i = first[x]; i != -1; i = e[i].next){
			int v = e[i].v;
			//printf("v : %d\n",v);
			if(dis[v] > dis[x] + e[i].cost){
				dis[v] = dis[x] + e[i].cost;
				if(inq[v] == 0){
					inq[v] = 1;
					cnt[v]++;
					if(cnt[v] > N)
						return false;
					Q.push(v);
				}
			}
		}
	}
	return true;
}

int main(){
	int a,b,c;
	scanf("%d",&T);
	while(T--){
		//Init
		memset(first,-1,sizeof(first));
		ecnt = 0;
		scanf("%d%d%d",&N,&X,&Y);
		for(int i = 1; i <= X; ++i){
			scanf("%d%d%d",&a,&b,&c);
			//S(b) - S(a) <= c --> S(b) <= S(a) + c
			Add_edge(a,b,c);
		}
		for(int i = 1; i <= Y; ++i){
			scanf("%d%d%d",&a,&b,&c);
			//S(b) - S(a) >= c --> S(a) - S(b) <= -c --> S(a) <= S(b) + (-c)
			Add_edge(b,a,-c);
		}
		for(int i = 1; i <= N; ++i){
			//S(i) - S(i - 1) >= 0 --> S(i - 1) <= S(i) + 0
			Add_edge(i,i - 1,0);
		}
		if(Spfa(1) == false) printf("-1\n");
		else if(dis[N] >= INF) printf("-2\n");
		else printf("%d\n",dis[N]);
	}
	return 0;
}
