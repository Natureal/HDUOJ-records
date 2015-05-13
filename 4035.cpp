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
const int INF = (1 << 30) - 1;
const int MAXN = 10010;
const double eps = 1e-9;

int T,N,m[MAXN];
double dp[MAXN],K[MAXN],E[MAXN];
double A[MAXN],B[MAXN],C[MAXN],D[MAXN];
vector<int> g[MAXN];

void Solve(int p,int pre){
	//printf("p : %d\n",p);
	A[p] = K[p];
	B[p] = (1.0 - K[p] - E[p]) / m[p];
	C[p] = 0.0;
	D[p] = 1.0 - K[p] - E[p];
	for(int i = 0; i < m[p]; ++i){
		int v = g[p][i];
		if(v == pre) continue;
		Solve(v,p);
		A[p] += B[p] * A[v];
		D[p] += B[p] * D[v];
		C[p] += B[p] * B[v];
	}
	A[p] /= (1.0 - C[p]);
	B[p] /= (1.0 - C[p]);
	D[p] /= (1.0 - C[p]);
}

int main(){
	int a,b;
	scanf("%d",&T);
	FOR(tt,1,T){
		scanf("%d",&N);
		FOR(i,1,N) g[i].clear();
		REP(i,N - 1){
			scanf("%d%d",&a,&b);
			g[a].PB(b);
			g[b].PB(a);
		}
		FOR(i,1,N) m[i] = g[i].size();
		FOR(i,1,N){
			scanf("%lf%lf",&K[i],&E[i]);
			K[i] /= 100.0;
			E[i] /= 100.0;
		}
		Solve(1,0);
		printf("Case %d: ",tt);
		if(fabs(1 - A[1]) < eps) printf("impossible\n");
		else{
			dp[1] = D[1] / (1 - A[1]);
			printf("%.6f\n",dp[1]);
		}
	}
	return 0;
}

