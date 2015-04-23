////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-27 18:39:21
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5051
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 5051.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 27 Sep 2014 05:27:54 PM CST
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
#define lpos (pos << 1)
#define rpos (pos << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
typedef long long ll;
const int INF = 1 << 29;

int T;
int n,b,q;

int main(){
	scanf("%d",&T);
	for(int t = 1; t <= T; ++t){
		scanf("%d%d%d",&n,&b,&q);
		printf("Case #%d: ",t);
		int tq = q;
		while(tq % 10 == 0) tq /= 10;
		if(tq == 1){
			if(q != 1) while(b < n) b *= 10;
			while(b > n) b /= 10;
			if(n == b) printf("1.00000\n");
			else printf("0.00000\n");
		}
		else{
			printf("%.5f\n",log10(1.0 + 1.0 / n));
		}
	}
	return 0;
}