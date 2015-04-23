////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-09 14:08:10
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4991
////Problem Title: 
////Run result: Accept
////Run time:875MS
////Run memory:8596KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: hdu4991.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Mon 08 Sep 2014 10:47:42 PM CST
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
const int maxn = 10010;
const ll mod = 123456789;

int a[maxn],b[maxn],n,m;
ll c[105][maxn];

int Lowbit(int x){
	return x & (-x);
}
void Update(int x,int d,int k){
	while(x <= maxn){
		c[k][x] = (c[k][x] + d) % mod;
		x += Lowbit(x);
	}
}
ll Getsum(int x,int k){
	ll res = 0;
	while(x){
		res = (res + c[k][x]) % mod;
		x -= Lowbit(x);
	}
	return res;
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
        memset(c,0,sizeof(c));
		for(int i = 1; i <= n; ++i){
			scanf("%d",a + i);
			b[i] = a[i];
		}
		sort(b + 1,b + n + 1);
		int size = unique(b + 1,b + n + 1) - b - 1;
		for(int i = 1; i <= n; ++i)
			a[i] = lower_bound(b + 1,b + size + 1,a[i]) - b;
		ll tmp;
		for(int i = 1; i <= n; ++i){
            Update(a[i],1,1);
			for(int j = 1; j < m; ++j){
				tmp = Getsum(a[i] - 1,j);
				if(!tmp) break;
				Update(a[i],tmp,j + 1);
			}
		}
		printf("%lld\n",Getsum(maxn,m) % mod);
	}
	return 0;
}

