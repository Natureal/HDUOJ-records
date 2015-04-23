////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-04 21:42:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5200
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:2808KB
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
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 50010;

inline int Read(){
	int x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x;
}

int N,Q;
int vis[MAXN];
int now;
int ans[MAXN];

struct node{
	int h,id;
}nd[MAXN];

struct query{
	int q,id;
}q[MAXN];

bool cmp(query a,query b){
	return a.q > b.q;
}

bool cmp1(node a,node b){
	return a.h < b.h;
}

int main(){
	while(scanf("%d%d",&N,&Q) != EOF){
		now = 0;
		MEM(vis,0);
		for(int i = 1; i <= N; ++i){
			nd[i].h = Read();
			nd[i].id = i;
		}
		for(int i = 1; i <= Q; ++i){
			q[i].q = Read();
			q[i].id = i;
		}
		sort(q + 1,q + Q + 1,cmp);
		sort(nd + 1,nd + N + 1,cmp1);
		//init
		int pos;
		for(pos = N; pos >= 1; --pos){
			if(nd[pos].h > q[1].q) vis[nd[pos].id] = 1;
			else break;
		}
		for(int i = 1; i <= N; ++i) if(vis[i] && !vis[i - 1]) now++;
		ans[q[1].id] = now;
		for(int i = 2; i <= Q; ++i){
			for(; pos >= 1; --pos){
				if(nd[pos].h <= q[i].q) break;
				int cur = nd[pos].id;
				int cnt = vis[cur - 1] + vis[cur + 1];
				vis[cur] = 1;
				if(cnt == 2) now--;
				if(cnt == 0) now++;
			}
			ans[q[i].id] = now;
		}
		for(int i = 1; i <= Q; ++i)
			printf("%d\n",ans[i]);
	}
	return 0;
}


	
