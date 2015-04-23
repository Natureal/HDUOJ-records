////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-12 21:52:45
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1166
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:828KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: hdu1166.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Fri 12 Sep 2014 09:09:57 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int INF = 1 << 29;
const int maxn = 50000;

int T,n,a[maxn + 10],sum[maxn * 4 + 10];
int ql,qr,p,v;

void Build_tree(int pos,int l,int r){
	if(l == r)
		scanf("%d",&sum[pos]);
	else{
		int mid = l + (r - l) / 2;
		Build_tree(pos << 1,l,mid);
		Build_tree(pos << 1 | 1,mid + 1,r);
		sum[pos] = sum[pos << 1] + sum[pos << 1 | 1];
	}
}

void Update(int pos,int l,int r){
	if(l == r)
		sum[pos] += v;
	else{
		int mid = l + (r - l) / 2;
		if(p <= mid) Update(pos << 1,l,mid);
		else Update(pos << 1 | 1,mid + 1,r);
		sum[pos] = sum[pos << 1] + sum[pos << 1 | 1];
	}
}

int Query(int pos,int l,int r){
	if(ql <= l && r <= qr)
		return sum[pos];
	int mid = l + (r - l) / 2;
	int res = 0;
	if(ql <= mid) res += Query(pos << 1,l,mid);
	if(qr > mid) res += Query(pos << 1 | 1,mid + 1,r);
	return res;
}


int main(){
	char s[20];
	scanf("%d",&T);
	for(int t = 1; t <= T; ++t){
		scanf("%d",&n);
		Build_tree(1,1,n);
		printf("Case %d:\n",t);
		while(scanf("%s",s) != EOF){
			if(s[0] == 'E') break;
			else if(s[0] == 'Q'){
				scanf("%d%d",&ql,&qr);
				printf("%d\n",Query(1,1,n));
			}
			else if(s[0] == 'A'){
				scanf("%d%d",&p,&v);
				Update(1,1,n);
			}
			else if(s[0] == 'S'){
				scanf("%d%d",&p,&v);
				v = -v;
				Update(1,1,n);
			}
		}
	}
	return 0;
}
				
