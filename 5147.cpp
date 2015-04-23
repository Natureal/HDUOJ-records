////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-20 21:24:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5147
////Problem Title: 
////Run result: Accept
////Run time:920MS
////Run memory:2464KB
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
const int maxn = 50000;

int T,n,v[maxn + 10];
ll s1[maxn + 10],s2[maxn + 10];

struct BIT{
	int c[maxn + 10];
	void clear(){
		memset(c,0,sizeof(c));
	}
	int Lowbit(int x){
		return x & (-x);
	}
	int Getsum(int x){
		int res = 0;
		while(x){
			res += c[x];
			x -= Lowbit(x);
		}
		return res;
	}
	void Update(int x,int d){
		while(x <= maxn){
			c[x] += d;
			x += Lowbit(x);
		}
	}
}B1,B2;

int main(){
	scanf("%d",&T);
	while(T--){
		B1.clear();
		B2.clear();
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i)
			scanf("%d",v + i);
		for(int i = 1; i <= n; ++i){
			s1[i] = B1.Getsum(v[i] - 1);
			B1.Update(v[i],1);
		}
		for(int i = n; i >= 1; --i){
			s2[i] = s2[i + 1];
			s2[i] += B2.Getsum(maxn + 1) - B2.Getsum(v[i]);
			B2.Update(v[i],1);
		}
		ll ans = 0;
		for(int i = 1; i < n; ++i){
			ans = ans + s1[i] * s2[i + 1];
		}
		printf("%I64d\n",ans);
	}
	return 0;
}

