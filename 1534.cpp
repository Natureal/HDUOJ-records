////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-08 01:01:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1534
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1356KB
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
const int maxn = 20010;

int n,t[maxn];
int first[maxn],ecnt;
int inq[maxn],cnt[maxn],dis[maxn];

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
	fill(dis + 1,dis + n + 1,-INF);
	dis[s] = 0;
	cnt[s] = 1;
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
					if(++cnt[v] > n + 2) return false;
					Q.push(v);
				}
			}
		}
	}
	return true;
}

int main(){
	char s[10];
	int a,b,Case = 0;
	while(scanf("%d",&n) != EOF,n){
		memset(first,-1,sizeof(first));
		ecnt = 0;
		for(int i = 1; i <= n; ++i) scanf("%d",t + i);
		while(scanf("%s",s) != EOF && s[0] != '#'){
			scanf("%d%d",&a,&b);
			if(s[0] == 'F'){
				if(s[2] == 'S') Add_edge(b,a,-t[a]);
				else Add_edge(b,a,t[b] - t[a]);
			}
			else{
				if(s[2] == 'F') Add_edge(b,a,t[b]);
				else Add_edge(b,a,0);
			}
		}
		for(int i = 1; i <= n; ++i) Add_edge(0,i,0);
		printf("Case %d:\n",++Case);
		if(Spfa(0) == false) printf("impossible\n");
		else{
			for(int i = 1; i <= n; ++i)
				printf("%d %d\n",i,dis[i]);
		}
		puts("");
	}
	return 0;
}
