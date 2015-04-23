////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-11 07:18:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2262
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:2072KB
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
const int MAXN = 20;
const int MAXM = 250;
const double eps = 1e-6;

int n,m,top;
char g[MAXN][MAXN];
double A[MAXM][MAXM];
bool can[MAXN][MAXN];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

void Bfs(){
	MEM(can,false);
	queue<int> x,y;
	while(!x.empty()) x.pop();
	while(!y.empty()) y.pop();
	REP(i,n) REP(j,m) if(g[i][j] == '$'){
		x.push(i);
		y.push(j);
		can[i][j] = true;
	}
	while(!x.empty()){
		int curx = x.front(); x.pop();
		int cury = y.front(); y.pop();
		for(int k = 0; k < 4; ++k){
			int tx = curx + dir[k][0];
			int ty = cury + dir[k][1];
			if(tx >= 0 && tx < n && ty >= 0 && ty < m && g[tx][ty] != '#'){
				if(can[tx][ty] == false){
					can[tx][ty] = true;
					x.push(tx);
					y.push(ty);
				}
			}
		}
	}
}

bool Gauss(){
	int i,col;
	for(i = 0,col = 0; col < top; ++i,++col){
		int r = i;
		for(int j = i + 1; j < top; ++j)
			if(fabs(A[j][col]) > fabs(A[r][col])) r = j;
		if(r != i)
			for(int j = 0; j <= top; ++j) swap(A[r][j],A[i][j]);
		if(fabs(A[i][col]) < eps){
			--i;
			continue;
		}
		for(int k = i + 1; k < top; ++k) if(!(fabs(A[k][col]) < eps)){
			double f = A[k][col] / A[i][col];
			for(int j = col; j <= top; ++j) A[k][j] -= f * A[i][j];
		}
		for(int j = top; j >= col; --j) A[i][j] /= A[i][col];
	}
	for(; i < top; ++i) if(!(fabs(A[i][top]) < eps))
		return false;
	int key;
	for(i = top - 1; i >= 0; --i){
		for(key = 0; fabs(A[i][key]) < eps; ++key);
		for(int j = key + 1; j < top; ++j)
			A[i][top] -= A[j][top] * A[i][j];
	}
	return true;
}

bool gauss(){
	int i,j;
	for(i = 0,j = 0; i < top && j < top; ++j){
		int k;
		for(k = i; k < top; ++k){
			if(!(fabs(A[k][j]) < eps))
				break;
		}
		if(k < top){
			if(i != k)
				for(int r = j; r <= top; ++r) swap(A[i][r],A[k][r]);
			double tt = 1 / A[i][j];
			for(int r = j; r <= top; ++r) A[i][r] *= tt;
			for(int r = 0; r < top; ++r) if(r != i){
				for(int t = top; t >= j; --t)
					A[r][t] -= A[r][j] * A[i][t];
			}
			++i;
		}
	}
	for(int r = i; r < top; ++r)
		if(!(fabs(A[r][top]) < eps))
			return false;
	return true;
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		top = n * m;
		REP(i,n) scanf("%s",g[i]);
		REP(i,top) REP(j,top + 1) A[i][j] = 0.0;
		Bfs();
		int sx,sy;
		REP(i,n) REP(j,m) if(g[i][j] == '@'){
			sx = i;
			sy = j;
			break;
		}
		REP(i,n) REP(j,m) if(g[i][j] != '#'){
			int a = i * m + j;
			if(g[i][j] == '$'){
				A[a][top] = 0;
				A[a][a] = 1;
				continue;
			}
			int cnt = 0;
			REP(k,4){
				int tx = i + dir[k][0];
				int ty = j + dir[k][1];
				if(tx >= 0 && tx < n && ty >= 0 && ty < m
						&& g[tx][ty] != '#' && can[tx][ty]){
					A[a][tx * m + ty] = 1;
					cnt++;
				}
			}
			A[a][a] = A[a][top] = -1.0 * cnt;
		}
		if(can[sx][sy] && gauss()){
			//ÕÒÖ÷Ôª
			for(int i = 0; i < top; ++i){
				if(fabs(A[i][sx * m + sy] - 1.0) < eps){
					printf("%.6f\n",A[i][top]);
					break;
				}
			}
		}
		else printf("-1\n");
	}
	return 0;
}
