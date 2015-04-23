////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-16 12:28:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4418
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:1972KB
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
const int MAXN = 210;
const double eps = 1e-8;

int T;
int N,M,Y,X,D;
double P[MAXN];
double g[MAXN][MAXN];
bool can[MAXN];

void Gauss(){
	int i,col;
	for(i = 0,col = 0; col < N; ++i,++col){
		int r = i;
		for(int j = i + 1; j < N; ++j)
			if(fabs(g[j][col]) > fabs(g[r][col])) r = j;
		if(r != i) for(int j = col; j <= N; ++j) swap(g[r][j],g[i][j]);
		if(fabs(g[i][col]) < eps){
			--i;
			continue;
		}
		for(int j = N; j >= col; --j) g[i][j] /= g[i][col];
		for(int k = 0; k < N; ++k) if(k != i){
			for(int j = N; j >= col; --j)
				g[k][j] -= g[k][col] * g[i][j];
		}
	}
}

void Debug(){
	for(int i = 0; i < N; ++i){
		for(int j = 0; j <= N; ++j) printf("%.2f ",g[i][j]);
		puts("");
	}
}

void Bfs(){
	queue<int> Q;
	while(!Q.empty()) Q.pop();
	MEM(can,false);
	can[Y] = can[(N - Y) % N] = true;
	Q.push(Y);
	Q.push((N - Y) % N);
	while(!Q.empty()){
		int cur = Q.front(); Q.pop();
		FOR(j,1,M){
			int nxt = (cur - j + N) % N;
			if(P[j] >= eps && !can[nxt]){
				can[nxt] = true;
				Q.push(nxt);
			}
		}
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		MEM(g,0);
		scanf("%d%d%d%d%d",&N,&M,&Y,&X,&D);
		FOR(i,1,M) scanf("%lf",&P[i]),P[i] /= 100.0;
		if(X == Y){
			printf("0.00\n");
			continue;
		}
		N = (N - 1) * 2;
		if(D > 0) X = (N - X) % N;
		Bfs();
		if(!can[X]){
			printf("Impossible !\n");
			continue;
		}
		REP(i,N){
			if(i == Y || i == (N - Y) % N){
				g[i][i] = 1;
				g[i][N] = 0;
				continue;
			}
			g[i][i] = -1;
			FOR(j,1,M){
				int nxt = (i + j) % N;
				if(!can[nxt]) continue;
				g[i][nxt] += P[j];
				g[i][N] -= j * P[j];
			}
		}
		//Debug();
		Gauss();
		for(int i = 0; i < N; ++i) if(fabs(g[i][X]-1) < eps){
			printf("%.2f\n",g[i][N]);
			break;
		}
	}
	return 0;
}
