////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-08 15:16:05
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2492
////Problem Title: 
////Run result: Accept
////Run time:296MS
////Run memory:976KB
//////////////////System Comment End//////////////////


/*************************************************************************
    > File Name: hdu2492.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Mon 08 Sep 2014 01:21:55 PM CST
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

int T,n,a[100005];
int c[100005];
int pre[100005],suf[100005];

int Lowbit(int x){	return x & (-x);	}
void Update(int x,int d){	while(x <= 100000){ c[x] += d,x += Lowbit(x);} }
int Getsum(int x){
    int res = 0;
    while(x > 0){
        res += c[x];
        x -= Lowbit(x);
    }
    return res;
}

int main(){
    cin >> T;
	while(T--){
		cin >> n;
		memset(c,0,sizeof(c));
		for(int i = 1; i <= n; ++i){
			cin >> a[i];
			Update(a[i],1);
			pre[i] = Getsum(a[i]) - 1;
		}
		memset(c,0,sizeof(c));
		for(int i = n; i >= 1; --i){
			Update(a[i],1);
			suf[i] = Getsum(a[i]) - 1;
		}
        ll ans = 0;
		for(int i = 1; i <= n; ++i){
            //printf("pre : %d , suf : %d\n",pre[i],suf[i]);
			ans += pre[i] * (n - i - suf[i]) + (i - 1 - pre[i]) * suf[i];
		}
		cout << ans << endl;
	}
	return 0;
}

