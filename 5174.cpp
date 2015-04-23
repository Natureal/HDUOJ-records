////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-14 21:56:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5174
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1152KB
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
const ll mod = 2147483647;

int n;
int num[105];
ll val[105];

int main(){
	int tt = 0;
	while(scanf("%d",&n) != EOF){
		MEM(num,0);
		REP(i,n) scanf("%I64d",val + i);
		sort(val + 1,val + n + 1);
		int cnt = 1;
		num[1] = 1;
		FOR(i,2,n){
			if(val[i] != val[cnt]){
				val[++cnt] = val[i];
				num[cnt] = 1;
			}
			else ++num[cnt];
		}
		if(cnt == 1){
			printf("Case #%d: %d\n",++tt,-1);
			continue;
		}
		int ans = 0;
		FOR(i,1,n){
			int a = (i == 1) ? n : i - 1;
			int b = (i == n) ? 1 : i + 1;
			if((val[a] + val[i]) % mod == val[b]){
				ans += num[i];
			}
		}
		printf("Case #%d: %d\n",++tt,ans);
	}
	return 0;
}
