////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-29 18:43:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5115
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:464KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: d.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 29 Nov 2014 04:19:54 PM CST
************************************************************************/

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
const int INF = 1 << 30;

int T,N;
int a[210],b[210];
int dp[210][210];

int main(){
	scanf("%d",&T);
	for(int tt = 1; tt <= T; ++tt){
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i)
			scanf("%d",a + i);
		for(int i = 1; i <= N; ++i)
			scanf("%d",b + i);
		memset(dp,0x3f,sizeof(dp));
		for(int i = 1; i <= N; ++i){
			dp[i][i] = b[i - 1] + b[i + 1];
			dp[i][i - 1] = dp[i + 1][i] = 0;
		}
		for(int len = 1; len < N; ++len){
			for(int i = 1; i + len <= N; ++i){
				int j = i + len;
				for(int k = i; k <= j; ++k){
					dp[i][j] = min(dp[i][j],dp[i][k - 1] + dp[k + 1][j] + b[i - 1] + b[j + 1]);
				}
			}
		}
		int sum = 0;
		for(int i = 1; i <= N; ++i)
			sum += a[i];
		printf("Case #%d: %d\n",tt,sum + dp[1][N]);
	}
	return 0;
}
