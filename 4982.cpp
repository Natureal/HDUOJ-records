////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-08-24 21:15:01
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4982
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:328KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 1002.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Sun 24 Aug 2014 07:05:49 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int vis[200005];
int sq[450];
int cnt;
int n,k;

void Init(){
	cnt = 0;
	for(int i = 1; i <= 450; ++i){
		if(i * i > 200000) break;
			sq[++cnt] = i * i;
	}
}

int main(){
	Init();
	int tsum;
	while(scanf("%d%d",&n,&k) == 2){
		tsum = k * (k + 1) / 2;
		if(tsum > n){
			printf("NO\n");
			continue;
		}
		tsum -= k; // sum (1....k - 1)
		int top = n - tsum;
		int L = n - top;
		int tag = -1;
		if(top - 2 == k - 1){
            tag = n - k;
		}
		int R = n - 1;
		int flag = 0;
		for(int i = 1; i <= 450; ++i){
			if(L <= sq[i] && sq[i] <= R && sq[i] != tag){
				flag = 1;
				break;
			}
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");

	}
	return 0;
}
