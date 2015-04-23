////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-10 12:15:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1466
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:308KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: a.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Mon 10 Nov 2014 11:44:43 AM CST
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

int n;
int dp[21][210];

int main(){
	memset(dp,0,sizeof(dp));
	for(int i = 0; i <= 20; ++i)
		dp[i][0] = 1;
	for(int i = 1; i <= 20; ++i){
		for(int r = 1; r < i; ++r){
			for(int j = 0; j <= 200; ++j){
				if(dp[r][j]){
					dp[i][(i - r) * r + j] = 1;
				}
			}
		}
	}
	while(scanf("%d",&n) != EOF){
		printf("0");
		for(int i = 1; i <= 200; ++i) if(dp[n][i])
			printf(" %d",i);
		puts("");
	}
	return 0;
}
