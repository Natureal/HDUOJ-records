////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-20 01:17:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1532
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1260KB
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
const int INF = 1 << 30;
const int maxn = 210;

int c[maxn][maxn],n,m;
bool vis[maxn];

int Dfs(int p,int minc){
	if(p == m) return minc;
	vis[p] = true;
	for(int i = 1; i <= m; ++i) if(!vis[i] && c[p][i] > 0){
		int d = Dfs(i,min(minc,c[p][i]));
		if(d > 0){ //一旦发现就该返回，因为就找一条增广路
			c[p][i] -= d;
			c[i][p] += d;
			return d;
		}
	}
	return 0;
}

int FF(){
	int plus,max_flow = 0;
	while(1){
		memset(vis,false,sizeof(vis));
		plus = Dfs(1,INF);
		if(plus == 0) break;
		max_flow += plus;
	}
	return max_flow;
}

int main(){
	int t1,t2,t3;
	while(scanf("%d%d",&n,&m) != EOF){
		memset(c,0,sizeof(c));
		for(int i = 1; i <= n; ++i){
			scanf("%d%d%d",&t1,&t2,&t3);
			c[t1][t2] += t3;
		}
		printf("%d\n",FF());
	}
	return 0;
}
