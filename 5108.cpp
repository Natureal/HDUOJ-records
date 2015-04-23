////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-22 21:10:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5108
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:340KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: a.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 22 Nov 2014 06:59:30 PM CST
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

int n;

int main(){
	while(scanf("%d",&n) != EOF){
		if(n == 1){
			printf("0\n");
			continue;
		}
		int m = n;
		int k = sqrt(1.0 * n);
		int ans = 0;
		for(int i = 2; i <= k; ++i) if(n % i == 0){
			while(n % i == 0){
				n /= i;
			}
			ans = max(ans,i);
		}
		ans = max(ans,n);
		printf("%d\n",m / ans);
	}
	return 0;
}

 
