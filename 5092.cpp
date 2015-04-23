////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-02 17:38:41
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5092
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: c.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sun 02 Nov 2014 01:12:59 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
const int INF = 1 << 30;

int T,n,m;
int g[105][105];
int next[105][105];

int main(){
	scanf("%d",&T);
	for(int Case = 1; Case <= T; ++Case){
		scanf("%d%d",&m,&n);
		for(int i = 1; i <= m; ++i)
			for(int j = 1; j <= n; ++j)
				scanf("%d",&g[i][j]);
		for(int i = m - 1; i >= 1; --i){
			for(int j = 1; j <= n; ++j){
				if(j < n && g[i+1][j+1] <= g[i+1][j] && (j==1 || g[i+1][j+1] <= g[i+1][j-1])){
					g[i][j] += g[i+1][j+1];
					next[i][j] = j+1;
				}
				else if((j==n || g[i+1][j] <= g[i+1][j+1]) && (j==1 || g[i+1][j] <= g[i+1][j-1])){
					g[i][j] += g[i+1][j];
					next[i][j] = j;
				}
				else{
					g[i][j] += g[i+1][j-1];
					next[i][j] = j - 1;
				}
			}
		}
		printf("Case %d\n",Case);
		int tmin = INF;
		for(int i = 1; i <= n; ++i) tmin = min(tmin,g[1][i]);
		for(int i = n; i >= 1; --i) if(g[1][i] == tmin){
			printf("%d",i);
			int row = 2,col = next[1][i];
			while(row <= m){
				printf(" %d",col);
				col = next[row][col];
				++row;
			}
			puts("");
			break;
		}
	}
	return 0;
}
