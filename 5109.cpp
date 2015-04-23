////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-22 21:43:30
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5109
////Problem Title: 
////Run result: Accept
////Run time:687MS
////Run memory:336KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: b.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sat 22 Nov 2014 07:08:41 PM CST
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

int A,len,flag;
char s[100];
ll val[100];
ll ans,st,stval,tl;

void Solve(int p,int limit,ll t){
	if(p > limit){
		int base = 1;
		for(int i = 0; i <= limit; base *= 10,++i){
			ll tmp = 0;
			if(i != limit && val[1] == 0)
				continue;
			if(i == limit && s[1] == '0')
				continue;
			tmp = (t / base);
			tmp = tmp * st + stval;
			tmp = tmp * base + t % base;
			if(tmp % A == 0 && tmp / A < ans){
				flag = 1;
				ans = tmp / A;
			}
		}
		return;
	}
	for(int i = 0; i <= 9; ++i){
		val[p] = i;
		Solve(p + 1,limit,t * 10 + i);
	}
}

int main(){
	while(scanf("%d%s",&A,s + 1) != EOF){
		ans = 1000000000000000000LL;
		len = strlen(s + 1);
		st = 1;
		stval = 0;
		flag = 0;
		for(int i = 1; i <= len; ++i){
			stval = stval * 10 + s[i] - '0';
			st *= 10;
		}
		for(int i = 0; i <= 4; ++i){
			tl = 1;
			for(int j = 1; j <= i; ++j) tl *= 10;
			Solve(1,i,0);
			if(flag) break;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
