
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
#define PB(a) push_back(a)

typedef long long ll;
typedef pair<int,int> pii;
const double eps = 1e-13;
const int INF = (1 << 30) - 1;
const int MAXN = 30;

double P;
double g[MAXN][MAXN];

void Gauss(){
	for(int i = 0,col = 0; col <= 20; ++i,++col){
		int r = i;
		for(int j = i + 1; j <= 20; ++j)
			if(fabs(g[j][col]) > fabs(g[r][col])) r = j;
		if(r != i)
			for(int j = col; j <= 21; ++j) swap(g[i][j],g[r][j]);
		/*if(fabs(g[i][col]) < eps){
			--i;
			continue;
		}
		这部分实际上在这题中并不需要出现，写了反而被卡精度QAQ
		*/
		for(int j = 21; j >= col; --j) g[i][j] /= g[i][col];
		for(int k = 0; k <= 20; ++k) if(k != i){
			for(int j = 21; j >= col; --j)
				g[k][j] -= g[k][col] / g[i][col] * g[i][j];
		}
	}
}


int main(){
	while(scanf("%lf",&P) != EOF){
		MEM(g,0);
		FOR(i,0,19){
			g[i][21] += 1.0;
			g[i][i] += 1.0;
			if(i + 1 <= 20) g[i][i + 1] += -P;
			g[i][max(i - 2,0)] += P - 1.0;
		}
		g[20][20] = 1.0;
		Gauss();
		printf("%.10f\n",g[0][21] * 2 - g[19][21]);
	}
	return 0;
}


