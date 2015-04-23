////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-28 01:39:57
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5045
////Problem Title: 
////Run result: Accept
////Run time:140MS
////Run memory:8592KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 5045.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 28 Sep 2014 01:14:37 AM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lpos (pos << 1)
#define rpos (pos << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
typedef long long ll;
const int INF = 1 << 29;

int T,N,M;
double p[15][1005];
double dp[1005][1050];

int main(){
	scanf("%d",&T);
	for(int t = 1; t <= T; ++t){
		scanf("%d%d",&N,&M);
		memset(dp,0,sizeof(dp));
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < M; ++j)
				scanf("%lf",&p[i][j]);
			dp[0][1 << i] = p[i][0];
		}
		int top = 1 << N,next;
		for(int i = 1; i < M; ++i){
			for(int j = 0; j < top; ++j) if(dp[i - 1][j]){
				for(int k = 0; k < N; ++k) if(!(j & (1 << k))){
					next = j | (1 << k);
					if(next == top - 1) next = 0;
					if(dp[i - 1][j] + p[k][i] > dp[i][next])
						dp[i][next] = dp[i - 1][j] + p[k][i];
				}
			}
		}
		double ans = 0.0;
		for(int j = 0; j < top; ++j)
			ans = max(ans,dp[M - 1][j]);
		printf("Case #%d: %.5lf\n",t,ans);
	}
	return 0;
}
