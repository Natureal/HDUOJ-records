////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2015-03-08 13:51:29
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 5183
////Problem Title: 
////Run result: Accept
////Run time:1326MS
////Run memory:60680KB
//////////////////System Comment End//////////////////
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

int T,n,K;
long long sum[1000010];
set<long long> st;
int A[1000010];

inline int Read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
	return x * f;
}

int main(){
	T = Read();
	for(int tt = 1; tt <= T; ++tt){	
		st.clear();
		n = Read();
		K = Read();
		for(int i = 1; i <= n; ++i) A[i] = Read();
		bool flag = false;
		for(int i = 1; i <= n; ++i){
			if(i & 1)	sum[i] = sum[i - 1] + A[i];
			else	sum[i] = sum[i - 1] - A[i];
		}
		for(int i = n; i >= 1; --i){
			st.insert(sum[i]);
			long long cur = (i & 1) ? sum[i - 1] + K : sum[i - 1] - K;
			if(st.count(cur)){
				flag = true;
				break;
			}
		}
		if(flag) printf("Case #%d: Yes.\n",tt);
		else printf("Case #%d: No.\n",tt);
	}
	return 0;
}
