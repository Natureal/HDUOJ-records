////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-23 23:33:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5072
////Problem Title: 
////Run result: Accept
////Run time:875MS
////Run memory:1028KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1003.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Wed 22 Oct 2014 02:03:15 PM CST
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

int T;
int a[300010];
int fac[100010];
int f[100],cnt;
ll ans,n;

void Dfs(int p,int c,int val){
	if(p > cnt){
		if(c & 1) ans += fac[val] - 1;
		else if(c > 0) ans -= fac[val] - 1;
		return;
	}
	Dfs(p + 1,c,val);
	Dfs(p + 1,c + 1,val * f[p]);
}

void Dfs1(int p,int c,int val){
	if(p > cnt){
		if(c > 1) fac[val]++;
		return;
	}
	Dfs1(p + 1,c,val);
	Dfs1(p + 1,c + 1,val * f[p]);
}

int main(){
	int v,tmp;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d",&n);
		memset(fac,0,sizeof(fac));
		for(int i = 1; i <= n; ++i){
			scanf("%d",a + i);
			tmp = a[i];
			v = sqrt(1.0 * tmp);
			cnt = 0;
			for(int j = 2; j <= v; ++j) if(tmp % j == 0){
				f[++cnt] = j;
				fac[j]++;
				while(tmp % j == 0) tmp /= j;
			}
			if(tmp != 1){
				f[++cnt] = tmp;
				fac[tmp]++;
			}
			Dfs1(1,0,1);
		}
		ll res = 0;
		for(int i = 1; i <= n; ++i){
			cnt = 0;
			tmp = a[i];
			v = sqrt(1.0 * tmp);
			for(int j = 2; j <= v; ++j) if(tmp % j == 0){
				f[++cnt] = j;
				while(tmp % j == 0) tmp /= j;
			}
			if(tmp != 1){
				f[++cnt] = tmp;
			}
			ans = 0;
			Dfs(1,0,1);
			res += ans * (n - 1 - ans);	
		}
		printf("%I64d\n",n * (n - 1) * (n - 2) / (ll)6 - res / (ll)2);
	}
	return 0;
}
		
