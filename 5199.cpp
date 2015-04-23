////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-04-04 21:18:32
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5199
////Problem Title: 
////Run result: Accept
////Run time:1762MS
////Run memory:2652KB
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

map<int,int> mp;
int n,m;

inline int Read(){
      int x = 0;char ch = getchar();
      while(ch < '0' || ch > '9') ch = getchar();
      while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
      return x;
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		mp.clear();
		int a;
		REP(i,n){
			a = Read();
			mp[a]++;
		}
		REP(i,m){
			a = Read();
			printf("%d\n",mp[a]);
			mp[a] = 0;
		}
	}
	return 0;
}
