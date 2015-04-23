////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-31 21:45:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5167
////Problem Title: 
////Run result: Accept
////Run time:405MS
////Run memory:7104KB
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
const ll RA = 1e9;

int T,n;
int f[200];
map<ll,int> mp;

void Pre(){
	f[0] = f[1] = 1;
	FOR(i,2,45){
		f[i] = f[i - 1] + f[i - 2];
	}
}

void Dfs(int p,ll val){
	if(val > RA)
		return;
	mp[val] = 1;
	FOR(i,p,45) Dfs(i,val * f[i]);
}

int main(){
	Pre();
	Dfs(2,1);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n <= 1){
			printf("Yes\n");
			continue;
		}
		if(mp[n]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
