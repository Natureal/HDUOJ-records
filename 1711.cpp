////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-16 21:42:01
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1711
////Problem Title: 
////Run result: Accept
////Run time:468MS
////Run memory:5080KB
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
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
typedef unsigned long long ull;
const int INF = 1 << 30;

int T,N,M;
int s1[1000010];
int s2[10010];
int P[10010];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		for(int i = 1; i <= N; ++i) scanf("%d",s1 + i);
		for(int i = 1; i <= M; ++i) scanf("%d",s2 + i);
		P[1] = 0;
		int j = 0;
		for(int i = 2; i <= M; ++i){
			while(j > 0 && s2[j + 1] != s2[i]) j = P[j];
			if(s2[j + 1] == s2[i]) j++;
			P[i] = j;
		}
		j = 0;
		int ans = -1;
		for(int i = 1; i <= N; ++i){
			while(j > 0 && s2[j + 1] != s1[i]) j = P[j];
			if(s2[j + 1] == s1[i]) j++;
			if(j == M){
				ans = i - M + 1;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
