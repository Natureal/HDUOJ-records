////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-12 22:38:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1754
////Problem Title: 
////Run result: Accept
////Run time:1078MS
////Run memory:2372KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: hdu1754.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Fri 12 Sep 2014 10:24:14 PM CST
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
const int maxn = 200000;

int n,m,s[maxn + 10];
int arr[maxn * 4 + 10],ql,qr,p,v;

void Build(int pos,int l,int r){
	if(l == r)
		scanf("%d",&arr[pos]);
	else{
		int mid = l + (r - l) / 2;
		Build(pos << 1,l,mid);
		Build(pos << 1 | 1,mid + 1,r);
		arr[pos] = max(arr[pos << 1],arr[pos << 1 | 1]);
	}
}
void Update(int pos,int l,int r){
	if(l == r)
		arr[pos] = v;
	else{
		int mid = l + (r - l) / 2;
		if(p <= mid) Update(pos << 1,l,mid);
		else Update(pos << 1 | 1,mid + 1,r);
		arr[pos] = max(arr[pos << 1],arr[pos << 1 | 1]);
	}
}
int Query(int pos,int l,int r){
	if(ql <= l && r <= qr)
		return arr[pos];
	int mid = l + (r - l) / 2,res = -1;
	if(ql <= mid) res = max(res,Query(pos << 1,l,mid));
	if(qr > mid) res = max(res,Query(pos << 1 | 1,mid + 1,r));
	return res;
}

int main(){
	int a,b;
	char s[5];
	while(scanf("%d%d",&n,&m) != EOF){
		Build(1,1,n);
		while(m--){
			scanf("%s%d%d",s,&a,&b);
			if(s[0] == 'Q'){
				ql = a,qr = b;
				printf("%d\n",Query(1,1,n));
			}
			else{
				p = a,v = b;
				Update(1,1,n);
			}
		}
	}
	return 0;
}

