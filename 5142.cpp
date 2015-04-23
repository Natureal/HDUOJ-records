////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-13 22:07:08
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5142
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1096KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1001.cpp
    > Author: Natureal
    > Mail: 564374850@qq.com 
    > Created Time: Sat 13 Dec 2014 07:03:09 PM CST
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
typedef unsigned long long ull;
const int INF = 1 << 30;

int n,a;
int v[100];

int main(){
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i){
		scanf("%d",&a);
		int cnt = 0;
		while(a){
			if(a & 1) v[++cnt] = 1;
			else v[++cnt] = 0;
			a >>= 1;
		}
		int base = 1,ans = 0;
		for(int i = cnt; i >= 1; --i){
			ans += base * v[i];
			base *= 2;
		}
		printf("%d\n",ans);
	}
	return 0;
}
