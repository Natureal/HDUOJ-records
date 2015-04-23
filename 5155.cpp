////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-03 23:54:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5155
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:1272KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll dp[110][110];
ll c[60][60];
int n,m;

int main(){
	for(int i = 0; i <= 50; ++i){
		c[i][0] = 1;
		for(int j = 1; j <= i; ++j)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	while(scanf("%d%d",&n,&m) != EOF){
		memset(dp,0,sizeof(dp));
		for(int j = 0; j <= m; ++j)
			dp[1][j] = c[m][j];
		for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		for(int k = 1; k <= m; ++k)
		for(int t = min(m - j,k); t >= 0; --t){
			dp[i + 1][j + t] = (dp[i + 1][j + t] + 
				dp[i][j] * c[m - j][t] % mod * c[j][k - t] % mod) % mod;
		}
		printf("%I64d\n",dp[n][m]);
	}
	return 0;
}