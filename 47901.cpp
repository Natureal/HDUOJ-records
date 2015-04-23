////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-07 13:56:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4790
////Problem Title: 
////Run result: Accept
////Run time:46MS
////Run memory:228KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 4790.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Fri 07 Nov 2014 12:03:57 AM CST
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

int T;
ll a,b,c,d,p,m;

ll Gcd(ll a,ll b){
	return b == 0 ? a : Gcd(b,a % b);
}

ll F(ll x,ll y){
	if(x < 0 || y < 0)
		return 0;
	ll nx = (x + 1) / p,tx = (x + 1) - nx * p - 1;
	ll ny = (y + 1) / p,ty = (y + 1) - ny * p - 1;
	ll res = nx * ny * p,l1,l2;
	res += (tx + 1) * ny + (ty + 1) * nx;
	//if(m == 0) m += p;
    ll ex = tx - m > 0 ? tx - m : 0,ey = ty - m > 0 ? ty - m : 0;
    tx -= ex;
    ty -= ey;
    if(tx >= 0 && ty >= 0){
        l1 = tx - (m - ty) + 1;
        l2 = ty - (m - tx) +1;
        if(l1 >= 0 && l2 >= 0){
            res += max(l1,l2);
        }
    }
    if(ex > 0 && ey > 0){
        ex += m;
        ey += m;
        l1 = ex - (p + m - ey) + 1;
        l2 = ey - (p + m - ex) + 1;
        if(l1 >= 0 && l2 >= 0){
            res += max(l1,l2);
        }
    }
	return res;
}

int main(){
	scanf("%d",&T);
	for(int Case = 1; Case <= T; ++Case){
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&p,&m);
		printf("Case #%d: ",Case);
		ll ans = F(b,d) - F(a - 1,d) - F(b,c - 1) + F(a - 1,c - 1);
		ll den = (b - a + 1) * (d - c + 1);
		ll g = Gcd(ans,den);
		printf("%I64d/%I64d\n",ans / g,den / g);
	}
	return 0;
}
