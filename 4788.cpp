////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: suda1327405059
////Nickname: Algodevil
////Run ID: 
////Submit time: 2014-11-06 20:00:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 4788
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
/*************************************************************************
    > File Name: 4788.cpp
    > Author: Nature
    > Mail: 564374850@qq.com 
    > Created Time: Thu 06 Nov 2014 07:32:56 PM CST
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

int T;
char s[20];
char st[20][20] = {"B","KB","MB","GB","TB","PB","EB","ZB","YB"};
double fac[20];

void Pre(){
	double v = 1000.0 / 1024.0;
	fac[0] = 1.0;
	for(int i = 1; i <= 10; ++i){
		fac[i] = fac[i - 1] * v;
	}
}

int main(){
	char c;
	Pre();
	scanf("%d",&T);
	getchar();
	for(int i = 1; i <= T; ++i){
		c = getchar();
		while(c >= '0' && c <= '9')
			c = getchar();
		scanf("%s",s);
		getchar();
		s[strlen(s) - 1] = '\0';
		for(int j = 0; j < 10; ++j){
			if(strcmp(s,st[j]) == 0){
				printf("Case #%d: %.2f%%\n",i,100.0 * (1.0 - fac[j]));
				break;
			}
		}
	}
	return 0;
}
