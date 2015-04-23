////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-09 22:44:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4771
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1160KB
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

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int N,M,K,stx,sty;
char g[110][110];
int vis[110][110];
int X[5],Y[5];
int dis[10][10];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

struct Node{
	int x,y,step;
	Node(int tx = 0,int ty = 0,int tstep = 0) :
		x(tx),y(ty),step(tstep) {}
};

int Bfs(int a,int b){
	queue<Node> Q;
	while(!Q.empty()) Q.pop();
	Q.push(Node(X[a],Y[a],0));
	vis[X[a]][Y[a]] = 1;
	while(!Q.empty()){
		Node cur = Q.front(); Q.pop();
		if(cur.x == X[b] && cur.y == Y[b])
			return cur.step;
		for(int i = 0; i < 4; ++i){
			int tx = cur.x + dir[i][0];
			int ty = cur.y + dir[i][1];
			if(tx < 1 || tx > N || ty < 1 || ty > M) continue;
			if(g[tx][ty] == '#' || vis[tx][ty]) continue;
			Q.push(Node(tx,ty,cur.step + 1));
			vis[tx][ty] = 1;
		}
	}
	return -1;
}

int main(){
	while(scanf("%d%d",&N,&M) != EOF){
		if(N == 0 && M == 0)
			break;
		REP(i,N){
			scanf("%s",g[i] + 1);
			REP(j,M) if(g[i][j] == '@') stx = i,sty = j;
		}
		scanf("%d",&K);
		REP(i,K) scanf("%d%d",&X[i],&Y[i]);
		X[K + 1] = stx,Y[K + 1] = sty;
		REP(i,K + 1) FOR(j,1,K + 1){
			MEM(vis,0);
			dis[i][j] = dis[j][i] = Bfs(i,j);
		}
		int arr[10],ans = INF;
		REP(i,K) arr[i] = i;
		do{
			int sum = 0;
			REP(i,K){
				int u,v = arr[i];
				if(i == 1) u = K + 1;
				else u = arr[i - 1];
				if(dis[u][v] == -1){
					sum = INF;
					break;
				}
				sum += dis[u][v];
			}
			ans = min(ans,sum);
		}while(next_permutation(arr + 1,arr + K + 1));
		if(ans >= INF) printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
}
