////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-10-04 16:41:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5057
////Problem Title: 
////Run result: Accept
////Run time:2234MS
////Run memory:30004KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 5057.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Sat 04 Oct 2014 03:11:35 PM CST
************************************************************************/

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
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
const int maxn = 100010;
const int mod = 1 << 15;

int T,N,M;
int A[maxn];
char c[maxn][10][10];
unsigned short re[maxn][10][10];

int Lowbit(int x){
	return x & (-x);
}

void Update(int x,int d,int p,int v){
	int tmp;
	while(x <= N){
		tmp = re[x][d][p] + v;
		c[x][d][p] += tmp / mod;
		re[x][d][p] = tmp % mod;
		x += Lowbit(x);
	}
}

int Getsum(int x,int d,int p){
	int res = 0;
	while(x){
		res += c[x][d][p] * mod + re[x][d][p];
		x -= Lowbit(x);
	}
	return res;
}

int main(){
	char s[5];
	int tem,l,r,d,p,x,y;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&N,&M);
		memset(c,0,sizeof(c));
		memset(re,0,sizeof(re));
		for(int i = 1; i <= N; ++i){
			scanf("%d",A + i);
			tem = A[i];
			for(int j = 0; j < 10; ++j){
				Update(i,j,tem % 10,1);
				tem /= 10;
			}
		}
		for(int i = 1; i <= M; ++i){
			scanf("%s",s);
			if(s[0] == 'S'){
				scanf("%d%d",&x,&y);
				tem = A[x];
				for(int j = 0; j < 10; ++j){
					Update(x,j,tem % 10,-1);
					tem /= 10;
				}
				A[x] = y;
				for(int j = 0; j < 10; ++j){
					Update(x,j,y % 10,1);
					y /= 10;
				}
			}
			else{
				scanf("%d%d%d%d",&l,&r,&d,&p);
				printf("%d\n",Getsum(r,d - 1,p) - Getsum(l - 1,d - 1,p));
			}
		}
	}
	return 0;
}

		





