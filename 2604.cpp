////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-14 23:14:53
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2604
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:252KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 5015.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 14 Sep 2014 10:31:33 PM CST
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

int L,M;

struct Mx{
	int a[4][4];
	void clear(){
		memset(a,0,sizeof(a));
	}
	void stand(){
		memset(a,0,sizeof(a));
		for(int i = 0; i < 4; ++i) a[i][i] = 1;
	}
	Mx operator * (const Mx &b){
		Mx c; c.clear();
		for(int i = 0; i < 4; ++i)
		for(int j = 0; j < 4; ++j)
		for(int k = 0; k < 4; ++k){
			c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % M;
		}
		return c;
	}
};

Mx Mx_pow(int n){
	Mx m1; m1.stand();
	Mx res; res.clear();
	res.a[0][0] = res.a[0][2] = res.a[0][3] = 1;
	res.a[1][0] = res.a[2][1] = res.a[3][2] = 1;
	while(n){
		if(n & 1) m1 = m1 * res;
		res = res * res;
		n >>= 1;
	}
	return m1;
}

int main(){
	while(scanf("%d%d",&L,&M) != EOF){
		if(L == 0) printf("0\n");
		else if(L == 1) printf("%d\n",2 % M);
		else if(L == 2) printf("%d\n",4 % M);
		else if(L == 3) printf("%d\n",6 % M);
		else if(L == 4) printf("%d\n",9 % M);
		else{
			Mx res;
			res.a[0][0] = 9;
			res.a[1][0] = 6;
			res.a[2][0] = 4;
			res.a[3][0] = 2;
			res = Mx_pow(L - 4) * res;
			printf("%d\n",res.a[0][0]);
		}
	}
	return 0;
}
