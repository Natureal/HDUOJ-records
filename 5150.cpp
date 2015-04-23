////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-27 21:36:18
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5150
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1156KB
//////////////////System Comment End//////////////////
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

int N;
int sum,v;
int p[1010];

void Pre(){
	memset(p,0,sizeof(p));
	for(int i = 2; i <= 1000; ++i){
		for(int j = i + i; j <= 1000; j += i){
			p[j] = 1;
		}
	}
}

int main(){
	Pre();
	while(scanf("%d",&N) != EOF){
		sum = 0;
		for(int i = 1; i <= N; ++i){
			scanf("%d",&v);
			if(p[v] == 0) sum += v;
		}
		printf("%d\n",sum);
	}
	return 0;
}
