////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-01 15:23:29
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2769
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 12169.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sun 31 Aug 2014 10:34:46 AM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
const int mod = 10001;

int t,v[205];

bool Judge(int a,int b){
    int top = t << 1;
    for(int i = 2; i <= top; ++i){
        if(i & 1){
            if(v[i] != (a * v[i - 1] % mod + b) % mod){
                return false;
            }
        }
        else{
            v[i] = (a * v[i - 1] % mod + b) % mod;
        }
    }
    return true;
}

void Print(){
    int top = t << 1;
    for(int i = 2; i <= top; i += 2)
        printf("%d\n",v[i]);
}

void Ex_gcd(int a,int b,int &d,int &x,int &y){
    if(!b) d = a,x = 1,y = 0;
    else Ex_gcd(b,a % b,d,y,x),y -= a / b * x;
}

int main(){
    scanf("%d",&t);
    for(int i = 1; i <= t; ++i)
        scanf("%d",&v[(i << 1) - 1]);
    int a,b,c,x,y,d;
    for(a = 0; a <= 10000; ++a){
        Ex_gcd(a + 1,-mod,d,b,y);
        c = (mod + v[3] - (a * a % mod) * v[1] % mod) % mod;
        if(c % d) continue; //非整除 无解。
        b *= c / d;
        int k = abs(-mod / d);
        b = (b % k + k) % k;
        if(Judge(a,b))  break;
    }
    Print();
    return 0;
}