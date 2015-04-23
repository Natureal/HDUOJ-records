////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-26 00:38:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5036
////Problem Title: 
////Run result: Accept
////Run time:843MS
////Run memory:384KB
//////////////////System Comment End//////////////////
/*************************************************************************

    > File Name: 5036.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Thu 25 Sep 2014 11:43:25 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <bitset>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1 << 29;
const int maxn = 1010;

int T,N;
bitset<maxn> bset[maxn];

int main(){
	int k,v;
	scanf("%d",&T);
	for(int t = 1; t <= T; ++t){
		scanf("%d",&N);
		for(int i = 0; i < N; ++i){
			bset[i].reset();
			bset[i][i] = true;
			scanf("%d",&k);
			while(k--){
				scanf("%d",&v);
				bset[i][v - 1] = true;
			}
		}
		for(int j = 0; j < N; ++j){
			for(int i = 0; i < N; ++i)
				if(bset[i][j])
					bset[i] |= bset[j];
		}
		double ans = 0.0;
		for(int i = 0; i < N; ++i){
			int cnt = 0;
			for(int j = 0; j < N; ++j){
				if(bset[j][i]) ++cnt;
			}
			ans += 1.0 / cnt;
		}
		printf("Case #%d: %.5lf\n",t,ans);
	}
	return 0;
}
