////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-01-31 21:16:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5166
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1104KB
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

int T,n;
int A[1010];

int main(){
	int a;
	scanf("%d",&T);
	while(T--){
		MEM(A,0);
		scanf("%d",&n);
		REP(i,n){
			scanf("%d",&a);
			A[a] = 1;
		}
		int p1 = 0,p2 = 0;
		REP(i,1010) if(!A[i]){
			if(!p1) p1 = i;
			else p2 = i;
			if(p1 && p2) break;
		}
		printf("%d %d\n",p1,p2);
	}
	return 0;
}
