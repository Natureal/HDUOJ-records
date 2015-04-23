////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-05 01:02:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1695
////Problem Title: 
////Run result: Accept
////Run time:203MS
////Run memory:13932KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: hdu1695.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Thu 04 Sep 2014 08:12:03 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int RA = 100000;

int a,b,c,d,k;
int Case;
int pfac[RA + 5][30];
int num[RA + 5];
ll phi[RA + 5];
ll sum[RA + 5];

void Phi_table(){
	phi[1] = sum[1] = 1;
	for(ll i = 2; i <= RA; ++i){
		if(!phi[i]){
			for(ll j = i; j <= RA; j += i){
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
				pfac[j][num[j]++] = i;
			}
		}
		sum[i] = sum[i - 1] + phi[i];
	}
}

ll Dfs(int pos,int val,int st){
	ll res = 0;
	for(int i = pos; i < num[val]; ++i)
		res += st / pfac[val][i] - Dfs(i + 1,val,st / pfac[val][i]);
	return res;
}

int main(){
	Phi_table();
	scanf("%d",&Case);
	for(int t = 1; t <= Case; ++t){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		if(k == 0){
            printf("Case %d: 0\n",t);
            continue;
        }
		if(b > d){
			int tem = b;
			b = d;
			d = tem;
		}
		b /= k;
		d /= k;
		ll ans = sum[b];
		for(int i = b + 1; i <= d; ++i)
			ans += b - Dfs(0,i,b);
		printf("Case %d: %I64d\n",t,ans);
	}
	return 0;
}



