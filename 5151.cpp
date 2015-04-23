////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-27 21:35:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5151
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:1584KB
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
const int INF = 1 << 30;
const ll mod = 1000000007;

ll c[210][210];
int N,val[110];
ll dp[110][110];

void Pre(){
	for(int i = 0; i <= 200; ++i){
        c[i][0] = c[i][i] = 1;
		for(int j = 1; j < i; ++j){
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
}

int main(){
	Pre();
	while(scanf("%d",&N) != EOF){
		for(int i = 1; i <= N; ++i){
			scanf("%d",&val[i]);
		}
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= N; ++i){
			dp[i][i] = dp[i][i - 1] = dp[i + 1][i] = 1;
		}
		for(int len = 1; len <= N; ++len){
			for(int i = 1; i + len <= N; ++i){
				int j = i + len;
				for(int k = i; k <= j; ++k) if(k == i || k == j || (val[k - 1] == val[k + 1])){
					dp[i][j] = (dp[i][j] + ((dp[i][k - 1] * dp[k + 1][j]) % mod * c[j - i][k - i]) % mod) % mod;
					//printf("dp[%d][%d] : %lld\n",i,j,dp[i][j]);
				}
			}
		}
		printf("%I64d\n",dp[1][N]);
	}
	return 0;
}
