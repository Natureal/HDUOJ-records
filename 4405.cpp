////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-30 11:34:49
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4405
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:5660KB
//////////////////System Comment End//////////////////
#pragma comment(linker,"/STACK:1024000000,1024000000")
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
typedef pair<int,int> pii;
const int INF = 1 << 30;

int N,M;
double dp[100020];
int vis[100020];

double Solve(int p){
    if(dp[p]) return dp[p];
    if(p >= N) return 0.0;
    if(vis[p]){
        dp[p] += Solve(vis[p]);
        return dp[p];
    }
    for(int i = 1; i <= 6; ++i)
        dp[p] += (Solve(p + i) + 1.0) / 6.0;
    return dp[p];
}

int main(){
	int a,b;
	while(scanf("%d%d",&N,&M) != EOF){
		if(N == 0 && M == 0) break;
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= M; ++i){
			scanf("%d%d",&a,&b);
			vis[a] = b;
		}
		Solve(0);
		printf("%.4f\n",dp[0]);
	}
	return 0;
}
