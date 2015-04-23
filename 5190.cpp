////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-21 21:56:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5190
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1628KB
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

int n,m;
int a[1000],b[1000];

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		int ans = INF;
		REP(i,m){
			scanf("%d%d",&a[i],&b[i]);
			int cnt = n / a[i];
			if(a[i] * cnt < n) cnt++;
			ans = min(ans,cnt * b[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
