////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-20 21:23:46
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5146
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1096KB
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

int T,n,v[1010];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i) scanf("%d",v + i);
		ll s1 = 0,s2 = 0;
		for(int i = 1; i <= n; i += 2) s1 += v[i];
		for(int i = 2; i <= n; i += 2) s2 += v[i];
		int flag = 1;
		for(int i = 1; i <= n; ++i){
			if(v[i] != v[n + 1 - i]){
				flag = 0;
				break;
			}
		}
		if(s1 == s2 && !flag) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
