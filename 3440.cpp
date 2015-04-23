////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-10 15:02:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3440
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:1224KB
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
const int maxn = 1010;

int T,N,D;
int first[maxn],ecnt;
int inq[maxn],cnt[maxn],dis[maxn];

struct edge{
	int u,v,next,cost;
}e[maxn << 1];

struct node{
	int h,id;
}t[maxn];

bool cmp(node a,node b){
	return a.h < b.h;
}

void Add_edge(int u,int v,int c){
	e[++ecnt].next = first[u];
	e[ecnt].u = u;
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
	cnt[s] = 1;
	Q.push(s);
	while(!Q.empty()){
		int x = Q.front(); Q.pop();
		inq[x] = 0;
		for(int i = first[x]; ~i; i = e[i].next){
			int v = e[i].v;
			if(dis[v] > dis[x] + e[i].cost){
				dis[v] = dis[x] + e[i].cost;
				if(inq[v] == 0){
					inq[v] = 1;
					if(++cnt[v] > N) return false;
					Q.push(v);
				}
			}
		}
	}
	return true;
}

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		memset(first,-1,sizeof(first));
		ecnt = 0;
		scanf("%d%d",&N,&D);
		for(int i = 1; i <= N; ++i){
			scanf("%d",&t[i].h);
			t[i].id = i;
			//pos[i] - pos[i - 1] >= 1 --> pos[i - 1] <= pos[i] - 1
			Add_edge(i,i - 1,-1);
		}
		sort(t + 1,t + N + 1,cmp);
		for(int i = 2; i <= N; ++i){
			if(t[i].id > t[i - 1].id){ 
				//pos[t[i].id] - pos[t[i - 1].id] <= D
				//pos[t[i].id] <= pos[t[i - 1].id] + D
				Add_edge(t[i - 1].id,t[i].id,D);
			}
			else{                      
				//pos[t[i - 1].id] - pos[t[i].id] <= D
				//pos[t[i - 1].id] <= pos[t[i].id] + D
				Add_edge(t[i].id,t[i - 1].id,D);
			}		
		}
		printf("Case %d: ",tt);
		int st = min(t[1].id,t[N].id);
		int ed = t[1].id + t[N].id - st;
		if(Spfa(st)) printf("%d\n",dis[ed]);
		else printf("-1\n");
	}
	return 0;
}
