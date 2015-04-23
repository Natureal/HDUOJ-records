////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-18 21:23:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5207
////Problem Title: 
////Run result: Accept
////Run time:358MS
////Run memory:2400KB
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
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 100010;

int T;
int n,v[MAXN];
int vis[MAXN];
int tmax;

int main(){
	scanf("%d",&T);
	FOR(tt,1,T){
		MEM(vis,0);
		tmax = 0;
		scanf("%d",&n);
		FOR(i,1,n){
			scanf("%d",&v[i]);
			vis[v[i]]++;
			tmax = max(tmax,v[i]);
		}
		for(int i = tmax; i >= 1; --i){
			int cnt = 0;
			for(int j = i; cnt < 2 && j <= tmax; j += i) if(vis[j]){
				cnt += vis[j];
			}
			if(cnt >= 2){
				printf("Case #%d: %d\n",tt,i);
				break;
			}
		}
	}
	return 0;
}
