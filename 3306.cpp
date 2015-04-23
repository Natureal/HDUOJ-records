////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-15 17:56:45
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3306
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:248KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 3306.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Mon 15 Sep 2014 05:20:56 PM CST
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
const ll mod = 10007;

ll N,X,Y;

struct Mx{
	ll a[4][4];
	void clear(){ memset(a,0,sizeof(a)); }
	void stand(){ memset(a,0,sizeof(a)); for(int i = 0; i < 4; ++i) a[i][i] = 1;}
	Mx operator * (const Mx &b){
		Mx c; c.clear();
		for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
		for(int k = 0; k < 4; ++k){
			c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % mod;
		}
		return c;
	}
};

Mx Mx_pow(ll num){
	Mx res; res.stand();
	Mx t; t.clear();
	t.a[0][0] = t.a[3][0] = X*X % mod;
	t.a[0][1] = t.a[3][1] = 2*X*Y % mod;
	t.a[0][2] = t.a[3][2] = Y*Y % mod;
	t.a[1][0] = X % mod;
	t.a[1][1] = Y % mod;
	t.a[2][0] = 1;
	t.a[3][3] = 1;
	while(num){
		if(num & 1) res = res * t;
		t = t * t;
		num >>= 1;
	}
	return res;
}

int main(){
	while(scanf("%I64d%I64d%I64d",&N,&X,&Y) != EOF){
        if(N == 0){
            printf("0\n");
            continue;
        }
		Mx ans; ans.clear();
		ans.a[0][0] = 1;
		ans.a[1][0] = 1;
		ans.a[2][0] = 1;
		ans.a[3][0] = 2;
		ans = Mx_pow(N - 1) * ans;
		printf("%I64d\n",ans.a[3][0]);
	}
	return 0;
}
