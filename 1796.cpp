////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-04 22:28:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1796
////Problem Title: 
////Run result: Accept
////Run time:390MS
////Run memory:228KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: hdu1796.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Thu 04 Sep 2014 09:53:53 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int Gcd(int a,int b) { return b == 0 ? a : Gcd(b,a % b); }
int Lcm(int a,int b) { return a / Gcd(a,b) * b; }

int n,m;
int v[15];
int ans;

void Dfs(int p,int cnt,int l,int tar){
	if(p > m){
		//printf("l : %d,tar : %d\n",l,tar);
		if(cnt == tar){
			int tmp = (n - 1) / l;
			ans += (tar & 1) ? tmp : -tmp;
		}
		return;
	}
	if(m - p + 1 + cnt < tar)
		return;
	Dfs(p + 1,cnt,l,tar);
	int tl = Lcm(l,v[p]);
	if(tl < n && cnt < tar)
		Dfs(p + 1,cnt + 1,tl,tar);
}

int main(){
	while(scanf("%d %d",&n,&m) != EOF){
		for(int i = 1; i <= m; ++i){
			scanf("%d",&v[i]);
			if(!v[i]) --i,--m;
		}
		ans = 0;
		for(int i = 1; i <= m; ++i)
			Dfs(1,0,1,i);
		printf("%d\n",ans);
	}
	return 0;
}

