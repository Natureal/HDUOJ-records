////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-23 00:08:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5073
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1420KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 1004.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Wed 22 Oct 2014 11:26:09 PM CST
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
ll n,k,a[50010],sum[50010],sum2[50010];

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&k);
		sum[0] = sum2[0] = 0;
		for(int i = 1; i <= n; ++i){
			scanf("%I64d",&a[i]);
        }
        sort(a + 1,a + n + 1);
        for(int i = 1; i <= n; ++i){
			sum[i] = sum[i - 1] + a[i];
			sum2[i] = sum2[i - 1] + a[i] * a[i];
		}
		if(k == 0){
			printf("%.10f\n",1.0 * sum2[n] - sum[n] * sum[n] / (1.0 * n));
			continue;
		}
		if(n == k){
			printf("0\n");
			continue;
		}
		ll ans = (n - k) * sum2[n - k] - sum[n - k] * sum[n - k];
		for(int i = n - k + 1; i <= n; ++i){
			ans = min(ans,(n - k) * (sum2[i] - sum2[i - n + k]) -
					(sum[i] - sum[i - n + k]) * (sum[i] - sum[i - n + k]));
		}
		printf("%.10f\n",(double)ans / (1.0 * n - k));
	}
	return 0;
}
