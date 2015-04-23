////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-06 09:57:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4815
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:16848KB
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

int T,N;
double P,dp[50][40010];
int sum,val[50];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%lf",&N,&P);
		sum = 0;
		FOR(i,1,N){
			scanf("%d",val + i);
			sum += val[i];
		}
		MEM(dp,0);
		dp[0][0] = 1.0;
		FOR(i,1,N){
			FOR(j,0,sum){
				dp[i][j] = dp[i - 1][j] * 0.5;
				if(j >= val[i]) dp[i][j] += dp[i - 1][j - val[i]] * 0.5;
			}
		}
		FOR(i,1,sum) dp[N][i] += dp[N][i - 1];
		FOR(i,0,sum){
			if(dp[N][i] > P || fabs(dp[N][i] - P) < 1e-8){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}