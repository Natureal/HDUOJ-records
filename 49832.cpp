////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-04 14:11:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4983
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:244KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1003.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Thu 04 Sep 2014 11:40:55 AM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod = (1e9) + 7;

ll n,k;
ll ans;

ll Phi(ll v){
    ll tmp = v;
    ll m = sqrt(v + 0.5);
    for(ll i = 2; i <= m; ++i) if(v % i == 0){
        tmp = tmp / i * (i - 1);
        while(v % i == 0) v /= i;
        if(v == 1) break;
    }
    if(v != 1) tmp = tmp / v * (v - 1);
    return tmp;
}

int main(){
    while(scanf("%I64d%I64d",&n,&k) != EOF){
        if(n == 1) printf("1\n");
        else if(k > 2) printf("0\n");
        else if(k == 2) printf("1\n");
        else{
            ans = 0;
            for(ll i = 1; i * i <= n; ++i) if(n % i == 0){
                ll sum = Phi(i) * Phi(n / i);
                if(i * i != n) sum *= 2;
                ans = (ans + sum) % mod;
            }
            printf("%I64d\n",ans);
        }
    }
    return 0;
}
