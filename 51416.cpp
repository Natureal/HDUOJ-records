////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-12-12 01:44:39
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5141
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:3068KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n,i,pos,p,l,r,mid;
int v[100001],qs[100001],vs[100001],len[100001];
int Q[100001],qcnt;

inline int Read(){
       int x = 0;char ch = getchar();
       while(ch < '0' || ch > '9')ch = getchar();
       while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
       return x;
}

int main(){
	while(scanf("%d",&n) != EOF){
		for(i = 1; i <= n; ++i)
			v[i] = Read();
		pos = qcnt = 0;
		memset(qs,-1,sizeof(qs));
		for(i = 1; i <= n; ++i){
			l = 1,r = qcnt + 1;
			while(l < r){
				mid = l + (r - l) / 2;
				if(Q[mid] >= v[i]) r = mid;
				else l = mid + 1;
			}
			p = l;
			Q[p] = v[i];
			if(p > qcnt) ++qcnt;
			if(p == 1) qs[p] = i;
			else qs[p] = max(qs[p],qs[p - 1]);
			vs[i] = qs[p];
			len[i] = p;
		}
		long long ans = 0;
		for(i = 1; i <= n; ++i){
			if(len[i] == qcnt) pos = vs[i];
			ans = ans + pos;
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
