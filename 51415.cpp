////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-12 01:31:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5141
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:3060KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n,i,pos,p;
int v[100001],qs[100001],vs[100001],len[100001];
int Q[100001],qcnt;

inline int Read(){
       int x = 0;char ch = getchar();
       while(ch < '0' || ch > '9')ch = getchar();
       while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
       return x;
}

void Write(long long v){
       if(v>9) Write(v/10);
       putchar(v%10+'0');
}

int main(){
	while(scanf("%d",&n) != EOF){
		for(i = 1; i <= n; ++i)
			v[i] = Read();
		qcnt = 0;
		memset(qs,-1,sizeof(qs));
		for(i = 1; i <= n; ++i){
			p = lower_bound(Q + 1,Q + qcnt + 1,v[i]) - Q;
			Q[p] = v[i];
			if(p > qcnt) ++qcnt;
			if(p == 1) qs[p] = i;
			else qs[p] = max(qs[p],qs[p - 1]);
			vs[i] = qs[p];
			len[i] = p;
		}
		long long ans = 0;
		pos = 0;
		for(i = 1; i <= n; ++i){
			if(len[i] == qcnt) pos = vs[i];
			ans = ans + pos;
		}
		Write(ans);
		puts("");
	}
	return 0;
}
