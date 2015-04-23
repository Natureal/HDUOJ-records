////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-15 00:17:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5015
////Problem Title: 
////Run result: Accept
////Run time:1265MS
////Run memory:260KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 5015.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 14 Sep 2014 11:26:51 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1 << 29;
const ll mod = 10000007;

int n,m;

struct Mx{
	ll a[15][15];
	void clear(){
		memset(a,0,sizeof(a));
	}
	void stand(){
		memset(a,0,sizeof(a));
		for(int i = 0; i <= n + 1; ++i)
			a[i][i] = 1;
	}
	Mx operator * (const Mx &b){
		Mx c; c.clear();
		for(int i = 0; i <= n + 1; ++i)
		for(int j = 0; j <= n + 1; ++j)
		for(int k = 0; k <= n + 1; ++k){
			c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
		}
		return c;
	}
};

Mx Mx_pow(int v){
	Mx res; res.stand();
	Mx t; t.clear();
	t.a[0][0] = 10; t.a[0][n + 1] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j <= i; ++j){
			t.a[i][j] = 1;
		}
	}
	t.a[n + 1][n + 1] = 1;
	while(v){
		if(v & 1){
			res = res * t;
		}
		t = t * t;
		v >>= 1;
	}
	return res;
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		Mx res; res.clear();
		res.a[0][0] = 233;
		for(int i = 1; i <= n; ++i){
			scanf("%I64d",&res.a[i][0]);
		}
		res.a[n + 1][0] = 3;
		res = Mx_pow(m) * res;
		printf("%I64d\n",res.a[n][0] % mod);
	}
	return 0;
}

