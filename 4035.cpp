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

int T,N;
int K[MAXN],E[MAXN];
vector<int> g[MAXN];

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
		FOR(i,1,N){
			scanf("%lf%lf",&K[i],&E[i]);
			K[i] /= 100.0;
			E[i] /= 100.0;
		}
		

