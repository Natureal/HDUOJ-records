////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-15 11:40:15
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5188
////Problem Title: 
////Run result: Accept
////Run time:530MS
////Run memory:25112KB
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
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 40;

int n,w;
struct node{
	int t,v,l;
	bool operator < (const node &b) const{
		return l - t < b.l - b.t;
	}
}nd[MAXN];

ll dp[30 * 100010];

void Max(ll &x,ll y){ if(x < y) x = y; }
template<typename T>
void Min(T &x,T y){ if(x > y) x = y; }

int main(){
	while(scanf("%d%d",&n,&w) != EOF){
		ll sumv = 0;
		REP(i,n){
			scanf("%d%d%d",&nd[i].t,&nd[i].v,&nd[i].l);
			sumv += nd[i].v;
		}
		if(sumv < w){
			printf("zhx is naive!\n");
			continue;
		}
		if(w == 0){
			puts("0");
			continue;
		}
		MEM(dp,0);
		sort(nd + 1,nd + n + 1);
		int ans = INF,sum = 0;
		REP(i,n){
			int bot = max(nd[i].l,nd[i].t);
			sum += bot;
			sum = min(sum,ans);
			for(int j = 2; j <= sum; ++j) Max(dp[j],dp[j - 1]);
			for(int j = sum; j >= bot; --j){
				Max(dp[j],dp[j - nd[i].t] + nd[i].v);
				if(dp[j] >= w) ans = min(ans,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
