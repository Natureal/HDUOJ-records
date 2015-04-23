////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-06 09:57:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4813
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1172KB
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
#define REV(i,n) for(int i=(n-1);i>=0;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int T;
int N,M;
char s[1010];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		scanf("%s",s + 1);
		int len = strlen(s + 1);
		FOR(i,1,len){
			printf("%c",s[i]);
			if(i % M == 0) puts("");
		}
	}
	return 0;
}