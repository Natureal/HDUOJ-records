////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 00:42:24
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5182
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1152KB
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
#define REP(i,n) for(int i=1;i<=(n);++i)
#define REV(i,n) for(int i=(n);i>=1;--i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define getmid(l,r) ((l) + ((r) - (l)) / 2)
#define MP(a,b) make_pair(a,b)

typedef long long ll;
typedef pair<int,int> pii;
const int INF = (1 << 30) - 1;

int n;
struct node{
	int a,b,id;
}nd[105];

bool cmp(node a,node b){
	if(a.a - a.b == b.a - b.b){
		if(a.b == b.b) return a.id < b.id;
		return a.b < b.b;
	}
	return (a.a - a.b) > (b.a - b.b);
}

int main(){
	while(scanf("%d",&n) != EOF){
	REP(i,n) scanf("%d%d",&nd[i].a,&nd[i].b),nd[i].id = i;
	sort(nd + 1,nd + n + 1,cmp);
	REP(i,n){
		printf("%d%c",nd[i].id - 1,i == n ? '\n' : ' ');
	}
	}
	return 0;
}
