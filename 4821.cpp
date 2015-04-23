////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-02-06 10:25:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4821
////Problem Title: 
////Run result: Accept
////Run time:421MS
////Run memory:3100KB
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
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;
const int MAXN = 100010;
const ull B = 1e9 + 7;

int L,M;
char s[MAXN];
ull hash[MAXN];
map<ull,int> mp;

int main(){
	while(scanf("%d%d%s",&M,&L,s + 1) != EOF){
		int len = strlen(s + 1);
		ull cur = 0,tmp = 1;
		REP(i,L) tmp = tmp * B;
		FOR(i,1,len){
			cur = cur * B + s[i] - 'a';
			if(i > L) cur -= tmp * (s[i - L] - 'a');
			if(i >= L) hash[i - L + 1] = cur;
		}
		int ans = 0;
		FOR(i,1,L){
			mp.clear();
			int flag,pos = i,cnt = 0;
			for(int j = 1; ; ++j){
				if(pos + L - 1 > len) break;
				flag = ++mp[hash[pos]];
				if(flag == 2) cnt++;
				if(j > M){
					flag = --mp[hash[pos - L * M]];
					if(flag == 1) cnt--;
				}

				pos += L;
				if(j >= M) ans += (cnt == 0);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
				
				
