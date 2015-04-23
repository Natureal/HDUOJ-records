////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-13 22:04:55
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5144
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1104KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 1003.cpp
    > Author: Natureal
    > Mail: 564374850@qq.com 
    > Created Time: Sat 13 Dec 2014 08:22:34 PM CST
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
typedef unsigned long long ull;
const int INF = 1 << 30;

int T;
double H,v;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf",&H,&v);
		printf("%.2f\n",v * sqrt(v * v + 2 * 9.8 * H) / 9.8);
	}
	return 0;
}
