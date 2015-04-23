////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-28 20:40:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1059
////Problem Title: 
////Run result: Accept
////Run time:515MS
////Run memory:532KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: p1014.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Thu 27 Nov 2014 11:21:14 PM CST
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
const int maxn = 60000;

int num[10];
int dp[maxn + 10];
int val[10][100],cnt[10];
int sum;

void Pre(){
	for(int i = 1; i <= 6; ++i){
		int n = num[i];
		cnt[i] = 0;
		for(int k = 1; k <= n; k <<= 1){
			val[i][++cnt[i]] = k * i;
			n -= k;
		}
		if(n > 0){
			val[i][++cnt[i]] = n * i;
		}
	}
}

int main(){
	int Case = 0;
	while(~scanf("%d%d%d%d%d%d",num + 1,num + 2,num + 3,num + 4,num + 5,num + 6)){
		sum = 0;
		for(int i = 1; i <= 6; ++i){
			sum += i * num[i];
		}
		if(sum == 0)
			break;
		printf("Collection #%d:\n",++Case);
		if(sum % 2){
			printf("Can't be divided.\n\n");
			continue;
		}
		sum /= 2;
		Pre();
		memset(dp,0,sizeof(dp));
		for(int i = 1; i <= 6; ++i){
			for(int o = 1; o <= cnt[i] ; ++o){
				for(int j = sum; j >= val[i][o]; --j){
					dp[j] = max(dp[j],dp[j - val[i][o]] + val[i][o]);
				}
			}
		}
		if(dp[sum] == sum)
			printf("Can be divided.\n\n");
		else
			printf("Can't be divided.\n\n");
	}
	return 0;
}
