////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-19 22:10:47
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5020
////Problem Title: 
////Run result: Accept
////Run time:1953MS
////Run memory:15932KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 1003.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Fri 19 Sep 2014 07:53:17 PM CST
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
pair<ll,ll> no[1000005];

int T,n,cnt;
ll x[1005],y[1005];

ll Gcd(ll a,ll b){ return b == 0 ? a : Gcd(b,a % b); }

int main(){
	for(scanf("%d",&T); T; --T){
		ll ans = 0;
		scanf("%d",&n);
		for(int i = 1; i <= n; ++i)
			scanf("%I64d%I64d",&x[i],&y[i]);
		for(int i = 1; i <= n; ++i){
            cnt = 0;
            for(int j = i + 1; j <= n; ++j){
                ll ty = y[j] - y[i];
                ll tx = x[j] - x[i];
                ll G = Gcd(ty,tx);
				ty /= G; tx /= G;
				if(tx != 0 && ty != 0){
					if(tx < 0) tx = -tx,ty = -ty;
				}
				else{
					if(tx < 0) tx = -tx;
					if(ty < 0) ty = -ty;
				}
				no[cnt++] = make_pair(tx,ty);
            }
            sort(no,no + cnt);
			ll num = 0;
            for(int j = 0; j < cnt; ++j){
                if(j == 0 || no[j] == no[j - 1]) ++num;
                else{
                    if(num >= 2){
                        ans += num*(num-1);
					}
					num = 1;
                }
            }
        	if(num >= 2){
				ans += num*(num-1);
			}
		}
		ans /= 2;
		printf("%I64d\n",ans);
	}
	return 0;
}


