////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-08 00:28:56
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4990
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:276KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: b.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sun 07 Sep 2014 10:50:06 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1 << 29;

int n,m;

struct Mx{
	int a[2][2];
	void clear(){ a[0][0] = a[0][1] = a[1][0] = a[1][1] = 0;}
	void stand(){ a[0][0] = a[1][1] = 1,a[0][1] = a[1][0] = 0;}
	Mx operator * (const Mx &b) const{
		Mx c;
		c.clear();
		for(int k = 0; k < 2; ++k)
		for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j){
			c.a[i][j] = (c.a[i][j] + (ll)a[i][k] * b.a[k][j]) % m;
		}
		return c;
	}
};

ll Mx_pow(int n){
	Mx y,a;
	y.stand();
	a.a[0][0] = 4,a.a[0][1] = a.a[1][1] = 1,a.a[1][0] = 0;
	while(n){
		if(n & 1) y = y * a;
		if(n >>= 1) a = a * a;
	}
	return y.a[0][1] % m;
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		int ans = Mx_pow((n + 1) / 2);
		if((n & 1) == 0) ans *= 2;
		printf("%d\n",ans % m);
	}
	return 0;
}
