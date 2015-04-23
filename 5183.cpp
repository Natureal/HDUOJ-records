////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 13:48:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5183
////Problem Title: 
////Run result: Accept
////Run time:1450MS
////Run memory:60684KB
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

int T,n,K;
ll sum[1000010];
set<ll> st;
int A[1000010];

inline int Read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int main(){
	T = Read();
	REP(tt,T){
		st.clear();
		n = Read();
		K = Read();
		REP(i,n) A[i] = Read();
		bool flag = false;
		for(int i = 1; i <= n; ++i){
			if(i & 1)	sum[i] = sum[i - 1] + A[i];
			else	sum[i] = sum[i - 1] - A[i];
		}
		for(int i = n; i >= 1; --i){
			st.insert(sum[i]);
			ll cur = (i & 1) ? sum[i - 1] + K : sum[i - 1] - K;
			if(st.count(cur)){
				flag = true;
				break;
			}
		}
		if(flag) printf("Case #%d: Yes.\n",tt);
		else printf("Case #%d: No.\n",tt);
	}
	return 0;
}
