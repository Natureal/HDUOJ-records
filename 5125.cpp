////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-30 01:11:03
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5125
////Problem Title: 
////Run result: Accept
////Run time:765MS
////Run memory:16148KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 5125.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 30 Nov 2014 12:18:29 AM CST
************************************************************************/

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
const int INF = 1 << 30;
const int maxn = 2010;

struct BIT{
	int c[maxn];
	int Lowbit(int x){
		return x & (-x);
	}
	int Getmax(int x){
		int res = 0;
		while(x > 0){
			res = max(res,c[x]);
			x -= Lowbit(x);
		}
		return res;
	}
	void Update(int x,int val){
		while(x <= maxn){
			c[x] = max(c[x],val);
			x += Lowbit(x);
		}
	}
}t[maxn];

int T,N,M,a[maxn],b[maxn];
int cp[maxn],cnt;

int main(){
	scanf("%d",&T);
	while(T--){
		memset(t,0,sizeof(t));
		cnt = 0;
		scanf("%d%d",&N,&M);
		for(int i = 1; i <= N; ++i){
			scanf("%d%d",a + i,b + i);
			cp[++cnt] = a[i];
			cp[++cnt] = b[i];
		}
		sort(cp + 1,cp + cnt + 1);
		cnt = unique(cp + 1,cp + cnt + 1) - cp;
		for(int i = 1; i <= N; ++i){
			a[i] = lower_bound(cp + 1,cp + cnt + 1,a[i]) - cp;
			b[i] = lower_bound(cp + 1,cp + cnt + 1,b[i]) - cp;
		}
		int ans = 0;
		for(int i = 1; i <= N; ++i){
			for(int j = M; j >= 0; --j){
				int tmp = t[j].Getmax(a[i] - 1) + 1;
				t[j].Update(a[i],tmp);
				ans = tmp > ans ? tmp : ans;
				if(j && j <= M){
					tmp = t[j - 1].Getmax(b[i] - 1) + 1;
					t[j].Update(b[i],tmp);
					ans = tmp > ans ? tmp : ans;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
