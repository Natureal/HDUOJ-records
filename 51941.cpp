////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-28 23:04:02
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5194
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1616KB
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
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define MEM(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int n,m;

int Gcd(int a,int b){
	while(a > 0 && b > 0){
		if(a > b) a %= b;
		else b %= a;
	}
	return a + b;
}

int main(){
	while(scanf("%d%d",&n,&m) != EOF){
		int g = Gcd(n * m,n + m);
		printf("%d/%d\n",n * m / g,(n + m) / g);
	}
	return 0;
}
