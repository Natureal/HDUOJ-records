////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-10 02:00:49
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4778
////Problem Title: 
////Run result: Accept
////Run time:3712MS
////Run memory:9368KB
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

int G,B,S,total;
int bag[30][30],color[10];
int dp[2100000];

int Dfs(int sta,int rem,int co[10]){
	if(dp[sta] != -1)
		return dp[sta];
    if(!sta || !rem) return 0;
	//printf("sta %d , rem %d \n",sta,rem);
	int res = 0;
	REP(i,B) if(sta & (1 << (i - 1))){
		int nxt_co[10] = {0};
		int cnt = 0;
		REP(j,G){
			nxt_co[j] = co[j] + bag[i][j];
			cnt += nxt_co[j] / S;
			nxt_co[j] %= S;
		}
		if(cnt) res = max(res,Dfs(sta ^ (1 << (i - 1)),rem - cnt,nxt_co) + cnt);
		else res = max(res,rem - Dfs(sta ^ (1 << (i - 1)),rem,nxt_co));
	}
	return dp[sta] = res;
}

int main(){
	int n,c;
	while(scanf("%d%d%d",&G,&B,&S) != EOF){
		if(!G && !B && !S)	break;
		MEM(color,0);
		MEM(bag,0);
		MEM(dp,-1);
		REP(i,B){
			scanf("%d",&n);
			REP(j,n){
				scanf("%d",&c);
				bag[i][c]++;
				color[c]++;
			}
		}
		total = 0;
		REP(i,G) total += color[i] / S;
		int co[10]; MEM(co,0);
		printf("%d\n",2 * Dfs((1 << B) - 1,total,co) - total);
	}
	return 0;
}
