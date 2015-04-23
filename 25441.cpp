////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-09-11 19:41:30
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:340KB
//////////////////System Comment End//////////////////

/*************************************************************************
    > File Name: 2544.cpp
    > Author: Nature
    > Mail: 564374850@qq.com
    > Created Time: Thu 11 Sep 2014 07:02:11 PM CST
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

int N,M,ans;
int u[20005],v[20005],w[20005];
int first[105],next[20005];

void Init(){
	memset(first,0,sizeof(first));
}

void Spfa(int s){
	queue<int> q; while(!q.empty()) q.pop();
	int d[105],c[105],inq[105];
	memset(d,0x3f,sizeof(d));
	memset(inq,0,sizeof(inq));
	memset(c,0,sizeof(c));
	d[s] = 0;
	inq[s] = c[s] = 1;
	q.push(s);
	while(!q.empty()){
		int x = q.front(); q.pop();
		inq[x] = 0;
		for(int y = first[x]; y; y = next[y]) if(d[v[y]] > d[x] + w[y]){
			d[v[y]] = d[x] + w[y];
			if(!inq[v[y]]){
				inq[v[y]] = 1;
				c[v[y]]++;
				if(c[v[y]] > N) return;
				q.push(v[y]);
			}
		}
	}
	printf("%d\n",d[N]);
}

int main(){
	while(scanf("%d%d",&N,&M) != EOF && (N || M)){
		Init();
		M <<= 1;
		for(int i = 1; i <= M; ++i){
			scanf("%d%d%d",&u[i],&v[i],&w[i]);
				next[i] = first[u[i]]; //编号为i的边的下一条边（若为0表示到头）
				first[u[i]] = i; //first表示节点u[i]的最后一读入条边的编号
				++i;
				u[i] = v[i - 1],v[i] = u[i - 1],w[i] = w[i - 1];
				next[i] = first[u[i]];
				first[u[i]] = i;
		}
		Spfa(1);
	}
	return 0;
}

