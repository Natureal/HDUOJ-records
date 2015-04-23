////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-25 23:53:54
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5084
////Problem Title: 
////Run result: Accept
////Run time:1375MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1003.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 25 Oct 2014 08:01:45 PM CST
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
const int maxn = 3010;

int n,m;
int r,c;
int t[maxn];

int main(){
	while(scanf("%d",&n) != EOF){
		int top = 2 * n - 1;
		for(int i = 0; i < top; ++i)
			scanf("%d",t + i);
		scanf("%d",&m);
		ll ans = 0;
		int tmp = 0;
		while(m--){
			scanf("%d %d",&r,&c);
			r = (r + tmp) % n;
			c = (c + tmp) % n;
			tmp = 0;
			for(int i = 0; i < n; ++i)
				tmp += t[n - 1 + c - i] * t[n - 1 - r + i];
			ans += tmp;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
		
		
