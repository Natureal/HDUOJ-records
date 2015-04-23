////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-05 17:01:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4135
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:296KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 4135.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Fri 05 Sep 2014 04:25:16 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int T;
ll pfac[105];
int num;
ll A,B,N;
ll ans;

ll Dfs(int pos,ll st){
	ll res = 0;
	for(int i = pos; i < num; ++i)
		res += st/pfac[i] - Dfs(i + 1,st/pfac[i]);
	return res;
}

int main(){
	scanf("%d",&T);
	for(int t = 1; t <= T; ++t){
		scanf("%I64d %I64d %I64d",&A,&B,&N);
		num = 0;
		ll m = sqrt(1.0 * N) + 2;
		for(ll i = 2; i <= m; ++i) if(N % i == 0){
			pfac[num++] = i;
			while(N % i == 0) N /= i;
		}
		if(N != 1) pfac[num++] = N;
		//Dfs(0,B);
		//printf("%lld %lld\n",Dfs(0,A - 1),Dfs(0,B));
		ans = B - Dfs(0,B) - (A - 1 - Dfs(0,A - 1));
		printf("Case #%d: %I64d\n",t,ans);
	}
	return 0;
}
