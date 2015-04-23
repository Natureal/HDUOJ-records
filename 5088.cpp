////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-01 22:04:28
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5088
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1003.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 01 Nov 2014 09:46:10 PM CST
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

ll T,N;
ll a[1010];

bool Gauss(){
	ll i,j,row = 0;
	for(i = 0; i < 64; ++i){
		for(j = row; j < N; ++j)
			if((a[j] >> i) & 1LL) break;
		if(j < N){
			swap(a[row],a[j]);
			for(ll k = row + 1; k < N; ++k)
				if((a[k] >> i) & 1LL) a[k] ^= a[row];
			++row;
		}
	}
	for(i = 0; i < N; ++i)
		if(!a[i]) return true;
	return false;
}

int main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d",&N);
		for(ll i = 0; i < N; ++i)
			scanf("%I64d",&a[i]);
		if(Gauss()) printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
