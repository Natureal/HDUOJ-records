////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-06 21:52:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5139
////Problem Title: 
////Run result: Accept
////Run time:717MS
////Run memory:2732KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1002.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 06 Dec 2014 08:12:31 PM CST
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
const ll mod = 1000000007;

ll ta[100010],t,f;
int cnt,n;
struct node{
	int val,pos;
}b[100010];

bool cmp1(node a,node b){
	return a.val < b.val;
}

bool cmp2(node a,node b){
	return a.pos < b.pos;
}

int main(){
	t = f = 1;
	while(scanf("%d",&n) != EOF){
		b[++cnt].val = n;
		b[cnt].pos = cnt;
	}
	sort(b + 1,b + cnt + 1,cmp1);
	for(int i = 1; i <= cnt; ++i){
		for(int j = b[i - 1].val + 1; j <= b[i].val; ++j){
			f = (f * j) % mod;
			t = (t * f) % mod;
		}
		ta[b[i].pos] = t;
	}
	sort(b + 1,b + cnt + 1,cmp2);
	for(int i = 1; i <= cnt; ++i){
		printf("%I64d\n",ta[i]);
	}
	return 0;
}
