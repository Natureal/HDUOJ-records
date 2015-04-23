////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-09 22:45:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4772
////Problem Title: 
////Run result: Accept
////Run time:0MS
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

int N;
int g[50][50],g2[50][50];
int tg[50][50];

int main(){
	while(scanf("%d",&N) != EOF && N){
		REP(i,N) REP(j,N) scanf("%d",&g[i][j]);
		REP(i,N) REP(j,N) scanf("%d",&g2[i][j]);
		int ans = 0;
		REP(o,4){
			int cnt = 0;
			REP(i,N) REP(j,N){
				tg[j][N - i + 1] = g[i][j];
			}
			REP(i,N) REP(j,N){
				if(tg[i][j] == g2[i][j])
					++cnt;
			}
			ans = max(ans,cnt);
			memcpy(g,tg,sizeof(tg));
		}
		printf("%d\n",ans);
	}
	return 0;
}

