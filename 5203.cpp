////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-11 21:15:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5203
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1680KB
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

int n,m;
int v[1010];

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		FOR(i,1,m){
			scanf("%d",&v[i]);
		}
		sort(v + 1,v + m + 1);
		ll l1 = v[1] - 1;
		ll l2 = n - v[m];
		if(l1 == l2){
			printf("0\n");
			continue;
		}
		if(l1 < l2) swap(l1,l2);
		if(l2 == 0){
			if(l1 < 3){
				printf("0\n");
				continue;
			}
			l1 -= 2;
			ll t = (l1 + 1) / 2;
			if(l1 % 2 == 0) t = -t;
			ll ans = ((ll)t * (t + 1)) / 2;
			cout << ans << endl;
		}
		else{
			ll ans = 0;
			ll bot = (l1 - l2) / 2;
			ll res = l1 - bot - bot - 1;
			cout << res << endl;
		}
	}
	return 0;
}
