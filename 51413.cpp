////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-12 01:23:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5141
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:3112KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int n;
int v[maxn];
int Q[maxn],qcnt;
int qs[maxn],vs[maxn],len[maxn];

int main(){
	while(scanf("%d",&n) != EOF){
		for(int i = 1; i <= n; ++i)
			scanf("%d",&v[i]);
		qcnt = 0;
		memset(qs,0,sizeof(qs));
		for(int i = 1; i <= n; ++i){
			int p = lower_bound(Q + 1,Q + qcnt + 1,v[i]) - Q;
			Q[p] = v[i];
			if(p > qcnt) ++qcnt;
			if(p == 1) qs[p] = i;
			else qs[p] = max(qs[p],qs[p - 1]);
			vs[i] = qs[p];
			len[i] = p;
		}
		long long ans = 0,pos = 0;
		for(int i = 1; i <= n; ++i){
			if(len[i] == qcnt) pos = vs[i];
			ans = ans + pos;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
