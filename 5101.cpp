////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-08 22:48:43
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5101
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:1888KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: b.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 08 Nov 2014 07:40:49 PM CST
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

int T,n;
ll k,v[1010][110],x[100010],cnt;
ll num[1010],ans;

int main(){
	scanf("%d",&T);
	while(T--){
		cnt = ans = 0;
		scanf("%d%I64d",&n,&k);
		for(int i = 0; i < n; ++i){
			scanf("%I64d",&num[i]);
			for(int j = 0; j < num[i]; ++j){
				scanf("%I64d",&v[i][j]);
				x[++cnt] = v[i][j];
			}
			sort(v[i],v[i] + num[i]);
		}
		sort(x + 1,x + cnt + 1);
		for(int i = 0; i < n; ++i){
            for(int j = 0; j < num[i]; ++j){
                ans += cnt - (lower_bound(x + 1,x + cnt + 1,k + 1 - v[i][j]) - x) + 1;
                ans -= num[i] - (lower_bound(v[i],v[i] + num[i],k + 1 - v[i][j]) - v[i]);
            }
		}
		printf("%I64d\n",ans / 2);
	}
	return 0;
}
