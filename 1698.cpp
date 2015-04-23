////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-26 22:42:58
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1698
////Problem Title: 
////Run result: Accept
////Run time:781MS
////Run memory:5376KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 1698.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Fri 26 Sep 2014 10:24:21 PM CST
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
#define lpos (pos << 1)
#define rpos (pos << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
typedef long long ll;
const int INF = 1 << 29;
const int maxn = 100010;

struct node{
	int l,r;
	int sum,col,flag;
}tree[maxn << 2];

int tl,tr,tv;

void Build_tree(int pos,int l,int r){
	tree[pos].l = l;
	tree[pos].r = r;
	tree[pos].sum = r - l + 1;
	tree[pos].col = 1;
	tree[pos].flag = 0;
	if(l == r)
		return;
	int mid = getmid(l,r);
	Build_tree(lpos,l,mid);
	Build_tree(rpos,mid + 1,r);
}

void Push_down(int pos){
	if(tree[pos].flag){
        int v = tree[pos].col;
		tree[lpos].col = tree[rpos].col = v;
		tree[lpos].flag = tree[rpos].flag = 1;
		tree[lpos].sum = v * (tree[lpos].r - tree[lpos].l + 1);
		tree[rpos].sum = v * (tree[rpos].r - tree[rpos].l + 1);
		tree[pos].flag = 0;
	}
}

void Update(int pos,int l,int r){
	if(tl <= l && r <= tr){
		tree[pos].col = tv;
		tree[pos].flag = 1;
		tree[pos].sum = tv * (tree[pos].r - tree[pos].l + 1);
		return;
	}
	Push_down(pos);
	int mid = getmid(l,r);
	if(tl <= mid) Update(lpos,l,mid);
	if(tr > mid) Update(rpos,mid + 1,r);
	tree[pos].sum = tree[lpos].sum + tree[rpos].sum;
}

int main(){
	int Case,N,Q;
	scanf("%d",&Case);
	for(int t = 1; t <= Case; ++t){
		scanf("%d%d",&N,&Q);
		Build_tree(1,1,N);
		while(Q--){
			scanf("%d%d%d",&tl,&tr,&tv);
			Update(1,1,N);
		}
		printf("Case %d: The total value of the hook is %d.\n",t,tree[1].sum);
	}
	return 0;
}
