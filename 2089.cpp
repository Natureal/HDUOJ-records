////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-26 13:03:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2089
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1088KB
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
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int n,m;
int dp[10][10][2];
int di[10],cnt;

int Dfs(int p,int pre,int flag){
	if(p <= 0)
		return 1;
	if(dp[p][pre][flag] != -1)
		return dp[p][pre][flag];
	int res = 0,top = (flag == 1) ? 9 : di[p];
 	FOR(i,0,top){
		 if(i == 4 || (i == 2 && pre == 6))
			 continue;
		 res += Dfs(p - 1,i,flag || i < di[p]);
	}
	return dp[p][pre][flag] = res;
}

int Solve(int v){
	MEM(dp,-1);
	cnt = 0;
	while(v){
		di[++cnt] = v % 10;
		v /= 10;
	}
	return Dfs(cnt,0,0);
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		if(!n && !m) break;
		if(n > m){ n = n ^ m , m = n ^ m , n = n ^ m;}
		printf("%d\n",Solve(m) - Solve(n - 1));
	}
	return 0;
}
