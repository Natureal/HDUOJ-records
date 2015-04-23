////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-11 23:54:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5064
////Problem Title: 
////Run result: Accept
////Run time:828MS
////Run memory:66372KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1003.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 11 Oct 2014 08:42:37 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
const int maxn = 1 << 12;

int val[1 << 22],c[maxn],n,m,t;
int dp[maxn][maxn];

int main(){
	scanf("%d",&t);
	while(t--){
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; ++i) scanf("%d",&val[i]);
		sort(val + 1,val + n + 1);
		int cur = 1;
		c[cur] = 1;
		for(int i = 2; i <= n; ++i){
			if(val[i] == val[cur]) ++c[cur];
			else{
				val[++cur] = val[i];
				c[cur] = 1;
			}
		}
		int ans = 0;
		for(int i = 1; i <= cur; ++i) dp[i][i] = c[i];
		for(int i = 1; i <= cur; ++i){
			int k = i,tmax;
			tmax = dp[i][i];
			ans = max(ans,tmax);
			for(int j = i + 1; j <= cur; ++j){
				for(; k > 0 && val[i] - val[k] <= val[j] - val[i]; --k){
					tmax = max(tmax,dp[k][i] + 1);
				}
				dp[i][j] = tmax;
				ans = max(ans,tmax);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
					
