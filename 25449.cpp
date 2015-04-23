////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-04 23:51:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1132KB
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
const int maxn = 110;

int N,M;
int g[maxn][maxn];

void Floyd(){
	for(int k = 1; k <= N; ++k)
		for(int i = 1; i <= N; ++i)
			for(int j = 1; j <= N; ++j)
				g[i][j] = min(g[i][j],g[i][k] + g[k][j]);
}

int main(){
	int a,b,c;
	while(scanf("%d%d",&N,&M) != EOF){
		if(N == 0 && M == 0) break;
		for(int i = 1; i <= N; ++i)
			fill(g[i] + 1,g[i] + N + 1,INF);
		for(int i = 1; i <= M; ++i){
			scanf("%d%d%d",&a,&b,&c);
			g[a][b] = g[b][a] = min(g[a][b],c);
		}
		Floyd();
		printf("%d\n",g[1][N]);
	}
	return 0;
}
