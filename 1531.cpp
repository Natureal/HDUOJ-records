////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-07 21:47:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1531
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1124KB
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
const int INF = 999999999;
const int maxn = 1010;

int n,m;
int first[maxn],ecnt;
int cnt[maxn],inq[maxn],dis[maxn];
queue<int> Q;

struct edge{
	int v,next,cost;
}e[maxn << 2];

void Add_edge(int u,int v,int c){
	e[++ecnt].next = first[u];
	e[ecnt].v = v;
	e[ecnt].cost = c;
	first[u] = ecnt;
}

bool Spfa(int s){
	for(int i = 0; i <= n; ++i){
		Add_edge(n + 1,i,0);
	}
	while(!Q.empty()) Q.pop();
	memset(inq,0,sizeof(inq));
	for(int i = 0; i <= n + 2; ++i)
		dis[i] = INF;
	dis[s] = 0;
	inq[s] = cnt[s] = 1;
	Q.push(n + 1);
	while(!Q.empty()){
		int x = Q.front();
		Q.pop();
		inq[x] = 0;
		for(int i = first[x]; i != -1; i = e[i].next){
			int v = e[i].v;
			if(dis[v] > dis[x] + e[i].cost){
				dis[v] = dis[x] + e[i].cost;
				if(inq[v] == 0){
					inq[v] = 1;
					cnt[v]++;
					if(cnt[v] > n + 1) return false;
					Q.push(v);
				}
			}
		}
	}
	return true;
}

int main(){
	int a,b,c;
	char s[10];
	while(scanf("%d",&n) != EOF,n){
		memset(first,-1,sizeof(first));
		memset(cnt,0,sizeof(cnt));
		ecnt = 0;
		scanf("%d",&m);
		for(int i = 1; i <= m; ++i){
			scanf("%d%d%s%d",&a,&b,s,&c);
			if(s[0] == 'g'){
				Add_edge(a + b,a - 1,-(c + 1));
			}
			else{
				Add_edge(a - 1,a + b,c - 1);
			}
		}
		if(Spfa(n + 1)) printf("lamentable kingdom\n");
		else printf("successful conspiracy\n");
	}
	return 0;
}
