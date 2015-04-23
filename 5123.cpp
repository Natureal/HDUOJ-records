////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-30 00:17:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5123
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:296KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1001.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 29 Nov 2014 07:00:51 PM CST
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

int T,N;
int num[1100];

int main(){
	scanf("%d",&T);
	while(T--){
		int a;
		memset(num,0,sizeof(num));
		scanf("%d",&N);
		for(int i = 1; i <= N; ++i){
			scanf("%d",&a);
			num[a]++;
		}
		int tmax = 0;
		for(int i = 1; i <= N; ++i){
			tmax = max(tmax,num[i]);
		}
		for(int i = 1; i <= N; ++i){
			if(num[i] == tmax){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
